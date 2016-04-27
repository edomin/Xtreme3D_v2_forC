#include <windows.h>

HWND X3D_WindowCreate(int width, int height, int depth, BOOL fullscreen,
                      char *caption);
int X3D_WindowDestroy(HWND hwnd);
BOOL X3D_WindowXed();
