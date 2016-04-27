#ifndef X3D_LIGHT_H
#define X3D_LIGHT_H

double (__stdcall * X3D_LightCreate)(double ls, double parent);
double (__stdcall * X3D_LightSetAmbientColor)(double light, double color);
double (__stdcall * X3D_LightSetDiffuseColor)(double light, double color);
double (__stdcall * X3D_LightSetSpecularColor)(double light, double color);
double (__stdcall * X3D_LightSetAttenuation)(double light, double constant,
                                             double linear, double quadratic);
double (__stdcall * X3D_LightSetShining)(double light, double mode);
double (__stdcall * X3D_LightSetSpotCutoff)(double light, double cutoff);
double (__stdcall * X3D_LightSetSpotExponent)(double light, double exponent);
double (__stdcall * X3D_LightSetSpotDirection)(double light, double x, double y,
                                               double z);
double (__stdcall * X3D_LightSetStyle)(double light, double ls);

#endif
