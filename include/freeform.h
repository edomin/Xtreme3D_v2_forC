#ifndef X3D_FREEFORM_H
#define X3D_FREEFORM_H

double (__stdcall * X3D_FreeformCreate)(char *filename, double parent);
double (__stdcall * X3D_FreeformPointInMesh)(double freeform, double x, double y, double z);
double (__stdcall * X3D_FreeformSphereSweepIntersect)(double freeform, double sphere, double radius, double vel);
double (__stdcall * X3D_FreeformToFreeforms)(double freeform, double start, double count, double parent);
double (__stdcall * X3D_FreeformSetSecondTextureCoords)(double freeform1, double freeform2);

#endif