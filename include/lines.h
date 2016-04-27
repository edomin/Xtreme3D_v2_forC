#ifndef X3D_LINES_H
#define X3D_LINES_H

double (__stdcall * X3D_LinesCreate)(double parent);
double (__stdcall * X3D_LinesAddNode)(double line, double x, double y,
                                      double z);
double (__stdcall * X3D_LinesDeleteNode)(double line, double ind);
double (__stdcall * X3D_LinesSetColors)(double line, double linecolor,
                                        double linealpha, double nodecolor,
                                        double nodealpha);
double (__stdcall * X3D_LinesSetSize)(double line, double linewidth,
                                      double nodesize);
double (__stdcall * X3D_LinesSetSplineMode)(double line, double lsm);
double (__stdcall * X3D_LinesSetNodesAspect)(double line, double lna);
double (__stdcall * X3D_LinesSetDivision)(double line, double division);

#endif
