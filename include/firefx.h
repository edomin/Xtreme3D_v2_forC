#ifndef X3D_FIREFX_H
#define X3D_FIREFX_H

double (__stdcall * X3D_FireFXManagerCreate)(void);
double (__stdcall * X3D_FireFXCreate)(double manager, double parent);
double (__stdcall * X3D_FireFXSetColor)(double manager, double incolor, double inalpha, double outcolor, double outalpha);
double (__stdcall * X3D_FireFXSetMaxParticles)(double manager, double particles);
double (__stdcall * X3D_FireFXSetParticleSize)(double manager, double size);
double (__stdcall * X3D_FireFXSetDensity)(double manager, double density);
double (__stdcall * X3D_FireFXSetEvaporation)(double manager, double evaporation);
double (__stdcall * X3D_FireFXSetCrown)(double manager, double crown);
double (__stdcall * X3D_FireFXSetLife)(double manager, double life);
double (__stdcall * X3D_FireFXSetBurst)(double manager, double burst);
double (__stdcall * X3D_FireFXSetRadius)(double manager, double radius);
double (__stdcall * X3D_FireFXExplosion)(double manager, double isp, double maxsp, double lbf);

#endif