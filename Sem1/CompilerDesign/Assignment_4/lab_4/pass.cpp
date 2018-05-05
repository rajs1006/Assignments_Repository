/* Sovit Kumar Agarwal 397315 , Ahmad Jibran 396610 , Rajeev Kumar 396932 */

// Enable assertions
#undef NDEBUG

#define LLVM_VERSION_NUM \
  (LLVM_VERSION_MAJOR * 10000 + LLVM_VERSION_MINOR * 100 + LLVM_VERSION_PATCH)

#include <llvm/Pass.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/InstVisitor.h>
#include <llvm/IR/CFG.h>
#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Constants.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/SetVector.h>
#include <llvm/ADT/DenseSet.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

namespace {

class MipsEmitPass : public ModulePass {
public:
  static char ID;
  MipsEmitPass() : ModulePass(ID) {}

  virtual void getAnalysisUsage(AnalysisUsage &au) const {
    au.setPreservesAll();
  }

  virtual bool runOnModule(Module &M) {
#if LLVM_VERSION_NUM >= 30700
    DL = &M.getDataLayout();
#else
    DL = M.getDataLayout();
#endif

    // Emit globals in data section
    // This only handled character string constants
    errs() << ".data\n";
    for (GlobalVariable &GV : M.globals()) {
      errs() << GV.getName() << ":";
      Constant *C = GV.getInitializer();
      if (auto *CDA = dyn_cast<ConstantDataArray>(C)) {
        errs() << " .asciiz \"" << CDA->getAsCString() << "\"";
      }
      errs() << "\n";
    }

    // Emit code in text section
    errs() << "\n.text\n";
    for (Function &F : M) {
      if (F.isDeclaration()) {
        // This is an external declaration, will be linked in
        continue;
      }

      handleFunction(F);
      errs() << "\n";
    }
    return false;
  }


  void handleFunction(Function &F) {
    // Reset state
    UsedRegs = 0;
    BlockNames.clear();
    Regs.clear();
    HandledInstrs.clear();

    // Assign unique names to all basic blocks
    std::string FuncName = F.getName();
    unsigned BlockId = 0;
    for (BasicBlock &BB : F) {
      BlockNames[&BB] = FuncName + "_" + std::to_string(BlockId);
      BlockId++;
    }

    errs() << FuncName << ":\n";
    for (BasicBlock &BB : F) {
      handleBasicBlock(BB);
    }
  }

  void handleBasicBlock(BasicBlock &BB) {
    CurrentBB = &BB;
    errs() << BlockNames[&BB] << ":\n";
    for (Instruction &I : BB) {
      // In some cases we may want to handle multiple instructions at once,
      // in which case we don't want them to be emitted again!
      if (HandledInstrs.find(&I) != HandledInstrs.end()) {
        continue;
      }

      HandledInstrs.insert(&I);
      handleInstruction(I);
    }
  }

  void handleInstruction(Instruction &I) {
    if (ReturnInst *Ret = dyn_cast<ReturnInst>(&I)) {
      const Function *F = CurrentBB->getParent();
      if (F->getName() == "main") {
        // Call exit syscall
        loadValue("$a0", Ret->getOperand(0));
        emitInstr("addi", "$v0", "$zero", INT64_C(17));
        emitInstr("syscall");
      } else {
        // $v0 is the return value register
        loadValue("$v0", Ret->getOperand(0));
        emitInstr("jr", "$ra");
      }
    } else if (CallInst *Call = dyn_cast<CallInst>(&I)) {
      // Normally, calls would have to back up used $tN registers
      // (and other caller-save registers) onto the stack. We ignore
      // this and other calling convention requirements here. The
      // examples are laid out so that it should not be necessary.

      // Arguments are stored in $a0-$a3
      int i = 0;
      for (Value *Arg : Call->arg_operands()) {
        loadValue("$a" + std::to_string(i), Arg);
      }

      emitInstr("jal", Call->getCalledFunction()->getName());

      // The return value is in $v0
      if (Call->getNumUses() != 0) {
        emitInstr("move", getOutReg(Call), "$v0");
      }
    } else if (GetElementPtrInst *GEP = dyn_cast<GetElementPtrInst>(&I)) {
      // In the general case, GEP requires a series of multiplies and
      // adds. However, here we only handle the case where it reduces
      // to an addition of a constant offset.
      Value *Ptr = GEP->getPointerOperand();
      std::string PtrReg = getInReg(Ptr);
      std::string ResReg = getOutReg(GEP);
      APInt APOffset(DL->getPointerTypeSizeInBits(GEP->getType()), 0);
      if (GEP->accumulateConstantOffset(*DL, APOffset) && APOffset.isSignedIntN(16)) {
        emitInstr("addi", ResReg, PtrReg, APOffset.getSExtValue());
      } else {
        // Too complicated, don't bother
        emitUnimplemented();
      }
    } else if (BinaryOperator *BinOp = dyn_cast<BinaryOperator>(&I)) {

	  Value *Op1 = BinOp->getOperand(0);
      Value *Op2 = BinOp->getOperand(1);

      std::string Op1Reg = getInReg(Op1);
      std::string ResReg = getOutReg(BinOp);

      switch (BinOp->getOpcode()) {
        case BinaryOperator::Add:

	      if (isSignedImm(Op2)) {
              emitInstr("addiu", ResReg, Op1Reg, getSignedImm(Op2));
            } else {
              emitInstr("addu", ResReg, Op1Reg, getInReg(Op2));
            }
          break;

		case BinaryOperator::Sub:

           if (isSignedImm(Op2)) {
              emitInstr("subu", ResReg, Op1Reg, getSignedImm(Op2));
            } else {
            emitInstr("sub", ResReg, Op1Reg, getInReg(Op2));
            }
           break;

		case BinaryOperator::Mul:

		  emitInstr("mult", Op1Reg, getInReg(Op2));
   		  emitInstr("mfhi", ResReg);
          emitInstr("mflo", ResReg);
          break;

		case BinaryOperator::SDiv:

		  emitInstr("div", Op1Reg, getInReg(Op2));
          emitInstr("mflo", ResReg);
          break;

		case BinaryOperator::SRem:
          emitInstr("div", Op1Reg, getInReg(Op2));
          emitInstr("mfhi", ResReg);
          break;

	    case BinaryOperator::UDiv:
          emitInstr("divu", Op1Reg, getInReg(Op2));
          emitInstr("mflo", ResReg);
          break;

		case BinaryOperator::URem:
          emitInstr("divu", Op1Reg, getInReg(Op2));
          emitInstr("mfhi", ResReg);
          break;

		case BinaryOperator::And:
          if (isUnsignedImm(Op2)) {
            emitInstr("andi", ResReg, Op1Reg, getUnsignedImm(Op2));
          } else {
            emitInstr("and", ResReg, Op1Reg, getInReg(Op2));
          }
          break;

		case BinaryOperator::Or:
          if (isUnsignedImm(Op2)) {
            emitInstr("ori", ResReg, Op1Reg, getUnsignedImm(Op2));
          } else {
            emitInstr("or", ResReg, Op1Reg, getInReg(Op2));
          }
          break;

		case BinaryOperator::Xor:
          if (isUnsignedImm(Op2)) {
            emitInstr("xori", ResReg, Op1Reg, getUnsignedImm(Op2));
          } else {
            emitInstr("xor", ResReg, Op1Reg, getInReg(Op2));
          }
          break;

		case BinaryOperator::Shl:
          if (isUnsignedImm(Op2)) {
            emitInstr("sll", ResReg, Op1Reg, getUnsignedImm(Op2));
          } else {
            emitInstr("sllv", ResReg, Op1Reg, getInReg(Op2));
          }
          break;

		case BinaryOperator::LShr:
		  if (isUnsignedImm(Op2)) {
            emitInstr("srl", ResReg, Op1Reg, getUnsignedImm(Op2));
          } else {
            emitInstr("srlv", ResReg, Op1Reg, getInReg(Op2));
          }
          break;

		case BinaryOperator::AShr:
          if (isUnsignedImm(Op2)) {
            emitInstr("sra", ResReg, Op1Reg, getUnsignedImm(Op2));
          } else {
            emitInstr("srav", ResReg, Op1Reg, getInReg(Op2));
          }
          break;

		default:
          // Other binary operators that we don't handle
          emitUnimplemented();
          break;
      }
    } else if (BranchInst *Br = dyn_cast<BranchInst>(&I)) {

	    HandledInstrs.insert(&I);
        if(Br->isUnconditional()){
      	BasicBlock *SuccBB = Br->getSuccessor(0);
      	PhiValues.clear();
      	PhiNodes.clear();
		 for (Instruction &SuccI : *SuccBB){
			if (isa<PHINode>(&SuccI)){
				PHINode *phiNode = dyn_cast<PHINode>(&SuccI);
				Value *inVal = phiNode->getIncomingValueForBlock(Br->getParent());
				PhiNodes.insert(phiNode);
				PhiValues.push_back(std::make_pair(phiNode, inVal));
			}
		 }

		 for (DenseSet<PHINode*>::iterator it=PhiNodes.begin(); it!=PhiNodes.end(); ++it) {
			 Value *inVal = (*it)->getIncomingValueForBlock(Br->getParent());
			 for (SmallVector<std::pair<PHINode*, Value*>, 8>::iterator jt=PhiValues.begin(); jt!=PhiValues.end(); ++jt) {
				 if(jt->second == *it){
					 loadValue(getInstrReg(jt->first), jt->second);
					 PhiNodes.erase(jt->first);
				 }
			 }
			 loadValue(getInstrReg(*it), inVal);
		 }


  		emitInstr("j", BlockNames[SuccBB]);
	  }
    } else if (ICmpInst *Cmp = dyn_cast<ICmpInst>(&I)) {
      BranchInst *Br = getOnlyUser<BranchInst>(Cmp);
      HandledInstrs.insert(&I);

      Value *Op1 = Cmp->getOperand(0);
      Value *Op2 = Cmp->getOperand(1);
      std::string Op1Reg = getInReg(Op1);
      std::string Op2Reg = getInReg(Op2);

      if(Br->isConditional() ){
      	BasicBlock *succ = Br->getSuccessor(0);
      	ICmpInst::Predicate pred= Cmp->getPredicate();
      	switch (pred) {
      		case ICmpInst::ICMP_EQ:
   				emitInstr("beq", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
        	case ICmpInst::ICMP_NE:
				emitInstr("bne", Op1Reg, Op2Reg, BlockNames[succ]);
      			break;
	        case ICmpInst::ICMP_SGT:
	   			emitInstr("bgt", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_SGE:
	   			emitInstr("bge", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_SLT: 
	   			emitInstr("blt", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_SLE: 
	   			emitInstr("ble", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_UGT:
	   			emitInstr("bgtu", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_UGE:
	   			emitInstr("bgeu", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_ULT: 
	   			emitInstr("bltu", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
	        case ICmpInst::ICMP_ULE:
	   			emitInstr("bleu", Op1Reg, Op2Reg, BlockNames[succ]);
    			break;
        	default:
          		llvm_unreachable("Invalid ICmp predicate!");
      	}
      	emitInstr("j", BlockNames[Br->getSuccessor(1)]);
	  }
    } else if (LoadInst *Load = dyn_cast<LoadInst>(&I)) {
      Value *Op1 = Load->getPointerOperand();
      std::string Op1Reg = getInReg(Op1);
      std::string ResReg = getOutReg(Load);
      unsigned bitSize = Load->getType()->getPrimitiveSizeInBits();

      Instruction *Inst = getOnlyUser<Instruction>(Load);
      std::string ResInst = getOutReg(Inst);
      HandledInstrs.insert(Inst);

      std::string Op1RegLoad = std::to_string(0) + "("+Op1Reg+")" ;

      if(bitSize == 8){
		  if(isa<SExtInst>(Inst)){
			  emitInstr("lb", ResInst, Op1RegLoad );
		  }else if(isa<ZExtInst>(Inst)){
			  emitInstr("lbu", ResInst, Op1RegLoad);
		  }
	  }else if(bitSize == 16){
		  if(isa<SExtInst>(Inst)){
			  emitInstr("lh", ResInst, Op1RegLoad);
		  }else if(isa<ZExtInst>(Inst)){
			  emitInstr("lhu", ResInst, Op1RegLoad);
		  }
	  }
    } else if (isa<PHINode>(&I)) {
		// TODO
      // Hint: You will probably want to handle Phi nodes as part
      // of branch instructions, and leave this condition empty.
      // Useful functions: Phi->getIncomingValueForBlock(BB)

    } else {
      emitUnimplemented();
    }
  }

private:
  // HELPERS
  //
  // In the following a number of helper functions are defined,
  // which will hopefully make your implementation simpler. Please
  // check which functions are available before starting the
  // assignment.

  // Emit zero-operand instruction
  void emitInstr(const char *Instr) {
    errs() << "  " << Instr << "\n";
  }

  // Emit one-operand instruction
  void emitInstr(const char *Instr, const std::string &Op1) {
    errs() << "  " << Instr << " " << Op1 << "\n";
  }

  // Emit two-operand instruction
  void emitInstr(const char *Instr, const std::string &Op1, const std::string &Op2) {
    errs() << "  " << Instr << " " << Op1 << ", " << Op2 << "\n";
  }

  // Emit three-operand instruction
  void emitInstr(const char *Instr, const std::string &Op1,
                 const std::string &Op2, const std::string &Op3) {
    errs() << "  " << Instr << " " << Op1 << ", " << Op2 << ", " << Op3 << "\n";
  }

  // Emit three-operand signed immediate instruction
  void emitInstr(const char *Instr, const std::string &Op1,
                 const std::string &Op2, int64_t Imm) {
    errs() << "  " << Instr << " " << Op1 << ", " << Op2 << ", " << Imm << "\n";
  }

  // Emit three-operand unsigned immediate instruction
  void emitInstr(const char *Instr, const std::string &Op1,
                 const std::string &Op2, uint64_t Imm) {
    errs() << "  " << Instr << " " << Op1 << ", " << Op2 << ", " << Imm << "\n";
  }

  // Emit memory instruction
  void emitMemInstr(const char *Instr, const std::string &Op,
                    const std::string &AddrOp, int16_t Offset) {
    errs() << "  " << Instr << " " << Op << ", " << Offset << "(" << AddrOp << ")\n";
  }

  // Emit a marker for unimplemented functionality
  void emitUnimplemented() {
    errs() << "  UNIMPLEMENTED\n";
  }

  // Check whether the value is representable as a signed N-bit immediate
  bool isSignedImm(Value *Op, unsigned N = 16) {
    if (ConstantInt *C = dyn_cast<ConstantInt>(Op)) {
      if (C->getValue().isSignedIntN(N)) {
        return true;
      }
    }
    return false;
  }

  // Check whether the value is representable as an unsigned N-bit immediate
  bool isUnsignedImm(Value *Op, unsigned N = 16) {
    if (ConstantInt *C = dyn_cast<ConstantInt>(Op)) {
      if (C->getValue().isIntN(N)) {
        return true;
      }
    }
    return false;
  }

  // Retrieve value as signed immediate
  int64_t getSignedImm(Value *Op) {
    return dyn_cast<ConstantInt>(Op)->getSExtValue();
  }

  // Retrieve value as unsigned immidiate
  uint64_t getUnsignedImm(Value *Op) {
    return dyn_cast<ConstantInt>(Op)->getZExtValue();
  }

  // Check if instruction has single user of type T, and return that user.
  // Example: if (SExtInst *SExt = getOnlyUser<SExtInstr>(Load)) { ... }
  template<class T>
  T *getOnlyUser(Value *Op) {
    if (!Op->hasOneUse()) {
      return nullptr;
    }

    Value *User = *Op->user_begin();
    return dyn_cast<T>(User);
  }

  // REGISTER ALLOCATION
  //
  // To keep this assignment reasonably simple, we use a very simple
  // register allocator, which simply assigns a new register to each
  // instruction, without reuse. This is a *very* bad use of registers,
  // but it is sufficient for the small code samples we are using.
  //
  // Additionally, we are neglecting a lot of issues relating to
  // function calls. We don't back up any registers on the stack during
  // a function call and generally don't care about called functions
  // corrupting our register state. Once again, this only works because
  // the sample codes only use functions in a way where this does not
  // matter.
  //
  // getOutReg() provides a register for an instruction result,
  // getInReg() for an instruction (input) operand. loadValue() can be
  // used if a value needs to be loaded into a specific register.

  // Get output register for an instruction
  std::string getOutReg(Instruction *I) {
    return getInstrReg(I);
  }

  // Get input register for a value (instruction, constant, global, etc.)
  std::string getInReg(Value *Val) {
    return loadValue("", Val);
  }

  // Load value into a register and return the register.
  // If RegHint is not empty, the value will be loaded into RegHint,
  // performing a register move should it be necessary.
  std::string loadValue(const std::string &RegHint, Value *Val) {
    std::string Reg;
    if (Argument *Arg = dyn_cast<Argument>(Val)) {
      // Arguments are in $a0-$a3.
      // This is generally unsafe, as $aN might have been overwritten in
      // the meantime. The examples are chosen so this is not an issue.
      Reg = "$a" + std::to_string(Arg->getArgNo());
    } else if (GlobalVariable *GV = dyn_cast<GlobalVariable>(Val)) {
      // Load address of global
      Reg = !RegHint.empty() ? RegHint : allocReg();
      emitInstr("la", Reg, GV->getName());
    } else if (ConstantExpr *CE = dyn_cast<ConstantExpr>(Val)) {
      // Convert constant expression into instruction
      Instruction *I = CE->getAsInstruction();
      handleInstruction(*I);
      Reg = getInstrReg(I);
      delete I;
    } else if (ConstantInt *CI = dyn_cast<ConstantInt>(Val)) {
      // Load constant into temporary register (rematerialization)
      Reg = !RegHint.empty() ? RegHint : allocReg();
      if (isSignedImm(Val)) {
        // If it's small enough we can use an addi
        emitInstr("addi", Reg, "$zero", getSignedImm(Val));
      } else {
        // Otherwise use load-immidate pseudo-instruction
        emitInstr("li", Reg, std::to_string(CI->getZExtValue()));
      }
    } else if (Instruction *I = dyn_cast<Instruction>(Val)) {
      Reg = getInstrReg(I);
    } else {
      return "$UNIMPLEMENTED";
    }

    if (RegHint.empty() || Reg == RegHint) {
      return Reg;
    }

    // Move value from Reg into RegHint
    emitInstr("move", RegHint, Reg);
    return RegHint;
  }

  //
  // You shouldn't need to call the following methods directly
  //

  // Allocate register for instruction result
  std::string getInstrReg(Instruction *I) {
    auto it = Regs.find(I);
    int RegNum;
    if (it != Regs.end()) {
      RegNum = it->second;
    } else {
      RegNum = UsedRegs++;
      Regs.insert({ I, RegNum });
    }
    return regNumToName(RegNum);
  }

  // Allocate an unused register
  std::string allocReg() {
    return regNumToName(UsedRegs++);
  }

  std::string regNumToName(int reg) {
    // First use $sN registers, then $tN registers
    if (reg < 8) {
      return "$s" + std::to_string(reg);
    } else {
      return "$t" + std::to_string(reg - 8);
    }
  }

  // Holds information about the data layout on this platform
  const DataLayout *DL;
  // Basic block that is currently being processed
  const BasicBlock *CurrentBB;

  // Number of registers used until now
  int UsedRegs = 0;
  // Output register for instructions
  DenseMap<Instruction *, int> Regs;

  // Unique name for each basic block, to be used when branching
  DenseMap<const BasicBlock *, std::string> BlockNames;

  // Set of already handled instructions. Can be used to avoid
  // repeated handling if two instructions are handled at once.
  DenseSet<Value *> HandledInstrs;

  DenseSet<PHINode *> PhiNodes;

  SmallVector<std::pair<PHINode*, Value*>, 8> PhiValues;
};

} // namespace

char MipsEmitPass::ID = 0;

// Pass registrations
static RegisterPass<MipsEmitPass> X("mips-emit-pass", "MIPS emission pass");
