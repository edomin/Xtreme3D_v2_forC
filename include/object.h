#ifndef X3D_OBJECT_H
#define X3D_OBJECT_H

double (__stdcall * X3D_ObjectHide)(double object);
double (__stdcall * X3D_ObjectShow)(double object);
double (__stdcall * X3D_ObjectIsVisible)(double object);
double (__stdcall * X3D_ObjectCopy)(double object, double parent);
double (__stdcall * X3D_ObjectDestroy)(double object);
double (__stdcall * X3D_ObjectSetPosition)(double object, double x, double y,
                                           double z);
double (__stdcall * X3D_ObjectGetPosition)(double object, double ind);
double (__stdcall * X3D_ObjectGetAbsolutePosition)(double object, double ind);
double (__stdcall * X3D_ObjectSetPositionOfObject)(double object1,
                                                   double object2);
double (__stdcall * X3D_ObjectAlignWithObject)(double object1, double object2);
double (__stdcall * X3D_ObjectSetPositionX)(double object, double x);
double (__stdcall * X3D_ObjectSetPositionY)(double object, double y);
double (__stdcall * X3D_ObjectSetPositionZ)(double object, double z);
double (__stdcall * X3D_ObjectSetAbsolutePosition)(double object, double x,
                                                   double y, double z);
double (__stdcall * X3D_ObjectSetDirection)(double object, double x, double y,
                                            double z);
double (__stdcall * X3D_ObjectGetDirection)(double object, double ind);
double (__stdcall * X3D_ObjectSetAbsoluteDirection)(double object, double x,
                                                    double y, double z);
double (__stdcall * X3D_ObjectGetAbsoluteDirection)(double object, double ind);
double (__stdcall * X3D_ObjectGetPitch)(double object);
double (__stdcall * X3D_ObjectGetTurn)(double object);
double (__stdcall * X3D_ObjectGetRoll)(double object);
double (__stdcall * X3D_ObjectSetRotation)(double object, double x, double y,
                                           double z);
double (__stdcall * X3D_ObjectMove)(double object, double speed);
double (__stdcall * X3D_ObjectLift)(double object, double speed);
double (__stdcall * X3D_ObjectTranslate)(double object, double x, double y,
                                         double z);
double (__stdcall * X3D_ObjectStrafe)(double object, double speed);
double (__stdcall * X3D_ObjectRotate)(double object, double x, double y,
                                      double z);
double (__stdcall * X3D_ObjectScale)(double object, double x, double y,
                                     double z);
double (__stdcall * X3D_ObjectSetScale)(double object, double x, double y,
                                        double z);
double (__stdcall * X3D_ObjectSetUpVector)(double object, double x, double y,
                                           double z);
double (__stdcall * X3D_ObjectPointToObject)(double object1, double object2);
double (__stdcall * X3D_ObjectAlignToCamera)(double object, double camera);
double (__stdcall * X3D_ObjectGetAtXY)(double viewer, double x, double y);
double (__stdcall * X3D_ObjectShowAxes)(double object, double mode);
double (__stdcall * X3D_ObjectGetGroundHeight)(double object, double target);
double (__stdcall * X3D_ObjectSceneRaycast)(double object, double target);
double (__stdcall * X3D_ObjectRaycast)(double object, double target);
double (__stdcall * X3D_ObjectGetCollisionPosition)(double ind);
double (__stdcall * X3D_ObjectGetCollisionNormal)(double ind);
double (__stdcall * X3D_ObjectSetDiffuseColor)(double object, double color,
                                               double alpha);
double (__stdcall * X3D_ObjectSetMaterial)(double object, char *material);
double (__stdcall * X3D_ObjectGetDistance)(double object1, double object2);
double (__stdcall * X3D_ObjectCheckCubeVsFace)(double object1, double object2);
double (__stdcall * X3D_ObjectCheckCubeVsCube)(double object1, double object2);
double (__stdcall * X3D_ObjectCheckFaceVsFace)(double object1, double object2);
double (__stdcall * X3D_ObjectCheckSphereVsSphere)(double object1,
                                                   double object2);
double (__stdcall * X3D_ObjectCheckSphereVsCube)(double object1,
                                                 double object2);
double (__stdcall * X3D_ObjectIsPointInObject)(double object, double x,
                                               double y, double z);
double (__stdcall * X3D_ObjectSetCulling)(double object, double mode);
double (__stdcall * X3D_ObjectSetName)(double object, char *name);
char * (__stdcall * X3D_ObjectGetName)(double object);
char * (__stdcall * X3D_ObjectGetClassName)(double object);
double (__stdcall * X3D_ObjectSetID)(double object, double id);
double (__stdcall * X3D_ObjectGetID)(double object);
double (__stdcall * X3D_ObjectGetParent)(double object);
double (__stdcall * X3D_ObjectGetChildCount)(double object);
double (__stdcall * X3D_ObjectGetChild)(double object, double ind);
double (__stdcall * X3D_ObjectGetBoundingsphereRadius)(double object);
double (__stdcall * X3D_ObjectGetIndex)(double object);
double (__stdcall * X3D_ObjectFindChild)(double object, char *name);
double (__stdcall * X3D_ObjectGetAbsoluteUp)(double object, double ind);
double (__stdcall * X3D_ObjectSetAbsoluteUp)(double object, double x, double y,
                                             double z);
double (__stdcall * X3D_ObjectGetAbsoluteRight)(double object, double ind);
double (__stdcall * X3D_ObjectGetAbsoluteXVector)(double object, double ind);
double (__stdcall * X3D_ObjectGetAbsoluteYVector)(double object, double ind);
double (__stdcall * X3D_ObjectGetAbsoluteZVector)(double object, double ind);
double (__stdcall * X3D_ObjectGetRight)(double object, double ind);
double (__stdcall * X3D_ObjectMoveChildUp)(double object, double ind);
double (__stdcall * X3D_ObjectMoveChildDown)(double object, double ind);
double (__stdcall * X3D_ObjectSetParent)(double object, double parent);
double (__stdcall * X3D_ObjectRemoveChild)(double object, double child,
                                           double keep);
double (__stdcall * X3D_ObjectMoveObjectAround)(double object1, double object2,
                                                double x, double y);
double (__stdcall * X3D_ObjectPitch)(double object, double angle);
double (__stdcall * X3D_ObjectTurn)(double object1, double angle);
double (__stdcall * X3D_ObjectRoll)(double object1, double angle);
double (__stdcall * X3D_ObjectGetUpVector)(double object, double ind);
double (__stdcall * X3D_ObjectStructureChanged)(double object);
double (__stdcall * X3D_ObjectRotateAbsolute)(double object, double x, double y,
                                              double z);
double (__stdcall * X3D_ObjectRotateAbsoluteVector)(double object, double x,
                                                    double y, double z,
                                                    double angle);
double (__stdcall * X3D_ObjectInFrustrum)(double object);
double (__stdcall * X3D_ObjectIsClipped)(double object);

#endif
