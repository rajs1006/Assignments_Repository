LLVM_VERSION ?= 3.5
CXXFLAGS = -rdynamic $(shell llvm-config-$(LLVM_VERSION) --cxxflags) -g -O0 -std=c++0x

.PHONY: all clean

all: pass.so

%.so: %.o
	$(CXX) $(CXXFLAGS) -dylib -shared -fPIC  $^ -o $@

clean:
	rm -f *.o *.so *.dwo *.bc *.ll *.out *.diff *.s.full test*.s
