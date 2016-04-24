TOOLCHAIN = D:/Programming/Compilers/MinGW_4.8.1/bin
CC = $(TOOLCHAIN)/mingw32-gcc
AR = $(TOOLCHAIN)/mingw32-ar
CFLAGS = -Isrc -ansi
ARFLAGS = rcs

all: lib/libxtreme3d_2c.a

lib/libxtreme3d_2c.a: obj/xtreme3d_2c.o
	-mkdir lib
	$(AR) $(ARFLAGS) lib/libxtreme3d_2c.a obj/xtreme3d_2c.o

obj/xtreme3d_2c.o: src/xtreme3d_2c.c src/xtreme3d_2c.h
	-mkdir obj
	$(CC) $(CFLAGS) -c src/xtreme3d_2c.c -o obj/xtreme3d_2c.o
	
clean:
	-rm -rf obj