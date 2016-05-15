TOOLCHAIN = D:/Programming/Compilers/MinGW_4.8.1/bin
CC = $(TOOLCHAIN)/mingw32-gcc
LD = $(TOOLCHAIN)/mingw32-gcc
CFLAGS = -I../include -Iinclude -Wall
LDFLAGS = -L../lib -lxtreme3d_2c -mwindows -s

SAMPLES = template.exe \
	terrain.exe \
	3rdperson.exe \
	water.exe \
	bumpmapping_and_blur.exe \
	volumetric_spotlight.exe \
	offscreen_rendering.exe \
	octree_1.exe \
	octree_2.exe \
	antialiasing.exe \
	parallax_mapping.exe \
	raycasting.exe \
	smd_skeleton_basic.exe \
	smd_skeleton_trinity.exe \
	thorfx.exe \
	primitives.exe \
	fps_demo.exe

all: $(SAMPLES) copylibraries

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

water.exe: water.o
	$(LD) -o water.exe water.o $(LDFLAGS)

water.o: water.c
	$(CC) $(CFLAGS) -c water.c -o water.o

bumpmapping_and_blur.exe: bumpmapping_and_blur.o
	$(LD) -o bumpmapping_and_blur.exe bumpmapping_and_blur.o $(LDFLAGS)

bumpmapping_and_blur.o: bumpmapping_and_blur.c
	$(CC) $(CFLAGS) -c bumpmapping_and_blur.c -o bumpmapping_and_blur.o

volumetric_spotlight.exe: volumetric_spotlight.o
	$(LD) -o volumetric_spotlight.exe volumetric_spotlight.o $(LDFLAGS)

volumetric_spotlight.o: volumetric_spotlight.c
	$(CC) $(CFLAGS) -c volumetric_spotlight.c -o volumetric_spotlight.o

offscreen_rendering.exe: offscreen_rendering.o
	$(LD) -o offscreen_rendering.exe offscreen_rendering.o $(LDFLAGS)

offscreen_rendering.o: offscreen_rendering.c
	$(CC) $(CFLAGS) -c offscreen_rendering.c -o offscreen_rendering.o

octree_1.exe: octree_1.o
	$(LD) -o octree_1.exe octree_1.o $(LDFLAGS)

octree_1.o: octree_1.c
	$(CC) $(CFLAGS) -c octree_1.c -o octree_1.o

octree_2.exe: octree_2.o
	$(LD) -o octree_2.exe octree_2.o $(LDFLAGS)

octree_2.o: octree_2.c
	$(CC) $(CFLAGS) -c octree_2.c -o octree_2.o

antialiasing.exe: antialiasing.o
	$(LD) -o antialiasing.exe antialiasing.o $(LDFLAGS)

antialiasing.o: antialiasing.c
	$(CC) $(CFLAGS) -c antialiasing.c -o antialiasing.o

parallax_mapping.exe: parallax_mapping.o
	$(LD) -o parallax_mapping.exe parallax_mapping.o $(LDFLAGS)

parallax_mapping.o: parallax_mapping.c
	$(CC) $(CFLAGS) -c parallax_mapping.c -o parallax_mapping.o

raycasting.exe: raycasting.o
	$(LD) -o raycasting.exe raycasting.o $(LDFLAGS)

raycasting.o: raycasting.c
	$(CC) $(CFLAGS) -c raycasting.c -o raycasting.o

smd_skeleton_basic.exe: smd_skeleton_basic.o
	$(LD) -o smd_skeleton_basic.exe smd_skeleton_basic.o $(LDFLAGS)

smd_skeleton_basic.o: smd_skeleton_basic.c
	$(CC) $(CFLAGS) -c smd_skeleton_basic.c -o smd_skeleton_basic.o

smd_skeleton_trinity.exe: smd_skeleton_trinity.o
	$(LD) -o smd_skeleton_trinity.exe smd_skeleton_trinity.o $(LDFLAGS)

smd_skeleton_trinity.o: smd_skeleton_trinity.c
	$(CC) $(CFLAGS) -c smd_skeleton_trinity.c -o smd_skeleton_trinity.o

thorfx.exe: thorfx.o
	$(LD) -o thorfx.exe thorfx.o $(LDFLAGS)

thorfx.o: thorfx.c
	$(CC) $(CFLAGS) -c thorfx.c -o thorfx.o

primitives.exe: primitives.o
	$(LD) -o primitives.exe primitives.o $(LDFLAGS)

primitives.o: primitives.c
	$(CC) $(CFLAGS) -c primitives.c -o primitives.o

fps_demo.exe: fps_demo.o
	$(LD) -o fps_demo.exe fps_demo.o $(LDFLAGS)

fps_demo.o: fps_demo.c
	$(CC) $(CFLAGS) -c fps_demo.c -o fps_demo.o

clean:
	-rm *.o
	
.PHONY: copylibraries
