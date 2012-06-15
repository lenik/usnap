
void main() {
	char *Hello = "Hello, World!\n";

	int i;

	for (i = 0; i < strlen(Hello) - 1; i++) {
		Hello[i] |= 0x20;
	}

	printf("%s", Hello);

	return;
}
