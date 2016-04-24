#ifndef X3D_SHADOWPLANE_H
#define X3D_SHADOWPLANE_H

double (__stdcall * X3D_ShadowplaneCreate)(double width, double height, double xtiles, double ytiles, double target, double light, double color, double alpha, double parent);
double (__stdcall * X3D_ShadowplaneSetLight)(double sp, double light);
double (__stdcall * X3D_ShadowplaneSetObject)(double sp, double target);
double (__stdcall * X3D_ShadowplaneSetOptions)(double sp, double stencil, double scissor, double transparent, double ignorez);

#endif