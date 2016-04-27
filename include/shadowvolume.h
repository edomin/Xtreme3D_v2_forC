#ifndef X3D_SHADOWVOLUME_H
#define X3D_SHADOWVOLUME_H

double (__stdcall * X3D_ShadowvolumeCreate)(double parent);
double (__stdcall * X3D_ShadowvolumeSetActive)(double sv, double value);
double (__stdcall * X3D_ShadowvolumeAddLight)(double sv, double l);
double (__stdcall * X3D_ShadowvolumeRemoveLight)(double sv, double l);
double (__stdcall * X3D_ShadowvolumeAddOccluder)(double sv, double obj);
double (__stdcall * X3D_ShadowvolumeRemoveOccluder)(double sv, double obj);
double (__stdcall * X3D_ShadowvolumeSetDarkeningColor)(double sv, double color,
                                                       double a);
double (__stdcall * X3D_ShadowvolumeSetMode)(double sv, double mode);
double (__stdcall * X3D_ShadowvolumeSetOptions)(double sv, double op1,
                                                double op2, double op3,
                                                double op4);

#endif
