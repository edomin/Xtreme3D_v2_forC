#ifndef X3D_THORFX_H
#define X3D_THORFX_H

double (__stdcall * X3D_ThorFXManagerCreate)(void);
double (__stdcall * X3D_ThorFXCreate)(double fm, double child);
double (__stdcall * X3D_ThorFXSetColor)(double fm, double inc, double ina,
                                        double outc, double outa, double cc,
                                        double ca);
double (__stdcall * X3D_ThorFXEnableCore)(double fm, double mode);
double (__stdcall * X3D_ThorFXEnableGlow)(double fm, double mode);
double (__stdcall * X3D_ThorFXSetMaxParticles)(double fm, double max);
double (__stdcall * X3D_ThorFXSetGlowSize)(double fm, double max);
double (__stdcall * X3D_ThorFXSetVibrate)(double fm, double max);
double (__stdcall * X3D_ThorFXSetWildness)(double fm, double max);
double (__stdcall * X3D_ThorFXSetTarget)(double fm, double x, double y,
                                         double z);
double (__stdcall * X3D_ThorFXSetTargetAsObject)(double fm, double obj);

#endif
