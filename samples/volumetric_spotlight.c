#include <stdio.h>
#include <windows.h>
#include "xtreme3d.h"

int main(int argc, char **argv)
{
    HWND hwnd;
	int s_width = 800;
    int s_height = 600;
	BOOL app_quit = FALSE;
	/* Xtreme3D functions */  
	X3D_Init();	
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Volumetric Spotlight Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_BLACK);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_BLACK);
    X3D_ViewerSetFogDistance(view1,100,500);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light = X3D_DummycubeCreate(0);
    X3D_ObjectSetPosition(light,0,25,0);
	double lightpos=X3D_DummycubeCreate(light);
	double cyl=X3D_CylinderCreate(0.2,0.8,3,16,4,1,lightpos);
	X3D_ObjectRotate(cyl,-90,0,0);
	double light_omni=X3D_LightCreate(X3D_LS_OMNI,lightpos);
	X3D_LightSetAttenuation(light_omni,1,0.1,0);
	X3D_LightSetDiffuseColor(light_omni,RGB(253,252,159));
	X3D_ObjectSetPosition(light_omni,0,0,-20);
	double light_target=X3D_DummycubeCreate(light);
	X3D_ObjectSetPosition(light_target,0,30,50);
    
    X3D_MaterialCreate("slight","xception/volumetric_spotlight/light.jpg", 0);
	X3D_MaterialSetBlendingMode("slight",X3D_BM_ADDITIVE);
	X3D_MaterialSetOptions("slight",0,1);
	double n=16.0;
	double i;
	double sprite1;
	for (i=1; i<n; i+=1)
	{
		sprite1=X3D_SpriteCreate("slight",i/2,i/2,lightpos); 
		X3D_SpriteNoZWrite(sprite1,1); 
		X3D_ObjectSetPosition(sprite1,0,0,-0.5-i/2); 
		X3D_ObjectUseObjectColor(sprite1,1); 
		X3D_ObjectSetDiffuseColor(sprite1,X3D_C_WHITE,(n/i)/n);
	}

	double shadow_caster=X3D_DummycubeCreate(scene);

	double plane=X3D_ShadowplaneCreate(1000,1000,50,50,shadow_caster,light_omni,X3D_C_BLACK, 0.6,scene);
	X3D_MaterialCreate("plane_tex","xception/volumetric_spotlight/ground.jpg", 0);
	X3D_ObjectSetMaterial(plane,"plane_tex");
	X3D_ObjectSetPosition(plane,0,0,0);
	X3D_ObjectSetDirection(plane,0,1,0);

	X3D_MaterialCreate("crate_tex","xception/volumetric_spotlight/crate.jpg", 0);
	double cube1=X3D_CubeCreate(10,10,10,shadow_caster);
	X3D_ObjectSetPosition(cube1,20,5,-20);
	X3D_ObjectSetMaterial(cube1,"crate_tex");
	double cube2=X3D_CubeCreate(10,10,10,shadow_caster);
	X3D_ObjectSetPosition(cube2,-20,5,-20);
	X3D_ObjectSetMaterial(cube2,"crate_tex");
	double cube3=X3D_CubeCreate(10,10,10,shadow_caster);
	X3D_ObjectSetPosition(cube3,20,5,20);
	X3D_ObjectSetMaterial(cube3,"crate_tex");
	double cube4=X3D_CubeCreate(10,10,10,shadow_caster);
	X3D_ObjectSetPosition(cube4,-20,5,20);
	X3D_ObjectSetMaterial(cube4,"crate_tex");

	double camPos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(camPos,0,20,40);

	double camera=X3D_CameraCreate(camPos);
	X3D_CameraSetViewDepth(camera,5000);
	X3D_ViewerSetCamera(view1,camera);
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
    
    double deltax = 0;
    double deltay = 1;
    double pit = 0;
    double mx = 400;
    double my = 300;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		
		X3D_ObjectPointToObject(lightpos,light_target);
		X3D_ObjectMoveObjectAround(light_target,lightpos,0,1);
		
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -2);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   2);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 1);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-1);
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
