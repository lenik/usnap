
#include "hexedit.h"

int main() {
	char s[1024], *cs;
	int i;
	printf("string: ");
	gets(s);
	printf("you has inputted: \"%s\"\n", s);
	printf("next index: ");
	scanf("%d", &i);
	cs = next((char *)s, i);
	printf("current cs: \"%s\"\n", cs);
	return 0;
}
