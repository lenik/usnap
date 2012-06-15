#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char **argv) {
	if (argc >= 2) {
		return (int)atol(argv[1]);
	} else {
		printf("%d\n", errno);
	}
	return errno;
}