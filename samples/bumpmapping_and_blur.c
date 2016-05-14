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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Bumpmapping and Blur Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_MAROON);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0);
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    X3D_MaterialCreate("mfloor","xception/bumpmapping_and_blur/Floor.jpg",0);
	
	X3D_MaterialCreate("mtexture","xception/bumpmapping_and_blur/hellknight_color.jpg", 0);
	X3D_MaterialCreate("mnormal","xception/bumpmapping_and_blur/hellknight_normal.jpg", 0);
	X3D_MaterialSetSecondTexture("mnormal","mtexture");
	
	double bump=X3D_BumpShaderCreate(1);
	X3D_MaterialSetShader("mnormal",bump);
    
	double camPos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(camPos,0,10,16);
	double camera=X3D_CameraCreate(camPos);

	X3D_ViewerSetCamera(view1,camera);
       
    double light=X3D_LightCreate(X3D_LS_OMNI,0);
	double light2=X3D_LightCreate(X3D_LS_SPOT,camera);
	X3D_ObjectSetPosition(light,0,20,-10);
	X3D_ObjectSetPosition(light2,0,3,-40);
	X3D_LightSetDiffuseColor(light2,RGB(145,89,69));
	X3D_LightSetAttenuation(light2,2,3,4);

	// double flare=X3D_SpriteCreate("mFlare",4,4,light);
	X3D_SpriteCreate("mFlare",4,4,light);

	double shadows=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(shadows,0,3,0);

	double mesh=X3D_FreeformCreate("xception/bumpmapping_and_blur/hellknight.3ds",shadows);
	X3D_ObjectSetMaterial(mesh,"mnormal");
	X3D_ObjectPitch(mesh,90);
	X3D_ObjectSetScale(mesh,0.1,0.1,0.1);
	X3D_ObjectSetPosition(mesh,0,3.5,0);

	double sp=X3D_ShadowplaneCreate(64,64, 8,8, shadows, light, X3D_C_BLACK, 0.6, scene);
	X3D_ObjectSetMaterial(sp,"mfloor");
	X3D_ObjectSetPosition(sp,0,0.1,0);
	X3D_ObjectPitch(sp,90);
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
	
	double text_blur = X3D_HUDTextCreate(font,"Press 'B' for enable blur and '0' - '5' for choosing blur mode",front);
    X3D_TextSetColor(text_blur,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_blur,16,32,0);
    
	BOOL blur_exists = FALSE;
	double blur;
	
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
		if (GetKeyState('B')      & 0x80)
		{
			if (!blur_exists)
			{
				blur_exists = TRUE;
				blur=X3D_BlurCreate(scene);
				X3D_BlurSetPreset(blur,1);
			}
			else
			{
				blur_exists = FALSE;
				X3D_ObjectDestroy(blur);
			}
		}
		if (GetKeyState('0')      & 0x80) 
			if (blur_exists)
				X3D_BlurSetPreset(blur,X3D_P_NONE);
		if (GetKeyState('1')      & 0x80) 
			if (blur_exists)
				X3D_BlurSetPreset(blur,X3D_P_GLOSSY);
		if (GetKeyState('2')      & 0x80) 
			if (blur_exists)
				X3D_BlurSetPreset(blur,X3D_P_BEAST_VIEW);
		if (GetKeyState('3')      & 0x80) 
			if (blur_exists)
				X3D_BlurSetPreset(blur,X3D_P_OCEAN_DEPTH);
		if (GetKeyState('4')      & 0x80) 
			if (blur_exists)
				X3D_BlurSetPreset(blur,X3D_P_DREAM);
		if (GetKeyState('5')      & 0x80) 
			if (blur_exists)
				X3D_BlurSetPreset(blur,X3D_P_OVER_BLUR);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) X3D_ObjectRotate(camera,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_ObjectMoveObjectAround(light,sp,0,0.5);
		
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
