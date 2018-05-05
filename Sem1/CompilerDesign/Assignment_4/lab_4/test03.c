#include "lib.h"

// Basic bitwise operators
int main() {
	int a = 0x77;
	int b = 0xf8;
	print_int(a & b);
	print_nl();
	print_int(a | b);
	print_nl();
	print_int(a ^ b);
	print_nl();

	int c = 0xff00ff00;
	int d = 0x77777777;
	print_int(c & d);
	print_nl();
	print_int(c | d);
	print_nl();
	print_int(c ^ d);
	print_nl();

	return 0;
}
