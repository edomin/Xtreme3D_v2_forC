#ifndef X3D_FPS_H
#define X3D_FPS_H

double (__stdcall * X3D_FpsManagerCreate)(void);
double (__stdcall * X3D_FpsManagerSetNavigator)(double manager, double nav);
double (__stdcall * X3D_FpsManagerSetMovementScale)(double manager, double scale);
double (__stdcall * X3D_FpsManagerAddMap)(double manager, double object);
double (__stdcall * X3D_FpsManagerRemoveMap)(double manager, double object);
double (__stdcall * X3D_FPSMapSetGroup)(double object, double group);
double (__stdcall * X3D_FpsSetManager)(double object, double manager);
double (__stdcall * X3D_FpsSetGroup)(double object, double group);
double (__stdcall * X3D_FpsSetSphereRadius)(double object);
double (__stdcall * X3D_FpsSetGravity)(double object, double mode);
double (__stdcall * X3D_FpsMove)(double object, double speed);
double (__stdcall * X3D_FpsStrafe)(double object, double speed);
double (__stdcall * X3D_FpsLift)(double object, double speed);
double (__stdcall * X3D_FpsGetVelocity)(double object, double ind);
double (__stdcall * X3D_FpsCountCollisions)(double object);
double (__stdcall * X3D_FpsClearCollisions)(double object);
double (__stdcall * X3D_FpsGetCollisionPosition)(double object, double col, double ind);
double (__stdcall * X3D_FpsGetCollisionNormal)(double object, double col, double ind);
double (__stdcall * X3D_FpsGetCollidedObject)(double object, double col);

#endif