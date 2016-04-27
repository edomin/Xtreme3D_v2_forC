#ifndef X3D_MIRROR_H
#define X3D_MIRROR_H

double (__stdcall * X3D_MirrorCreate)(double target, double parent);
double (__stdcall * X3D_MirrorSetObject)(double mirror, double target);
double (__stdcall * X3D_MirrorSetOptions)(double mirror, double stencil,
                                          double opaque, double planeclipping,
                                          double clearzbuffer);
#endif
