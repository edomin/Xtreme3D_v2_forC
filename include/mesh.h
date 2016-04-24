#ifndef X3D_MESH_H
#define X3D_MESH_H

double (__stdcall * X3D_MeshCountObjects)(double object);
double (__stdcall * X3D_MeshRotate)(double object, double x, double y, double z, double angle);
double (__stdcall * X3D_MeshExplode)(double object, double sp, double max, double x, double y, double z);
double (__stdcall * X3D_MeshSetVisible)(double object, double ind, double mode);
double (__stdcall * X3D_MeshCountVertices)(double object, double ind);
double (__stdcall * X3D_MeshOptimize)(double object);
double (__stdcall * X3D_MeshSmoothFaces)(double object, double weld, double threshold);

#endif