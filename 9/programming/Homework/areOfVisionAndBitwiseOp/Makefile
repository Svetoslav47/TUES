all: robot.exe

robot.exe: robot.c bitstate.o
	gcc robot.c bitstate.o -o robot.exe

bitstate.o: bitstate.c bitstate.h
	gcc -c bitstate.c -o bitstate.o

clean:
	del *.o *.exe