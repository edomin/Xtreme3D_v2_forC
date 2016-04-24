#ifndef X3D_MATERIAL_H
#define X3D_MATERIAL_H

double (__stdcall * X3D_MaterialLibraryCreate)(void);
double (__stdcall * X3D_MaterialLibraryActivate)(double matlib);
double (__stdcall * X3D_MaterialLibrarySetTexturePaths)(double matlib, char *path);
double (__stdcall * X3D_MaterialLibraryClear)(double matlib);
double (__stdcall * X3D_MaterialLibraryDeleteUnused)(double matlib);
double (__stdcall * X3D_MaterialCreate)(char *material, char *filename, double mode);
double (__stdcall * X3D_MaterialAddCubeMap)(char *material);
double (__stdcall * X3D_MaterialCubeMapLoadImage)(char *material, char *texture);
double (__stdcall * X3D_MaterialCubeMapFromScene)(char *material, double camera, double res);
double (__stdcall * X3D_MaterialSetAmbientColor)(char *material, double color, double alpha);
double (__stdcall * X3D_MaterialSetDiffuseColor)(char *material, double color, double alpha);
double (__stdcall * X3D_MaterialSetEmissionColor)(char *material, double color, double alpha);
double (__stdcall * X3D_MaterialSetSpecularColor)(char *material, double color, double alpha);
double (__stdcall * X3D_MaterialSetShininess)(char *material, double shininess);
double (__stdcall * X3D_MaterialSetPolygonMode)(char *material, double pm);
double (__stdcall * X3D_MaterialSetTextureMappingMode)(char *material, double tmm);
double (__stdcall * X3D_MaterialSetTextureImageAlpha)(char *material, double tia);
double (__stdcall * X3D_MaterialSetTextureScale)(char *material, double u, double v);
double (__stdcall * X3D_MaterialGetFromLib)(char *material1, char *material2);
double (__stdcall * X3D_MaterialSetTextureOffset)(char *material, double u, double v);
double (__stdcall * X3D_MaterialSetTextureMode)(char *material, double tm);
double (__stdcall * X3D_MaterialSetBlendingMode)(char *material, double bm);
double (__stdcall * X3D_MaterialSetTextureFilter)(char *material, double mi, double ma);
double (__stdcall * X3D_MaterialDisableTexture)(char *material, double mode);
double (__stdcall * X3D_MaterialLoadTexture)(char *material, char *filename);
double (__stdcall * X3D_MaterialGetCount)(void);
char * (__stdcall * X3D_MaterialGetName)(double ind);
double (__stdcall * X3D_MaterialSetFaceCulling)(char *material, double fc);
double (__stdcall * X3D_MaterialSetSecondTexture)(char *material1, char *material2);
double (__stdcall * X3D_MaterialSetTextureFormat)(char *material, double tf);
double (__stdcall * X3D_MaterialSetTextureCompression)(char *material, double tc);
double (__stdcall * X3D_MaterialTextureRequiredMemory)(char *material);
double (__stdcall * X3D_MaterialSetFilteringQuality)(char *material, double tf);
double (__stdcall * X3D_MaterialSetOptions)(char *material, double fog, double lighting);
double (__stdcall * X3D_MaterialSetShader)(char *material, double shader);
double (__stdcall * X3D_MaterialAddTextureEx)(char *material, char *texture);
double (__stdcall * X3D_MaterialTextureExClear)(char *material);
double (__stdcall * X3D_MaterialTextureExDelete)(char *material, double ind);

#endif