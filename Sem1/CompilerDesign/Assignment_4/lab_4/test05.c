#include "lib.h"

// Basic shift operations
int main() {
	unsigned a = 42;
	int b = -42;
	unsigned s = 3;
	print_int(a << s);
	print_nl();
	print_int(a >> s);
	print_nl();
	print_int(b >> s);
	print_nl();

	unsigned s2 = s + 1;
	print_int(a << s2);
	print_nl();
	print_int(a >> s2);
	print_nl();
	print_int(b >> s2);
	print_nl();
	return 0;
}
