#ifndef X3D_TRAIL_H
#define X3D_TRAIL_H

double (__stdcall * X3D_TrailCreate)(double bso, double parent);
double (__stdcall * X3D_TrailSetObject)(double obj, double tobject);
double (__stdcall * X3D_TrailSetAlpha)(double obj, double alpha, double fade);
double (__stdcall * X3D_TrailSetLimits)(double obj, double vl, double tl);
double (__stdcall * X3D_TrailSetMinDistance)(double obj, double md);
double (__stdcall * X3D_TrailSetUVScale)(double obj, double uv);
double (__stdcall * X3D_TrailSetMarkStyle)(double obj, double ms);
double (__stdcall * X3D_TrailSetMarkWidth)(double obj, double mv);
double (__stdcall * X3D_TrailSetEnabled)(double obj, double mode);
double (__stdcall * X3D_TrailClearMarks)(double obj);

#endif
