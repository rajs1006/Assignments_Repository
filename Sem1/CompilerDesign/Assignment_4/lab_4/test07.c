#include "lib.h"

// A simple for loop
int main() {
	int i;
	int k = 0;
	for (i = 0; i < 100; i++) {
		k += i;
	}
	print_int(k);
	return 0;
}
