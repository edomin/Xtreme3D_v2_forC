#ifndef X3D_DCE_H
#define X3D_DCE_H

double (__stdcall * X3D_DceManagerCreate)(void);
double (__stdcall * X3D_DceManagerStep)(double manager, double delta);
double (__stdcall * X3D_DceManagerSetWorldDirection)(double manager, double x,
                                                     double y, double z);
double (__stdcall * X3D_DceManagerSetWorldScale)(double manager, double scale);
double (__stdcall * X3D_DceManagerSetMovementScale)(double manager,
                                                    double scale);
double (__stdcall * X3D_DceManagerSetLayers)(double manager, double ccs);
double (__stdcall * X3D_DceManagerSetManualStep)(double manager, double mode);
double (__stdcall * X3D_DceSetManager)(double object, double manager);
double (__stdcall * X3D_DceSetActive)(double object, double mode);
double (__stdcall * X3D_DceIsActive)(double object);
double (__stdcall * X3D_DceSetUseGravity)(double object, double mode);
double (__stdcall * X3D_DceSetLayer)(double object, double layer);
double (__stdcall * X3D_DceGetLayer)(double object);
double (__stdcall * X3D_DceSetSolid)(double object, double mode);
double (__stdcall * X3D_DceSetFriction)(double object, double friction);
double (__stdcall * X3D_DceSetBounce)(double object, double bounce);
double (__stdcall * X3D_DceSetSize)(double object, double x, double y,
                                    double z);
double (__stdcall * X3D_DceSetSlideOrBounce)(double object, double csb);
double (__stdcall * X3D_DceApplyAcceleration)(double object, double x,
                                              double y, double z);
double (__stdcall * X3D_DceApplyAbsAcceleration)(double object, double x,
                                                 double y, double z);
double (__stdcall * X3D_DceStopAcceleration)(double object);
double (__stdcall * X3D_DceStopAbsAcceleration)(double object);
double (__stdcall * X3D_DceJump)(double object, double height, double speed);
double (__stdcall * X3D_DceMove)(double object, double x, double y, double z,
                                 double delta);
double (__stdcall * X3D_DceMoveTo)(double object, double x, double y, double z,
                                   double amount);
double (__stdcall * X3D_DceSetSpeed)(double object, double x, double y,
                                     double z);
double (__stdcall * X3D_DceInGround)(double object);
double (__stdcall * X3D_DceSetMaxRecursionDepth)(double object, double depth);
double (__stdcall * X3D_DceStaticSetManager)(double object, double manager);
double (__stdcall * X3D_DceStaticSetActive)(double object, double mode);
double (__stdcall * X3D_DceStaticSetShape)(double object, double cs);
double (__stdcall * X3D_DceStaticSetLayer)(double object, double layer);
double (__stdcall * X3D_DceStaticSetSize)(double object, double x, double y,
                                          double z);
double (__stdcall * X3D_DceStaticSetSolid)(double object, double mode);
double (__stdcall * X3D_DceStaticSetFriction)(double object, double friction);
double (__stdcall * X3D_DceStaticSetBounceFactor)(double object, double bounce);
double (__stdcall * X3D_DceGetVelocity)(double object, double ind);
double (__stdcall * X3D_DceGetGravity)(double object, double ind);
double (__stdcall * X3D_DceVelocityCollided)(double object);
double (__stdcall * X3D_DceGravityCollided)(double object);
double (__stdcall * X3D_DceCountCollisions)(double object);
double (__stdcall * X3D_DceGetCollidedObject)(double object, double col);
double (__stdcall * X3D_DceGetCollisionPosition)(double object, double col,
                                                 double ind);
double (__stdcall * X3D_DceGetCollisionNormal)(double object, double col,
                                               double ind);
#endif
