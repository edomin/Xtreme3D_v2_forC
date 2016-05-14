TOOLCHAIN = D:/Programming/Compilers/MinGW_4.8.1/bin
CC = $(TOOLCHAIN)/mingw32-gcc
LD = $(TOOLCHAIN)/mingw32-gcc
CFLAGS = -I../include -Iinclude
LDFLAGS = -L../lib -lxtreme3d_2c -mwindows

all: template.exe

template.exe: template.o
	$(LD) -o template.exe template.o $(LDFLAGS)

template.o: template.c
	$(CC) $(CFLAGS) -c template.c -o template.o
	
clean:
	-rm *.o