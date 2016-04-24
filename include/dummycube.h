#ifndef X3D_DUMMYCUBE_H
#define X3D_DUMMYCUBE_H

double (__stdcall * X3D_DummycubeCreate)(double parent);
double (__stdcall * X3D_DummycubeAmalgamate)(double object, double mode);
double (__stdcall * X3D_DummycubeSetCameraMode)(double object, double cim);

#endif