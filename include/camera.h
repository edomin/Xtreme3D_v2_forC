#ifndef X3D_CAMERA_H
#define X3D_CAMERA_H

double (__stdcall * X3D_CameraCreate)(double parent);
double (__stdcall * X3D_CameraSetStyle)(double cam, double cs);
double (__stdcall * X3D_CameraSetFocal)(double cam, double fov);
double (__stdcall * X3D_CameraSetSceneScale)(double cam, double scale);
double (__stdcall * X3D_CameraScaleScene)(double cam, double scale);
double (__stdcall * X3D_CameraSetViewDepth)(double cam, double depth);
double (__stdcall * X3D_CameraSetTargetObject)(double cam, double obj);
double (__stdcall * X3D_CameraMoveAroundTarget)(double cam, double pitch,
                                                double turn);
double (__stdcall * X3D_CameraSetDistanceToTarget)(double cam, double distance);
double (__stdcall * X3D_CameraGetDistanceToTarget)(double cam);
double (__stdcall * X3D_CameraCopyToTexture)(double cam, char * material,
                                             double width, double height);

#endif
