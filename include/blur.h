#ifndef X3D_BLUR_H
#define X3D_BLUR_H

double (__stdcall * X3D_BlurCreate)(double parent);
double (__stdcall * X3D_BlurSetPreset)(double blur, double p);
double (__stdcall * X3D_BlurSetOptions)(double blur, double delta,
                                        double left, double top, double right,
                                        double bottom);
double (__stdcall * X3D_BlurSetResolution)(double blur, double res);

#endif
