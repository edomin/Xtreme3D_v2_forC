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
	double view2 = X3D_ViewerCreate(0,0,512,512);
	
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_BLACK);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_BLACK);
    X3D_ViewerSetFogDistance(view1,50,100);
	
	X3D_ViewerSetLighting(view2,1);
    X3D_ViewerSetBackgroundColor(view2,X3D_C_BLACK);
    X3D_ViewerEnableFog(view2,1);
    X3D_ViewerSetFogColor(view2,X3D_C_BLACK);
    X3D_ViewerSetFogDistance(view2,50,100);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light,10,-100,10);
	X3D_LightSetDiffuseColor(light,RGB(255,0,0));
	double light2 = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light2,-25,100,-100);
	X3D_LightSetDiffuseColor(light2,RGB(0,128,255));
    
    double model=X3D_FreeformCreate("xception/antialiasing/model.3ds",scene);
	X3D_ObjectSetPosition(model,0,0,0);
	X3D_ObjectSetScale(model,0.1,0.1,0.1);
	X3D_ObjectPitch(model,90);

	X3D_MaterialCreate("mskin","xception/antialiasing/tex.jpg", 0);
	X3D_MaterialSetAmbientColor("mskin",X3D_C_WHITE,1);
	X3D_ObjectSetMaterial(model,"mskin");

	X3D_MaterialCreate("mScreen","", 0);
	X3D_MaterialSetTextureFilter("mScreen",1,1);
	X3D_MaterialSetBlendingMode("mScreen",X3D_BM_ADDITIVE);

	double glow0=X3D_DummycubeCreate(front);
	double glow1=X3D_HUDSpriteCreate("mScreen",642,642,glow0);
	X3D_ObjectSetPosition(glow1,640/2,480/2,0);
	double glow2=X3D_HUDSpriteCreate("mScreen",646,646,glow1);
	X3D_ObjectSetPosition(glow2,640/2,480/2,0);
	double glow3=X3D_HUDSpriteCreate("mScreen",650,650,glow2);
	X3D_ObjectSetPosition(glow3,640/2,480/2,0);
	double glow4=X3D_HUDSpriteCreate("mScreen",654,654,glow3);
	X3D_ObjectSetPosition(glow4,640/2,480/2,0);
    
    double camPos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(camPos,0,15,10);
	double camera=X3D_CameraCreate(camPos);
	X3D_ViewerSetCamera(view1,camera);
	double camera2=X3D_CameraCreate(camPos);
	X3D_CameraSetFocal(camera2,40);
	X3D_ViewerSetCamera(view2,camera2); 
    
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
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -0.5);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   0.5);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 0.5);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-0.5);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) 
			X3D_ObjectRotate(camera,deltay,0,0);
		X3D_ObjectRotate(camera2,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_Update();
		X3D_ObjectHide(glow0);
		X3D_ViewerRender(view2);
		X3D_ViewerCopyToTexture(view2,"mScreen");
		X3D_ObjectShow(glow0);
		X3D_ViewerRender(view1);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(60));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();
	
	return 0;
}
