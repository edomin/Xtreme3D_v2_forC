#ifndef X3D_SHADERS_H
#define X3D_SHADERS_H

double (__stdcall * X3D_ShaderEnable)(double shader, double mode);
double (__stdcall * X3D_BumpShaderCreate)(double texture2);
double (__stdcall * X3D_CelShaderCreate)(void);
double (__stdcall * X3D_CelShaderSetLineColor)(double shader, double color);
double (__stdcall * X3D_CelShaderSetLineWidth)(double shader, double width);
double (__stdcall * X3D_HiddenLineShaderCreate)(void);
double (__stdcall * X3D_HiddenLineShaderSetLineSmooth)(double shader,
                                                       double mode);
double (__stdcall * X3D_HiddenLineShaderSetSolid)(double shader, double mode);
double (__stdcall * X3D_HiddenLineShaderSetSurfaceLit)(double shader,
                                                       double mode);
double (__stdcall * X3D_HiddenLineShaderSetFrontLine)(double shader,
                                                      double width,
                                                      double color, double p,
                                                      double f);
double (__stdcall * X3D_HiddenLineShaderSetBackLine)(double shader,
                                                     double width, double color,
                                                     double p, double f);
double (__stdcall * X3D_MultiMaterialShaderCreate)(double matlib);
double (__stdcall * X3D_OutlineShaderCreate)(double smooth);
double (__stdcall * X3D_OutlineShaderSetLineColor)(double shader, double color);
double (__stdcall * X3D_OutlineShaderSetLineWidth)(double shader, double width);

#endif
