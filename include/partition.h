#ifndef X3D_PARTITION_H
#define X3D_PARTITION_H

double (__stdcall * X3D_OctreeCreate)(double maxdepth, double leafthreshold,
                                      double growgravy, double culling);
double (__stdcall * X3D_QuadtreeCreate)(double maxdepth, double leafthreshold,
                                        double growgravy, double culling);
double (__stdcall * X3D_PartitionDestroy)(double tree);
double (__stdcall * X3D_PartitionAddLeaf)(double tree, double object);
double (__stdcall * X3D_PartitionLeafChanged)(double object);
double (__stdcall * X3D_PartitionQueryFrustrum)(double tree, double viewer);
double (__stdcall * X3D_PartitionQueryLeaf)(double tree, double object);
double (__stdcall * X3D_PartitionQueryAABB)(double tree, double object);
double (__stdcall * X3D_PartitionQueryBSphere)(double tree, double object);
double (__stdcall * X3D_PartitionGetNodeTests)(double tree);
double (__stdcall * X3D_PartitionGetNodeCount)(double tree);
double (__stdcall * X3D_PartitionGetResult)(double tree, double index);
double (__stdcall * X3D_PartitionResultShow)(double tree);
double (__stdcall * X3D_PartitionResultHide)(double tree);

#endif
