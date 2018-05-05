#include "lib.h"

// Tip: If you get incorrect results on this test
// case, take a careful look at the assembly you
// generate for phi nodes. What could go wrong?

// Calculating fibonacci numbers
int fib(int n) {
	int a = 0;
	int b = 1;
	for (int i = 0; i < n; i++) {
		int t = a + b;
		a = b;
		b = t;
	}
	return b;
}

int main() {
	// Print first fibonacci numbers
	print_int(fib(0));
	print_nl();
	print_int(fib(1));
	print_nl();
	print_int(fib(2));
	print_nl();
	print_int(fib(3));
	print_nl();
	print_int(fib(4));
	print_nl();
	print_int(fib(5));
	print_nl();

	return 0;
}
