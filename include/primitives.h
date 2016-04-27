#ifndef X3D_PRIMITIVES_H
#define X3D_PRIMITIVES_H

double (__stdcall * X3D_PlaneCreate)(double singlequad, double width,
                                     double height, double xtiles,
                                     double ytiles, double parent);
double (__stdcall * X3D_CubeCreate)(double width, double height, double depth,
                                    double parent);
double (__stdcall * X3D_CubeSetNormalDirection)(double cube, double nd);
double (__stdcall * X3D_SphereCreate)(double radius, double slices,
                                      double stacks, double parent);
double (__stdcall * X3D_CylinderCreate)(double topradius, double bottomradius,
                                        double height, double slices,
                                        double stacks, double loops,
                                        double parent);
double (__stdcall * X3D_ConeCreate)(double bottomradius, double height,
                                    double slices, double stacks, double loops,
                                    double parent);
double (__stdcall * X3D_AnnulusCreate)(double innerradius, double outerradius,
                                       double height, double slices,
                                       double stacks, double loops,
                                       double parent);
double (__stdcall * X3D_TorusCreate)(double outerradius, double innerradius,
                                     double rings, double sides, double parent);
double (__stdcall * X3D_DiskCreate)(double innerradius, double outerradius,
                                    double startangle, double sweepangle,
                                    double loops, double slices, double parent);
#endif
