LLVM_VERSION=${LLVM_VERSION:-3.5}
make LLVM_VERSION=$LLVM_VERSION || exit 1

for file in *.c ; do
  base=${file%.*}
  clang-$LLVM_VERSION -target mips -c -emit-llvm $file -o $base.bc
  opt-$LLVM_VERSION -mem2reg $base.bc -o $base.bc
  llvm-dis-$LLVM_VERSION $base.bc -o $base.ll
  opt-$LLVM_VERSION -load ./pass.so -mips-emit-pass $base.bc > /dev/null 2> $base.s
  cat $base.s lib.s > $base.s.full
  spim -file $base.s.full | tail -n +6 > $base.out
  diff -b $base.exp $base.out > $base.diff
  if [ $? != 0 ]; then
	echo "Output diff for $base.c, see $base.diff"
  fi
done
