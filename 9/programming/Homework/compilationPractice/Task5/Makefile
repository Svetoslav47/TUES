main.out:
	gcc -c maths.c -o maths.o
	ar rcs libmath.a maths.o
	gcc main.c -L. -lmath -o main.out