#ifndef X3D_SKYDOME_H
#define X3D_SKYDOME_H

double (__stdcall * X3D_SkydomeCreate)(double slice1, double slice2, double parent);
double (__stdcall * X3D_SkydomeSetOptions)(double sky, double fade, double rotate);
double (__stdcall * X3D_SkydomeSetDeepColor)(double sky, double color);
double (__stdcall * X3D_SkydomeSetHazeColor)(double sky, double color);
double (__stdcall * X3D_SkydomeSetNightColor)(double sky, double color);
double (__stdcall * X3D_SkydomeSetSkyColor)(double sky, double color);
double (__stdcall * X3D_SkydomeSetSunDawnColor)(double sky, double color);
double (__stdcall * X3D_SkydomeSetSunZenithColor)(double sky, double color);
double (__stdcall * X3D_SkydomeSetSunElevation)(double sky, double sun);
double (__stdcall * X3D_SkydomeSetTurbidity)(double sky, double turn);
double (__stdcall * X3D_SkydomeAddRandomStars)(double sky, double s, double c);
double (__stdcall * X3D_SkydomeClearStars)(double sky);
double (__stdcall * X3D_SkydomeTwinkleStars)(double sky, double t);

#endif