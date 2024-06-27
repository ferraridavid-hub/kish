kish: kish.c
	gcc -Wall -Werror -O -o kish kish.c

clean:
	rm kish

debug:
	gcc -Wall -Werror -g -o kish kish.c
