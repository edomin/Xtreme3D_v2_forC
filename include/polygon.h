#ifndef X3D_POLYGON_H
#define X3D_POLYGON_H

double (__stdcall * X3D_PolygonCreate)(double parent);
double (__stdcall * X3D_PolygonAddVertex)(double polygon, double x, double y,
                                          double z);
double (__stdcall * X3D_PolygonSetVertexPosition)(double polygon, double vertex,
                                                  double x, double y, double z);
double (__stdcall * X3D_PolygonDeleteVertex)(double polygon, double vertex);

#endif
