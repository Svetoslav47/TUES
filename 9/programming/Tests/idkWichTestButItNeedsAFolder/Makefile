all: longlong.exe smartcar.exe main.exe

longlong.exe: longlong.c
	gcc longlong.c -o longlong.exe

smartcar.exe: smartcar.c
	gcc smartcar.c -o smartcar.exe

main.exe: main.c counter.o
	gcc main.c counter.o -o main.exe

counter.o: counter.c counter.h
	gcc -c counter.c -o counter.o

clean:
	rm -f *.o *.exe