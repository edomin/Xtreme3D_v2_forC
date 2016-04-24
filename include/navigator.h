#ifndef X3D_NAVIGATOR_H
#define X3D_NAVIGATOR_H

double (__stdcall * X3D_NavigatorCreate)(void);
double (__stdcall * X3D_NavigatorSetObject)(double nav, double object);
double (__stdcall * X3D_NavigatorSetUseVirtualUp)(double nav, double mode);
double (__stdcall * X3D_NavigatorSetVirtualUp)(double nav, double x, double y, double z);
double (__stdcall * X3D_NavigatorTurnHorizontal)(double nav, double angle);
double (__stdcall * X3D_NavigatorTurnVertical)(double nav, double angle);
double (__stdcall * X3D_NavigatorMoveForward)(double nav, double speed);
double (__stdcall * X3D_NavigatorStrafeHorizontal)(double nav, double speed);
double (__stdcall * X3D_NavigatorStrafeVertical)(double nav, double speed);
double (__stdcall * X3D_NavigatorStraighten)(double nav);
double (__stdcall * X3D_NavigatorFlyForward)(double nav, double speed);
double (__stdcall * X3D_NavigatorMoveUpWhenMovingForward)(double nav, double mode);
double (__stdcall * X3D_NavigatorInvertHorizontalWhenUpsideDown)(double nav, double mode);
double (__stdcall * X3D_NavigatorSetAngleLock)(double nav, double mode);
double (__stdcall * X3D_NavigatorSetAngles)(double nav, double min, double max);

#endif