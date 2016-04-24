#ifndef X3D_SKYBOX_H
#define X3D_SKYBOX_H

double (__stdcall * X3D_SkyboxCreate)(double parent);
double (__stdcall * X3D_SkyboxSetMaterial)(double sky, double index, char *mat);
double (__stdcall * X3D_SkyboxSetClouds)(double sky, double offset, double size);
double (__stdcall * X3D_SkyboxSetStyle)(double sky, double style);

#endif