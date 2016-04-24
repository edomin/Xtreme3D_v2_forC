#ifndef X3D_WATER_H
#define X3D_WATER_H

double (__stdcall * X3D_WaterCreate)(double parent);
double (__stdcall * X3D_WaterCreateRandomRipple)(double water);
double (__stdcall * X3D_WaterCreateRippleAtGridPosition)(double water, double x, double y);
double (__stdcall * X3D_WaterSetMask)(double water, char *material);
double (__stdcall * X3D_WaterSetActive)(double water, double active);
double (__stdcall * X3D_WaterReset)(double water);
double (__stdcall * X3D_WaterSetRainTimeInterval)(double water, double rti);
double (__stdcall * X3D_WaterSetRainForce)(double water, double force);
double (__stdcall * X3D_WaterSetViscosity)(double water, double viscosity);
double (__stdcall * X3D_WaterSetElastic)(double water, double elastic);
double (__stdcall * X3D_WaterSetResolution)(double water, double resolution);

#endif