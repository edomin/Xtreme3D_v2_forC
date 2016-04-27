#ifndef X3D_ODE_H
#define X3D_ODE_H

double (__stdcall * X3D_OdeManagerCreate)(void);
double (__stdcall * X3D_OdeManagerDestroy)(void);
double (__stdcall * X3D_OdeManagerStep)(double delta);
double (__stdcall * X3D_OdeManagerGetNumContactJoints)(void);
double (__stdcall * X3D_OdeManagerSetGravity)(double x, double y, double z);
double (__stdcall * X3D_OdeManagerSetSolver)(double osm);
double (__stdcall * X3D_OdeManagerSetIterations)(double iterations);
double (__stdcall * X3D_OdeManagerSetMaxContacts)(double maxcontacts);
double (__stdcall * X3D_OdeManagerSetVisible)(double mode);
double (__stdcall * X3D_OdeManagerSetGeomColor)(double color);
double (__stdcall * X3D_OdeWorldSetAutoDisableFlag)(double flag);
double (__stdcall * X3D_OdeWorldSetAutoDisableLinearThreshold)(double velocity);
double (__stdcall * X3D_OdeWorldSetAutoDisableAngularThreshold)(double velocity);
double (__stdcall * X3D_OdeWorldSetAutoDisableSteps)(double steps);
double (__stdcall * X3D_OdeWorldSetAutoDisableTime)(double time);
double (__stdcall * X3D_OdeDynamicSetAutoDisableFlag)(double object, double flag);
double (__stdcall * X3D_OdeDynamicSetAutoDisableLinearThreshold)(double object,
                                                                 double velocity);
double (__stdcall * X3D_OdeDynamicSetAutoDisableAngularThreshold)(double object,
                                                                  double velocity);
double (__stdcall * X3D_OdeDynamicSetAutoDisableSteps)(double object,
                                                       double steps);
double (__stdcall * X3D_OdeDynamicSetAutoDisableTime)(double object,
                                                      double time);
double (__stdcall * X3D_OdeStaticCreate)(double object);
double (__stdcall * X3D_OdeDynamicCreate)(double object);
double (__stdcall * X3D_OdeDynamicAlignObject)(double object);
double (__stdcall * X3D_OdeDynamicEnable)(double object, double mode);
double (__stdcall * X3D_OdeDynamicCalibrateCenterOfMass)(double object);
double (__stdcall * X3D_OdeDynamicAddForce)(double object, double x, double y,
                                            double z);
double (__stdcall * X3D_OdeDynamicAddForceAtPos)(double object, double x,
                                                 double y, double z, double px,
                                                 double py, double pz);
double (__stdcall * X3D_OdeDynamicAddForceAtRelPos)(double object, double x,
                                                    double y, double z,
                                                    double px, double py,
                                                    double pz);
double (__stdcall * X3D_OdeDynamicAddRelForce)(double object, double x,
                                               double y, double z);
double (__stdcall * X3D_OdeDynamicAddRelForceAtPos)(double object, double x,
                                                    double y, double z,
                                                    double px, double py,
                                                    double pz);
double (__stdcall * X3D_OdeDynamicAddRelForceAtRelPos)(double object, double x,
                                                       double y, double z,
                                                       double px, double py,
                                                       double pz);
double (__stdcall * X3D_OdeDynamicAddTorque)(double object, double x, double y,
                                             double z);
double (__stdcall * X3D_OdeDynamicAddRelTorque)(double object, double x,
                                                double y, double z);
double (__stdcall * X3D_OdeDynamicGetContactCount)(double object);
double (__stdcall * X3D_OdeDynamicGetContact)(double object, double ind);
double (__stdcall * X3D_OdeStaticGetContactCount)(double object);
double (__stdcall * X3D_OdeStaticGetContact)(double object, double ind);
double (__stdcall * X3D_OdeAddBox)(double object, double width, double height,
                                   double depth);
double (__stdcall * X3D_OdeAddCapsule)(double object, double length,
                                       double radius);
double (__stdcall * X3D_OdeAddCone)(double object, double length,
                                    double radius);
double (__stdcall * X3D_OdeAddCylinder)(double object, double length,
                                        double radius);
double (__stdcall * X3D_OdeAddPlane)(double object);
double (__stdcall * X3D_OdeAddSphere)(double object, double radius);
double (__stdcall * X3D_OdeAddTriMesh)(double object);
double (__stdcall * X3D_OdeSurfaceSetRollingFrictionCoeff)(double body,
                                                           double rfc);
double (__stdcall * X3D_OdeSurfaceEnableRollingFrictionCoeff)(double body,
                                                              double mode);
double (__stdcall * X3D_OdeSurfaceSetMode)(double body, double Mu2,
                                           double FDir1, double Bounce,
                                           double SoftERP, double SoftCFM,
                                           double Motion1, double Motion2,
                                           double Slip1, double Slip2);
double (__stdcall * X3D_OdeSurfaceSetMu)(double body, double mu);
double (__stdcall * X3D_OdeSurfaceSetMu2)(double body, double mu2);
double (__stdcall * X3D_OdeSurfaceSetBounce)(double body, double bounce);
double (__stdcall * X3D_OdeSurfaceSetBounceVel)(double body, double vel);
double (__stdcall * X3D_OdeSurfaceSetSoftERP)(double body, double erp);
double (__stdcall * X3D_OdeSurfaceSetSoftCFM)(double body, double cfm);
double (__stdcall * X3D_OdeSurfaceSetMotion1)(double body, double motion1);
double (__stdcall * X3D_OdeSurfaceSetMotion2)(double body, double motion2);
double (__stdcall * X3D_OdeSurfaceSetSlip1)(double body, double slip1);
double (__stdcall * X3D_OdeSurfaceSetSlip2)(double body, double slip2);
double (__stdcall * X3D_OdeAddJointBall)(void);
double (__stdcall * X3D_OdeAddJointFixed)(void);
double (__stdcall * X3D_OdeAddJointHinge)(void);
double (__stdcall * X3D_OdeAddJointHinge2)(void);
double (__stdcall * X3D_OdeAddJointSlider)(void);
double (__stdcall * X3D_OdeAddJointUniversal)(void);
double (__stdcall * X3D_OdeJointSetObjects)(double joint, double object1,
                                            double object2);
double (__stdcall * X3D_OdeJointEnable)(double joint, double mode);
double (__stdcall * X3D_OdeJointInitialize)(double joint, double mode);
double (__stdcall * X3D_OdeJointSetAnchor)(double joint, double x, double y,
                                           double z);
double (__stdcall * X3D_OdeJointSetAnchorAtObject)(double joint, double object);
double (__stdcall * X3D_OdeJointSetAxis1)(double joint, double x, double y,
                                          double z);
double (__stdcall * X3D_OdeJointSetAxis2)(double joint, double x, double y,
                                          double z);
double (__stdcall * X3D_OdeJointSetBounce)(double joint, double axis,
                                           double bounce);
double (__stdcall * X3D_OdeJointSetCFM)(double joint, double axis, double cfm);
double (__stdcall * X3D_OdeJointSetFMax)(double joint, double axis,
                                         double fmax);
double (__stdcall * X3D_OdeJointSetFudgeFactor)(double joint, double axis,
                                                double fmax);
double (__stdcall * X3D_OdeJointSetHiStop)(double joint, double axis,
                                           double histop);
double (__stdcall * X3D_OdeJointSetLoStop)(double joint, double axis,
                                           double lostop);
double (__stdcall * X3D_OdeJointSetStopCFM)(double joint, double axis,
                                            double cfm);
double (__stdcall * X3D_OdeJointSetStopERP)(double joint, double axis,
                                            double erp);
double (__stdcall * X3D_OdeJointSetVel)(double joint, double axis,
                                        double velocity);

#endif
