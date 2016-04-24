#ifndef X3D_ACTOR_H
#define X3D_ACTOR_H

double (__stdcall * X3D_ActorCreate)(char *filename, double parent);
double (__stdcall * X3D_ActorCopy)(double actor, double parent);
double (__stdcall * X3D_ActorSetAnimationRange)(double actor, double start, double end);
double (__stdcall * X3D_ActorGetCurrentFrame)(double actor);
double (__stdcall * X3D_ActorSwitchToAnimation)(double actor, double anim);
double (__stdcall * X3D_ActorSynchronize)(double actor1, double actor2);
double (__stdcall * X3D_ActorSetInterval)(double actor, double interval);
double (__stdcall * X3D_ActorSetAnimationMode)(double actor, double aam);
double (__stdcall * X3D_ActorSetFrameInterpolation)(double actor, double mode);
double (__stdcall * X3D_ActorAddObject)(double cator, char *filename);
char * (__stdcall * X3D_ActorGetCurrentAnimation)(double actor);
double (__stdcall * X3D_ActorGetFrameCount)(double actor);
double (__stdcall * X3D_ActorGetBoneCount)(double actor);
double (__stdcall * X3D_ActorGetBoneByName)(double actor, char *bonename);
double (__stdcall * X3D_ActorRotateBone)(double actor, double boneindex, double x, double y, double z);
double (__stdcall * X3D_ObjectClueToBone)(double object, double actor, double boneindex);
double (__stdcall * X3D_ActorGetBoneRotation)(double actor, double boneindex, double index);
double (__stdcall * X3D_ActorMoveBone)(double actor, double boneindex, double x, double y, double z);
double (__stdcall * X3D_ActorGetBonePosition)(double actor, double boneindex, double index);
double (__stdcall * X3D_ActorShowSkeleton)(double actor, double mode);

#endif