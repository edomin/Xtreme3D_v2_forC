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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Parallax Mapping Demo");
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
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
	X3D_MaterialCreate("logo","xception/parallax_mapping/logo.tga",1);
	X3D_MaterialSetOptions("logo",1,1);
	X3D_MaterialSetTextureImageAlpha("logo",X3D_TIA_DEFAULT);
	double logo=X3D_HUDSpriteCreate("logo",192,96,front);
	X3D_ObjectSetPosition(logo,640-192/2,480-96/2,0);
	
    double light = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light,5,10,5);
	X3D_LightSetAmbientColor(light,X3D_C_BLUE);
	X3D_LightSetDiffuseColor(light,X3D_C_YELLOW);
    
    X3D_MaterialCreate("plane_tex","xception/parallax_mapping/texture.tga",1);
	X3D_MaterialSetOptions("plane_tex",0,1);
	X3D_MaterialSetTextureImageAlpha("plane_tex",X3D_TIA_DEFAULT);
	X3D_MaterialCreate("plane_tex2","xception/parallax_mapping/spec.png",1);
	X3D_MaterialSetBlendingMode("plane_tex2",X3D_BM_ADDITIVE);
	//X3D_MaterialSetAmbientColor("plane_tex2",X3D_C_BLUE,1);
	X3D_MaterialSetDiffuseColor("plane_tex2",X3D_C_YELLOW,1);
	X3D_MaterialCreate("plane_tex3","xception/parallax_mapping/texture.png", 0);
	X3D_MaterialSetOptions("plane_tex3",0,1);

	double plane[5];
	int i;
	
	for (i=0; i<5; i++)
	{
		if (i<4) 
			plane[i]=X3D_PlaneCreate(1,1000,1000,25,25,scene);
		else 
			plane[i]=X3D_PlaneCreate(0,1000,1000,25,25,scene);
		if (i<4) 
			X3D_ObjectSetMaterial(plane[i],"plane_tex");
		if (i==0) 
			X3D_ObjectSetMaterial(plane[i],"plane_tex3");
		if (i==4) 
			X3D_ObjectSetMaterial(plane[i],"plane_tex2");
		X3D_ObjectSetPosition(plane[i],0,((double)i)/5,0);
		X3D_ObjectSetDirection(plane[i],0,1,0);
	}
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,15,40);
    
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,5000);
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
