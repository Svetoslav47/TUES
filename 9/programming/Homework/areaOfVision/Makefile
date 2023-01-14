all: taskManager.exe

processes.o: processes.c processes.h
	gcc -c processes.c

taskManager.exe: taskManager.c processes.o
	gcc -o taskManager.exe taskManager.c processes.o

clean:
	del *.o
	del *.exe