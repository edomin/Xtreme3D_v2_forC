#ifndef X3D_TREE_H
#define X3D_TREE_H

double (__stdcall * X3D_TreeCreate)(double parent);
double (__stdcall * X3D_TreeSetMaterials)(double tree, char *mleaf, char *mback,
                                          char *mbranch);
double (__stdcall * X3D_TreeSetBranchFacets)(double tree, double facets);
double (__stdcall * X3D_TreeBuildMesh)(double tree, double parent);
double (__stdcall * X3D_TreeSetBranchNoise)(double tree, double bnoise);
double (__stdcall * X3D_TreeSetBranchAngle)(double tree, double angle);
double (__stdcall * X3D_TreeSetBranchSize)(double tree, double size);
double (__stdcall * X3D_TreeSetBranchRadius)(double tree, double radius);
double (__stdcall * X3D_TreeSetBranchTwist)(double tree, double twist);
double (__stdcall * X3D_TreeSetDepth)(double tree, double depth);
double (__stdcall * X3D_TreeSetLeafSize)(double tree, double size);
double (__stdcall * X3D_TreeSetLeafThreshold)(double tree, double treeshold);
double (__stdcall * X3D_TreeSetSeed)(double tree, double seed);

#endif
