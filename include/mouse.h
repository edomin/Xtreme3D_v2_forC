#ifndef X3D_MOUSE_H
#define X3D_MOUSE_H

double (__stdcall * X3D_MouseGetX)(void);
double (__stdcall * X3D_MouseGetY)(void);
double (__stdcall * X3D_MouseSetPosition)(double x, double y);
double (__stdcall * X3D_MouseShowCursor)(double mode);

#endif
