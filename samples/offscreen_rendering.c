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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Offscreen Rendering Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);
	double view2 = X3D_ViewerCreate(0,0,128,128); 
	
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,(double)0xC0C0C0);
    X3D_ViewerSetLighting(view2,1);
    X3D_ViewerSetBackgroundColor(view2,(double)0xC0C0C0);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
	X3D_MaterialCreate("logo","xception/offscreen_rendering/logo.tga",1);
	X3D_MaterialSetOptions("logo",1,1);
	X3D_MaterialSetTextureImageAlpha("logo",X3D_TIA_DEFAULT);
	double logo=X3D_HUDSpriteCreate("logo",192,96,front);
	X3D_ObjectSetPosition(logo,640-192/2,480-96/2,0);
	
    double light = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light,5,30,5);
    
	double plane=X3D_PlaneCreate(0,300,150,20,10,scene);
	X3D_MaterialCreate("plane_tex","xception/offscreen_rendering/ground.jpg", 0);
	X3D_ObjectSetMaterial(plane,"plane_tex");
	X3D_ObjectSetPosition(plane,75,0,0);
	X3D_ObjectSetDirection(plane,0,1,0);
	double plane2=X3D_PlaneCreate(0,150,150,10,10,scene);
	X3D_MaterialCreate("plane2_tex","xception/offscreen_rendering/grid.bmp", 0);
	X3D_MaterialSetBlendingMode("plane2_tex",X3D_BM_TRANSPARENCY);
	X3D_MaterialSetTextureImageAlpha("plane2_tex",X3D_TIA_SUPER_BLACK_TRANSPARENT);
	X3D_ObjectSetMaterial(plane2,"plane2_tex");
	X3D_ObjectSetPosition(plane2,-36,120,0);
	X3D_ObjectSetDirection(plane2,0,-1,0);
	X3D_ObjectRotate(plane2,0,30,0);
	double plane3=X3D_PlaneCreate(0,150,150,10,10,scene);
	X3D_MaterialCreate("plane3_tex","xception/offscreen_rendering/ceil.jpg", 0);
	X3D_ObjectSetMaterial(plane3,"plane3_tex");
	X3D_ObjectSetPosition(plane3,0,160,0);
	X3D_ObjectSetDirection(plane3,0,-1,0);
	double plane4=X3D_PlaneCreate(0,150,150,10,10,scene);
	X3D_ObjectSetMaterial(plane4,"plane3_tex");
	X3D_ObjectSetPosition(plane4,150,80,0);
	X3D_ObjectSetDirection(plane4,0,-1,0);

	X3D_MaterialCreate("wall1_tex","xception/offscreen_rendering/wall1.jpg", 0);
	double wall1=X3D_PlaneCreate(0,300,160,5,4,scene);
	X3D_ObjectSetPosition(wall1,75,80,-75);
	X3D_ObjectSetMaterial(wall1,"wall1_tex");
	double wall2=X3D_PlaneCreate(0,300,160,5,4,scene);
	X3D_ObjectRotate(wall2,0,180,0);
	X3D_ObjectSetPosition(wall2,75,80,75);
	X3D_ObjectSetMaterial(wall2,"wall1_tex");
	double wall3=X3D_PlaneCreate(0,150,160,5,4,scene);
	X3D_ObjectRotate(wall3,0,90,0);
	X3D_ObjectSetPosition(wall3,-75,80,0);
	X3D_ObjectSetMaterial(wall3,"wall1_tex");
	double wall4=X3D_PlaneCreate(0,150,80,5,2,scene);
	X3D_ObjectRotate(wall4,0,-90,0);
	X3D_ObjectSetPosition(wall4,75,120,0);
	X3D_ObjectSetMaterial(wall4,"wall1_tex");
	double wall5=X3D_PlaneCreate(0,150,80,5,3,scene);
	X3D_ObjectRotate(wall5,0,-90,0);
	X3D_ObjectSetPosition(wall5,300-75,40,0);
	X3D_ObjectSetMaterial(wall5,"plane2_tex");

	X3D_MaterialCreate("box_tex","xception/offscreen_rendering/box.jpg", 0);
	double box=X3D_CubeCreate(20,20,10,scene);
	X3D_ObjectSetPosition(box,-50,10,-50);
	X3D_ObjectRotate(box,0,30,0);
	X3D_ObjectSetMaterial(box,"box_tex");

	X3D_MaterialCreate("mScreen","", 0);
	X3D_MaterialSetTextureFormat("mScreen",X3D_TF_DEFAULT); //tfIntencity for black and white TV
	X3D_MaterialSetTextureFilter("mScreen",1,1);

	X3D_MaterialCreate("black","xception/offscreen_rendering/pixel-black.bmp", 0);

	double tv=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(tv,0,15,-60);
	X3D_ObjectRotate(tv,-15,0,0);
	double cube1=X3D_PlaneCreate(1,10,10,1,1,tv);
	X3D_ObjectSetMaterial(cube1,"mScreen");
	double cube2=X3D_CubeCreate(12,1,2,tv);
	X3D_ObjectSetPosition(cube2,0,5,-0.7);
	X3D_ObjectSetMaterial(cube2,"black");
	double cube3=X3D_CubeCreate(12,1,2,tv);
	X3D_ObjectSetPosition(cube3,0,-5,-0.7);
	X3D_ObjectSetMaterial(cube3,"black");
	double cube4=X3D_CubeCreate(1,10,2,tv);
	X3D_ObjectSetPosition(cube4,5.5,0,-0.7);
	X3D_ObjectSetMaterial(cube4,"black");
	double cube5=X3D_CubeCreate(1,10,2,tv);
	X3D_ObjectSetPosition(cube5,-5.5,0,-0.7);
	X3D_ObjectSetMaterial(cube5,"black");
	double cube6=X3D_CubeCreate(11,10.5,8,tv);
	X3D_ObjectSetPosition(cube6,0,0,-4.2);
	X3D_ObjectSetMaterial(cube6,"black");

	double camPos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(camPos,10,10,-10);
	X3D_ObjectRotate(camPos,0,20,0);

	double cam2Pos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(cam2Pos,0,10,-30);
	X3D_ObjectRotate(cam2Pos,0,50,0);
	double cam2Pos_cyl=X3D_CylinderCreate(0.45,0.45,2,16,4,1,cam2Pos);
	X3D_ObjectSetPosition(cam2Pos_cyl,0,0,-1.5);
	X3D_ObjectRotate(cam2Pos_cyl,90,0,0);
	X3D_ObjectSetMaterial(cam2Pos_cyl,"black");
	double cam2Pos_cube=X3D_CubeCreate(1,2,3,cam2Pos);
	X3D_ObjectSetMaterial(cam2Pos_cube,"black");
	double cam2Pos_cyl2=X3D_CylinderCreate(1,1,0.6,16,4,1,cam2Pos);
	X3D_ObjectSetPosition(cam2Pos_cyl2,0,1+0.5,-1);
	X3D_ObjectRotate(cam2Pos_cyl2,0,0,90);
	X3D_ObjectSetMaterial(cam2Pos_cyl2,"black");
	double cam2Pos_cyl3=X3D_CylinderCreate(1,1,0.6,16,4,1,cam2Pos);
	X3D_ObjectSetPosition(cam2Pos_cyl3,0,1+0.5,1);
	X3D_ObjectRotate(cam2Pos_cyl3,0,0,90);
	X3D_ObjectSetMaterial(cam2Pos_cyl3,"black");
	double cam2Pos_cyl4=X3D_CylinderCreate(0.2,0.2,9,16,4,1,cam2Pos);
	X3D_ObjectSetPosition(cam2Pos_cyl4,0,-5,0);
	X3D_ObjectSetMaterial(cam2Pos_cyl4,"black");
    
    double camera=X3D_CameraCreate(camPos);
	X3D_CameraSetViewDepth(camera,5000);
	double camera2=X3D_CameraCreate(cam2Pos);
	X3D_ObjectSetPosition(camera2,0,0,-1.5);
	X3D_CameraSetViewDepth(camera2,5000);
	X3D_CameraSetFocal(camera2,15);
	X3D_ViewerSetCamera(view1,camera);
	X3D_ViewerSetCamera(view2,camera2); 
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_LTGRAY,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
	
	double font2 = X3D_WindowsBitmapfontCreate("Verdana",8);
    double text_x3d = X3D_HUDTextCreate(font2,"X3D-TV",front);
    X3D_TextSetColor(text_x3d,X3D_C_LIME,0.9);
    X3D_ObjectSetPosition(text_x3d,5,6,0);
    
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
		if (GetKeyState(VK_UP)    & 0x80) X3D_ObjectMove(cam2Pos, -0.5);
		if (GetKeyState(VK_DOWN)  & 0x80) X3D_ObjectMove(cam2Pos,  0.5);
		if (GetKeyState(VK_RIGHT) & 0x80) X3D_ObjectRotate(cam2Pos,0,-3,0);
		if (GetKeyState(VK_LEFT)  & 0x80) X3D_ObjectRotate(cam2Pos,0, 3,0);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) X3D_ObjectRotate(camera,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_Update();
		X3D_ObjectHide(text_x3d);
		X3D_ViewerRender(view1);
		X3D_ObjectShow(text_x3d);

		X3D_ObjectHide(text_fps);
		X3D_ViewerRender(view2);
		X3D_ViewerCopyToTexture(view2,"mScreen");
		X3D_ObjectShow(text_fps);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(60));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();
	
	return 0;
}
