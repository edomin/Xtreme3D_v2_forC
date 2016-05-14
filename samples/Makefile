TOOLCHAIN = D:/Programming/Compilers/MinGW_4.8.1/bin
CC = $(TOOLCHAIN)/mingw32-gcc
LD = $(TOOLCHAIN)/mingw32-gcc
CFLAGS = -I../include -Iinclude -Wall
LDFLAGS = -L../lib -lxtreme3d_2c -mwindows -s

all: template.exe terrain.exe 3rdperson.exe copylibraries

copylibraries:
	cp ../ode.dll ode.dll
	cp ../Xtreme3D.dll Xtreme3D.dll

template.exe: template.o
	$(LD) -o template.exe template.o $(LDFLAGS)

template.o: template.c
	$(CC) $(CFLAGS) -c template.c -o template.o

terrain.exe: terrain.o
	$(LD) -o terrain.exe terrain.o $(LDFLAGS)

terrain.o: terrain.c
	$(CC) $(CFLAGS) -c terrain.c -o terrain.o

3rdperson.exe: 3rdperson.o
	$(LD) -o 3rdperson.exe 3rdperson.o $(LDFLAGS)

3rdperson.o: 3rdperson.c
	$(CC) $(CFLAGS) -c 3rdperson.c -o 3rdperson.o

clean:
	-rm *.o
	
.PHONY: copylibraries
