#include "lib.h"

// A reimplementation of strlen()
static int my_strlen(const char *str) {
	int len = 0;
	while (*str != '\0') {
		str++;
		len++;
	}
	return len;
}

int main() {
	print_int(my_strlen("foo"));
	return 0;
}
