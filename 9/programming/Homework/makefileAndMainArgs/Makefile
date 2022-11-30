all: help.out strlenght.out strconcat.out strcmp.out

strlenght.out: strlenght.c mystrings.o
	gcc strlenght.c mystrings.o -o strlenght.out

strconcat.out: strconcat.c mystrings.o
	gcc strconcat.c mystrings.o -o strconcat.out

strcmp.out: strcmp.c mystrings.o
	gcc strcmp.c mystrings.o -o strcmp.out

help.out: help.c
	gcc help.c -o help.out

mystrings.o: mystrings.c mystrings.h
	gcc -c mystrings.c -o mystrings.o

clean:
	rm -f *.o *.out *.a