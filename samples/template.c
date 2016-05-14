#include <stdio.h>
#include <windows.h>
#include "xtreme3d.h"

int main(int argc, char **argv)
{
    HWND hwnd;
	int s_width = 640;
    int s_height = 480;
	BOOL app_quit = FALSE;
	/* Xtreme3D functions */  
	X3D_Init();	
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_WHITE);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_WHITE);
    X3D_ViewerSetFogDistance(view1,100,500);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    double back = X3D_DummycubeCreate(0);
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light,5,40,5);
    
    X3D_MaterialCreate("mGround","media/ground.jpg",0);
        
    double shadows = X3D_DummycubeCreate(scene);
    double sp = X3D_ShadowplaneCreate(64,64, 8,8, shadows, light, X3D_C_BLACK, 0.6, scene);
    X3D_ObjectSetMaterial(sp,"mGround");
    X3D_ObjectPitch(sp,90);
    
    double cube = X3D_CubeCreate(5,5,5,shadows);
    X3D_ObjectSetPosition(cube,0,2.5,-5);
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,15,40);
    
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,500);
    X3D_CameraSetFocal(camera,120);
    X3D_CameraSetSceneScale(camera,0.5);
    X3D_ViewerSetCamera(view1,camera); 
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
    
    double deltax = 0;
    double deltay = 1;
    double pit = 0;
    double mx = 320;
    double my = 240;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		if (GetKeyState(VK_SPACE) & 0x80) X3D_ObjectRotate(cube,2,2,0);
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -0.5);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   0.5);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 0.5);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-0.5);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) X3D_ObjectRotate(camera,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_Update();
		X3D_ViewerRender(view1);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(60));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();
	
	return 0;
}
