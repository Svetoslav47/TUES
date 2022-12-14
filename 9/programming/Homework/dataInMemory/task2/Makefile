all: safeadd.exe safesubtract.exe safemultiply.exe safedevide.exe

safeadd.exe: safeadd.c safeint.o safeint.h
	gcc safeadd.c safeint.c -o safeadd.exe

safesubtract.exe: safesubtract.c safeint.o safeint.h
	gcc safesubtract.c safeint.c -o safesubtract.exe

safemultiply.exe: safemultiply.c safeint.o safeint.h
	gcc safemultiply.c safeint.c -o safemultiply.exe

safedevide.exe: safedevide.c safeint.o safeint.h
	gcc safedevide.c safeint.c -o safedevide.exe
	
safeint.o: safeint.c safeint.h
	gcc -c safeint.c -o safeint.o

clean:
	del *.exe