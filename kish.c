/* Kito Shell */

#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<spawn.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

extern char ** environ;

int main() {
	while(1) {
		printf("--kish--$ ");
		char *prompt = NULL;
		size_t n = 0;
		if (getline(&prompt, &n, stdin) == -1) {
			if(!feof(stdin)) {
				printf("%s\n", strerror(errno));
			}
			break;
		}
		prompt[strlen(prompt) - 1] = 0;
		if (strlen(prompt) > 0) {
			char *argv[] = {prompt, NULL};
			posix_spawnp(NULL, prompt, NULL, NULL, argv, environ);
			wait(NULL);
		}

	}
	putchar('\n');
	return EXIT_SUCCESS;
}
