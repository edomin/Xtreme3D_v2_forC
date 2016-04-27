#ifndef X3D_LENSFLARE_H
#define X3D_LENSFLARE_H

double (__stdcall * X3D_LensflareCreate)(double parent);
double (__stdcall * X3D_LensflareSetSize)(double lf, double size);
double (__stdcall * X3D_LensflareSetSeed)(double lf, double seed);
double (__stdcall * X3D_LensflareSetSqueeze)(double lf, double squeeze);
double (__stdcall * X3D_LensflareSetStreaks)(double lf, double streaks);
double (__stdcall * X3D_LensflareSetStreakwidth)(double lf, double width);
double (__stdcall * X3D_LensflareSetSecs)(double lf, double secs);
double (__stdcall * X3D_LensflareSetResolution)(double lf, double res);
double (__stdcall * X3D_LensflareSetElements)(double lf, double glow,
                                              double ring, double streaks,
                                              double rays, double secs);
double (__stdcall * X3D_LensflareSetGradients)(double lf, double ind,
                                               double color1, double alpha1,
                                               double color2, double alpha2);
#endif
