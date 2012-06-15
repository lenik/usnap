
#include "escstr.h"

#ifdef __DEBUG_ESCSTR

#include <iostream>

void main() {
	char buf[1024];

	do {
		std::cin.getline(buf, sizeof(buf));
		if (strlen(buf) == 0) break;

		int i;
		size_t cOutstr = sizeof(buf);
		i = make_escaped_string(buf, strlen(buf), buf, cOutstr, &cOutstr);

		std::cout << buf;
	} while (1);
}

#endif
