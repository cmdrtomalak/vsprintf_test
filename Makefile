all:
	gcc -g -nostdlib -o print main.c vsprintf.c lib/write.c lib/errno.c
