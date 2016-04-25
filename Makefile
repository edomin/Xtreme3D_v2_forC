TOOLCHAIN = D:/Programming/Compilers/MinGW_4.8.1/bin
CC = mingw32-gcc
AR = mingw32-ar
CFLAGS = -Isrc -ansi
ARFLAGS = rcs

CONFIG_H_W =
CONFIG_H_T =
ifdef INC_WINDOW
  CFLAGS += -DX3D_INCLUDE_WINDOW_ROUTINES
  CONFIG_H_W =\#define X3D_INCLUDE_WINDOW_ROUTINES
endif
ifdef INC_TIMER
  CFLAGS += -DX3D_INCLUDE_TIMER_ROUTINES
  CONFIG_H_T =\#define X3D_INCLUDE_TIMER_ROUTINES
endif

.PHONY: all defines FORCE clean config

all: lib/libxtreme3d_2c.a

defines: .FORCE
	-rm include/config.h
	@echo "$(CONFIG_H_W)" >> include/config.h
	@echo "$(CONFIG_H_T)" >> include/config.h
	@echo "" >> include/config.h

lib/libxtreme3d_2c.a: obj/xtreme3d_2c.o
	-mkdir lib
	$(AR) $(ARFLAGS) lib/libxtreme3d_2c.a obj/xtreme3d_2c.o

obj/xtreme3d_2c.o: defines src/xtreme3d_2c.c src/xtreme3d_2c.h
	-mkdir obj
	$(CC) $(CFLAGS) -c src/xtreme3d_2c.c -o obj/xtreme3d_2c.o
	
clean:
	-rm -rf obj
	-rm include/config.h
	
.FORCE: