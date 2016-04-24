#ifndef X3D_B3D_H
#define X3D_B3D_H

double (__stdcall * X3D_LoadB3D)(char *filename, double parent);
double (__stdcall * X3D_ClearZones)(void);
double (__stdcall * X3D_ZonesVisible)(void);
double (__stdcall * X3D_CullZones)(double zone, double obj);
double (__stdcall * X3D_ZoneAddPortal)(double dc, double portal);
double (__stdcall * X3D_ZoneObjectInZone)(double dc, double obj);
double (__stdcall * X3D_ZoneGetCurrent)(double obj);
double (__stdcall * X3D_ZoneGetNew)(double dc, double obj);
double (__stdcall * X3D_ZoneAdjustSize)(double obj);
double (__stdcall * X3D_CreateZones)(double parent, double clear);
double (__stdcall * X3D_ZoneGetPortalCount)(double zone);
double (__stdcall * X3D_ZoneGetPortal)(double zone, double ind);

#endif