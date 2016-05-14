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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Water Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,RGB(203,204,204));
    X3D_ViewerSetFogDistance(view1,200,800);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    double back = X3D_DummycubeCreate(0);
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
	double lightpos = X3D_DummycubeCreate(0);
	X3D_ObjectSetPosition(lightpos, 0, 20, 20);
    double light = X3D_LightCreate(X3D_LS_PARALLEL, lightpos);
    X3D_LightSetAmbientColor(light, X3D_C_WHITE);
    
    double arch1=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(arch1,0,0,60);
	double block1_1=X3D_CubeCreate(10,40,10,arch1);
	X3D_ObjectSetPosition(block1_1,40,20,0);
	double block1_2=X3D_CubeCreate(10,40,10,arch1);
	X3D_ObjectSetPosition(block1_2,-40,20,0);
	double block1_3=X3D_CubeCreate(90,10,10,arch1);
	X3D_ObjectSetPosition(block1_3,0,45,0);

	double arch2=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(arch2,0,0,-60);
	X3D_ObjectRotate(arch2,0,45,0);
	double block2_1=X3D_CubeCreate(10,40,10,arch2);
	X3D_ObjectSetPosition(block2_1,40,20,0);
	double block2_2=X3D_CubeCreate(10,40,10,arch2);
	X3D_ObjectSetPosition(block2_2,-40,20,0);
	double block2_3=X3D_CubeCreate(90,10,10,arch2);
	X3D_ObjectSetPosition(block2_3,0,45,0);

	double sphere=X3D_SphereCreate(15,24,24,scene);
	X3D_ObjectSetPosition(sphere,30,15,10);

	double plane=X3D_PlaneCreate(0,1000,1000,10,10,scene);
	X3D_MaterialCreate("plane_tex","xception/water/sand.jpg", 0);
	X3D_MaterialSetOptions("plane_tex",0,1);
	X3D_ObjectSetMaterial(plane,"plane_tex");
	X3D_ObjectSetPosition(plane,0,0,0);
	X3D_ObjectSetDirection(plane,0,1,0);

	X3D_MaterialCreate("skyTop","xception/water/sky_top.jpg", 0);
	X3D_MaterialCreate("skyBottom","xception/water/sky_bottom.jpg", 0);
	X3D_MaterialCreate("skyLeft","xception/water/sky_left.jpg", 0);
	X3D_MaterialCreate("skyRight","xception/water/sky_right.jpg", 0);
	X3D_MaterialCreate("skyFront","xception/water/sky_front.jpg", 0);
	X3D_MaterialCreate("skyBack","xception/water/sky_back.jpg", 0);
	double sky=X3D_SkyboxCreate(back);
	X3D_SkyboxSetMaterial(sky,0,"skyTop");
	X3D_SkyboxSetMaterial(sky,1,"skyBottom");
	X3D_SkyboxSetMaterial(sky,2,"skyLeft");
	X3D_SkyboxSetMaterial(sky,3,"skyRight");
	X3D_SkyboxSetMaterial(sky,4,"skyFront");
	X3D_SkyboxSetMaterial(sky,5,"skyBack");
    
	X3D_MaterialAddCubeMap("mcube");
	X3D_MaterialSetBlendingMode("mcube",X3D_BM_TRANSPARENCY);
	X3D_MaterialSetDiffuseColor("mcube",X3D_C_BLUE,0.75);

	double water=X3D_WaterCreate(scene);
	X3D_WaterSetResolution(water,128); 
	X3D_WaterSetRainTimeInterval(water,0); 
	X3D_WaterSetRainForce(water,1000);
	X3D_WaterSetViscosity(water,0.95);
	X3D_WaterSetElastic(water,10);
	X3D_ObjectSetPosition(water,0,2.5,0);
	X3D_ObjectSetScale(water,1000,1000,1000);
	X3D_ObjectSetMaterial(water,"mcube");

	X3D_MaterialCreate("mMask","xception/water/watermask.bmp", 0);
	X3D_WaterSetMask(water,"mMask");
	
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,20,0);
    
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,5000);
    X3D_ViewerSetCamera(view1,camera); 
	
	double cm_camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(cm_camera,5000);
    
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

	int water_splash_frame_counter = 0;
	
    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -2);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   1);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 2);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-1);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) X3D_ObjectRotate(camera,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_ObjectRotate(cm_camera,-X3D_ObjectGetPitch(camera),0,0);
		X3D_ObjectSetPosition(cm_camera,0,X3D_ObjectGetPosition(water,1)-X3D_ObjectGetPosition(camPos,1)*2,0);
		
		if (water_splash_frame_counter < 20)
			water_splash_frame_counter++;
		else
		{
			water_splash_frame_counter = 0;
			X3D_WaterCreateRippleAtGridPosition(water,64-8,64-8);
			X3D_WaterCreateRippleAtGridPosition(water,64+8,64+8);
		}
		
		
		X3D_Update();

		X3D_ObjectHide(water);
		X3D_ObjectHide(plane);
		X3D_MaterialCubeMapFromScene("mcube",cm_camera,128);
		X3D_ObjectShow(plane);
		X3D_ObjectShow(water);

		X3D_ViewerRender(view1);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(60));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();
	
	return 0;
}
