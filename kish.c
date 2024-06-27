/* Kito Shell */

#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<spawn.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

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
			pid_t cpid = fork();
			switch(cpid) {
				case -1:
					perror("fork");
					exit(EXIT_FAILURE);
				case 0:
					execlp(prompt, prompt, NULL);
					fprintf(stderr,"%s\n", strerror(errno));
					exit(EXIT_FAILURE);
				default:
					wait(NULL);
					break;
			}
		}

	}
	putchar('\n');
	return EXIT_SUCCESS;
}
