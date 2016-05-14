#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Raycasting Demo");
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
    
	X3D_MaterialCreate("logo","xception/raycasting/logo.tga",1);
	X3D_MaterialSetOptions("logo",1,1);
	X3D_MaterialSetTextureImageAlpha("logo",X3D_TIA_DEFAULT);
	double logo=X3D_HUDSpriteCreate("logo",192,96,front);
	X3D_ObjectSetPosition(logo,800-192/2,600-96/2,0);
	
    double light = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light,5,30,5);
	X3D_LightSetDiffuseColor(light,RGB(255,128,0));
    
    double all_targets=X3D_DummycubeCreate(scene);
	double shadow_caster=X3D_DummycubeCreate(all_targets);

	double plane=X3D_ShadowplaneCreate(150,150,5,5,shadow_caster,light,X3D_C_BLACK, 0.3,scene);
	X3D_MaterialCreate("plane_tex","", 0);
	X3D_MaterialSetOptions("plane_tex",1,1);
	X3D_MaterialSetDiffuseColor("plane_tex",(double)0xC0C0C0,1);
	X3D_ObjectSetMaterial(plane,"plane_tex");
	X3D_ObjectSetPosition(plane,0,0,0);
	X3D_ObjectSetDirection(plane,0,1,0);

	X3D_MaterialCreate("red_tex","", 0);
	X3D_MaterialSetDiffuseColor("red_tex",(double)0x0000FF,1);
	X3D_MaterialCreate("green_tex","", 0);
	X3D_MaterialSetDiffuseColor("green_tex",(double)0x00FF00,1);
	X3D_MaterialCreate("black_tex","", 0);
	X3D_MaterialSetDiffuseColor("black_tex",(double)0x000000,1);

	double can_raycast=1;
	double result=0;
	int i;
	double target[10];
	time_t t;
	srand((unsigned)time(&t));
	int health_pts[10];
	int destroyed[10];
	for (i=0; i<10; i+=1)
	{
		target[i]=X3D_FreeformCreate("xception/raycasting/mesh.3ds",shadow_caster);
		X3D_ObjectShow(target[i]);
		X3D_ObjectSetMaterial(target[i],"red_tex");
		X3D_ObjectSetPosition(target[i],rand()%100-50,0,rand()%100-50);
		health_pts[(int)X3D_ObjectGetIndex(target[i])]=1;
		destroyed[(int)X3D_ObjectGetIndex(target[i])]=0;
	}
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,14,40);
    
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,5000);
    X3D_ViewerSetCamera(view1,camera);
	double Shooter=X3D_DummycubeCreate(camera);
	X3D_ObjectSetPosition(Shooter,0,-2,0);
	X3D_ObjectShowAxes(Shooter,1);
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
	double text_index=X3D_HUDTextCreate(font,"Intersect Index: ",front);
	X3D_TextSetColor(text_index,X3D_C_RED,0.6);
	X3D_ObjectSetPosition(text_index,16,24,0);
	double text_hpts=X3D_HUDTextCreate(font,"Intersect hpts: ",front);
	X3D_TextSetColor(text_hpts,X3D_C_RED,0.6);
	X3D_ObjectSetPosition(text_hpts,16,40,0);
    
    double deltax = 0;
    double deltay = 1;
    double pit = 0;
    double mx = 320;
    double my = 240;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];
	static char index[256];
	static char hpts[256];

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -0.5);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   0.5);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 0.5);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-0.5);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		for (i=0; i<10; i+=1)
		{
			if (destroyed[(int)X3D_ObjectGetIndex(target[i])]==1)
			{
				X3D_MeshExplode(target[i],0.6,1,0,0,0);
			}
		}

		if (GetKeyState(VK_LBUTTON) & 0x100)
		{
			if (can_raycast)
			{
				can_raycast=0;
				result = X3D_ObjectSceneRaycast(Shooter,all_targets);
				if (result!=0) 
				{
					if ((int)X3D_ObjectIsVisible(result)) //&& result!=plane2 
					{
						health_pts[(int)X3D_ObjectGetIndex(result)]-=1; 
					}
					if (health_pts[(int)X3D_ObjectGetIndex(result)]<=0)
						destroyed[(int)X3D_ObjectGetIndex(result)]=1;
					sprintf(index, "Intersect Index: %.u", (unsigned)X3D_ObjectGetIndex(result));
					X3D_TextSetText(text_index, index);
					sprintf(hpts, "Intersect hpts: %.u", (unsigned)health_pts[(int)X3D_ObjectGetIndex(result)]);
					X3D_TextSetText(text_hpts, hpts);
				}
			}
		}
		else
		{
			can_raycast=1;
		}
		
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
