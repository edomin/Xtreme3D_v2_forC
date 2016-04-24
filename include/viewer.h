#ifndef X3D_VIEWER_H
#define X3D_VIEWER_H

double (__stdcall * X3D_ViewerCreate)(double x, double y, double vwidth, double vheight);
double (__stdcall * X3D_ViewerSetCamera)(double viewer, double camera);
double (__stdcall * X3D_ViewerEnableVSync)(double viewer, double mode);
double (__stdcall * X3D_ViewerRender)(double viewer);
double (__stdcall * X3D_ViewerResize)(double viewer, double x, double y, double width, double height);
double (__stdcall * X3D_ViewerSetVisible)(double viewer, double mode);
double (__stdcall * X3D_ViewerGetPixelColor)(double viewer, double x, double y);
double (__stdcall * X3D_ViewerGetPixelDepth)(double viewer, double x, double y);
double (__stdcall * X3D_ViewerSetLighting)(double viewer, double mode);
double (__stdcall * X3D_ViewerSetBackgroundColor)(double viewer, double color);
double (__stdcall * X3D_ViewerSetAmbientColor)(double viewer, double color);
double (__stdcall * X3D_ViewerEnableFog)(double viewer, double mode);
double (__stdcall * X3D_ViewerSetFogColor)(double viewer, double color);
double (__stdcall * X3D_ViewerSetFogDistance)(double viewer, double f_start, double f_end);
double (__stdcall * X3D_ViewerScreenToWorld)(double viewer, double x, double y, double ind);
double (__stdcall * X3D_ViewerWorldToScreen)(double viewer, double x, double y, double z, double ind);
double (__stdcall * X3D_ViewerCopyToTexture)(double viewer, char *matname);

#endif