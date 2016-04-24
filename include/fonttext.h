#ifndef X3D_FONTTEXT_H
#define X3D_FONTTEXT_H

double (__stdcall * X3D_BmpfontCreate)(double width, double height, double hspace, double vspace, double intx, double inty, double start, double end);
double (__stdcall * X3D_BmpfontLoad)(double font, char *material);
double (__stdcall * X3D_WindowsBitmapfontCreate)(char *fontname, double material);
double (__stdcall * X3D_FlatTextCreate)(double font, char *string, double parent);
double (__stdcall * X3D_HUDTextCreate)(double font, char *string, double parent);
double (__stdcall * X3D_HUDTextSetRotation)(double text, double angle);
double (__stdcall * X3D_SpaceTextCreate)(char *font, double string, double parent);
double (__stdcall * X3D_SpaceTextSetExtrusion)(double text, double extrusion);
double (__stdcall * X3D_TextSetColor)(double text, double color, double alpha);
double (__stdcall * X3D_TextSetFont)(double text, double font);
double (__stdcall * X3D_TextSetText)(double text, char *string);

#endif