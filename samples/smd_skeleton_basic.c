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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D SMD Skeleton Basic Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
	
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,(double)0xC0C0C0);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0);
    double front = X3D_DummycubeCreate(0);
    
	X3D_MaterialCreate("logo","xception/smd_skeleton_basic/logo.tga",1);
	X3D_MaterialSetOptions("logo",1,1);
	X3D_MaterialSetTextureImageAlpha("logo",X3D_TIA_DEFAULT);
	double logo=X3D_HUDSpriteCreate("logo",192,96,front);
	X3D_ObjectSetPosition(logo,640-192/2,480-96/2,0);
	
    double light=X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_ObjectSetPosition(light,5,30,5);
	X3D_LightSetDiffuseColor(light,RGB(255,128,0));
	double light2=X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_ObjectSetPosition(light2,-10,50,-10);
	X3D_LightSetDiffuseColor(light2,RGB(0,128,255));
    
    double shadow_caster=X3D_DummycubeCreate(scene);

	double plane=X3D_ShadowplaneCreate(100,100,5,5,shadow_caster,light,X3D_C_BLACK, 0.6,scene);
	X3D_MaterialCreate("plane_tex","", 0);
	X3D_MaterialSetOptions("plane_tex",1,1);
	X3D_MaterialSetAmbientColor("plane_tex",(double)0x000000,1);
	X3D_MaterialSetDiffuseColor("plane_tex",(double)0xC0C0C0,1);
	X3D_ObjectSetMaterial(plane,"plane_tex");
	X3D_ObjectSetPosition(plane,0,0,0);
	X3D_ObjectSetDirection(plane,0,1,0);

	double actor_dummy=X3D_DummycubeCreate(scene);
	X3D_ObjectShowAxes(actor_dummy,0);
	X3D_ObjectSetPosition(actor_dummy,0,10,0);
	double actor=X3D_ActorCreate("xception/smd_skeleton_basic/test_mesh.smd",actor_dummy);
	X3D_ObjectShowAxes(actor,1);
	X3D_ActorShowSkeleton(actor,1);
	X3D_ObjectSetScale(actor,3,3,3);
	X3D_ObjectRotate(actor,90,0,0);
	X3D_ActorAddObject(actor,"xception/smd_skeleton_basic/test_main.smd");
	X3D_ActorSwitchToAnimation(actor,1);
	double bBottom=X3D_ActorGetBoneByName(actor,"bBottom");
	double bMiddle=X3D_ActorGetBoneByName(actor,"bMiddle");
	double bTop=X3D_ActorGetBoneByName(actor,"bTop");

	X3D_MaterialCreate("mCube","", 0);
	X3D_MaterialSetDiffuseColor("mCube",(double)0x333333,1);
	double cube0=X3D_CubeCreate(1,1,1,actor); 
	X3D_ObjectSetMaterial(cube0,"mCube");
	double cube1=X3D_SphereCreate(0.6,16,16,cube0); 
	X3D_ObjectSetMaterial(cube1,"mCube");
	double cube2=X3D_DummycubeCreate(cube1);
	double cube2_cyl=X3D_CylinderCreate(0.6,0.6,1,16,4,1,cube2); 
	X3D_ObjectSetMaterial(cube2_cyl,"mCube");
	X3D_ObjectSetPosition(cube2_cyl,0,0,-0.15);
	X3D_ObjectRotate(cube2_cyl,90,0,0);

	X3D_ObjectSetPosition(cube0,
	 X3D_ActorGetBonePosition(actor,bBottom,0),
	 X3D_ActorGetBonePosition(actor,bBottom,1),
	 X3D_ActorGetBonePosition(actor,bBottom,2));

	X3D_ObjectSetPosition(cube1,
	 X3D_ActorGetBonePosition(actor,bMiddle,0),
	 X3D_ActorGetBonePosition(actor,bMiddle,1),
	 X3D_ActorGetBonePosition(actor,bMiddle,2));

	X3D_ObjectSetPosition(cube2,
	 X3D_ActorGetBonePosition(actor,bTop,0),
	 X3D_ActorGetBonePosition(actor,bTop,1),
	 X3D_ActorGetBonePosition(actor,bTop,2));
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,20,40);
    
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
		
		X3D_ObjectClueToBone(cube0,actor,bBottom);
		X3D_ObjectClueToBone(cube1,actor,bMiddle);
		X3D_ObjectClueToBone(cube2,actor,bTop);
		
		if (GetKeyState(VK_UP)    & 0x80) X3D_ActorRotateBone(actor,bMiddle, 0.05,0, 0);
		if (GetKeyState(VK_DOWN)  & 0x80) X3D_ActorRotateBone(actor,bMiddle,-0.05,0, 0);
		if (GetKeyState(VK_LEFT)  & 0x80) X3D_ActorRotateBone(actor,bMiddle, 0,   0, 0.1);
		if (GetKeyState(VK_RIGHT) & 0x80) X3D_ActorRotateBone(actor,bMiddle, 0,   0,-0.1);
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
