/* Kito Shell */

#include<errno.h>
#include<stdio.h>
#include<string.h>

int main() {
	while(1) {
		printf("--kish--$ ");
		char *prompt = NULL;
		size_t n = 0;
		errno=2;
		if (getline(&prompt, &n, stdin) == -1) {
			if(!feof(stdin)) {
				printf("%s\n", strerror(errno));
			}
			break;
		}
		// Here prompt contains the entire command 


	}
	putchar('\n');
}
