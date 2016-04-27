#ifndef X3D_SPRITE_H
#define X3D_SPRITE_H

double (__stdcall * X3D_HUDSpriteCreate)(char *material, double width,
                                         double height, double parent);
double (__stdcall * X3D_SpriteCreate)(char *material, double width,
                                      double height, double parent);
double (__stdcall * X3D_SpriteSetSize)(double sprite, double width,
                                       double height);
double (__stdcall * X3D_SpriteScale)(double sprite, double x, double y);
double (__stdcall * X3D_SpriteSetRotation)(double sprite, double angle);
double (__stdcall * X3D_SpriteRotate)(double sprite, double angle);
double (__stdcall * X3D_SpriteMirror)(double nr, double u, double v);
double (__stdcall * X3D_SpriteNoZWrite)(double sprite, double mode);
double (__stdcall * X3D_ObjectUseObjectColor)(double obj, double mode);

#endif
