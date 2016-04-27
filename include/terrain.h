#ifndef X3D_TERRAIN_H
#define X3D_TERRAIN_H

double (__stdcall * X3D_BmpHDSCreate)(char *name);
double (__stdcall * X3D_BmpHDSSetInfiniteWarp)(double bmp, double mode);
double (__stdcall * X3D_BmpHDSSetInverted)(double bmp, double mode);
double (__stdcall * X3D_TerrainCreate)(double parent);
double (__stdcall * X3D_TerrainSetHeightData)(double terrain,
                                              double heightData);
double (__stdcall * X3D_TerrainSetTileSize)(double terrain, double size);
double (__stdcall * X3D_TerrainSetTilesPerTexture)(double terrain,
                                                   double tiles);
double (__stdcall * X3D_TerrainSetQualityDistance)(double terrain,
                                                   double distance);
double (__stdcall * X3D_TerrainSetQualityStyle)(double terrain, double style);
double (__stdcall * X3D_TerrainSetMaxCLodTriangles)(double terrain,
                                                    double triangles);
double (__stdcall * X3D_TerrainSetCLodPrecision)(double terrain,
                                                 double precision);
double (__stdcall * X3D_TerrainSetOcclusionFrameSkip)(double terrain,
                                                      double frameskip);
double (__stdcall * X3D_TerrainSetOcclusionTesselate)(double terrain,
                                                      double tes);
double (__stdcall * X3D_TerrainGetHeightAtObjectPosition)(double terrain,
                                                          double obj);
double (__stdcall * X3D_TerrainGetLastTriCount)(double terrain);

#endif
