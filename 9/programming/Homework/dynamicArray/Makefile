all: tests.exe donors.exe

dynamicArray.o: dynamicArray.h dynamicArray.c
	gcc -c dynamicArray.c -o dynamicArray.o

donors.exe: dynamicArray.o donors.c
	gcc donors.c dynamicArray.o -o donors.exe

tests.exe: dynamicArray.o tests.c
	gcc tests.c dynamicArray.o -o tests.exe 

clean:
	rm -f *.exe *.o