#include "lib.h"

// A simple conditional
int main() {
	int a = 1;
	int b = 2;
	int c;
	if (a > b) {
		c = a;
	} else {
		c = b;
	}
	print_int(c);
	print_nl();

	unsigned d = (unsigned) -1;
	unsigned e = 1;
	unsigned f = d < e ? d : e;
	print_int(f);
	print_nl();

	return 0;
}
