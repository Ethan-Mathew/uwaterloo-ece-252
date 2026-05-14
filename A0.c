#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		for (int j = 0; j < strlen(argv[i]); j++) {
			if (argv[i][j] == '-') {
				printf("\t");
			} else {
				break;
			}
		}

		printf("%s\n", argv[i]);
	}

	return 0;
}
