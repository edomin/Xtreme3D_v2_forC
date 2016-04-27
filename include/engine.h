#ifndef X3D_ENGINE_H
#define X3D_ENGINE_H

double (__stdcall * X3D_EngineCreate)(double window_h);
double (__stdcall * X3D_EngineDestroy)(void);
double (__stdcall * X3D_EngineSetObjectsSorting)(double os);
double (__stdcall * X3D_EngineSetCulling)(double vc);
double (__stdcall * X3D_EngineGetMaxTextureSize)(void);
double (__stdcall * X3D_EngineGetMaxTextureUnits)(void);
double (__stdcall * X3D_SetPakArchive)(char *filename);
double (__stdcall * X3D_Update)(void);
double (__stdcall * X3D_TrisRendered)(void);

#endif
