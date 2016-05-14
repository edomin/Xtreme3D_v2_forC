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
    X3D_ViewerEnableFog(view1,0);
    X3D_ViewerSetFogColor(view1,RGB(203, 204, 204));
    X3D_ViewerSetFogDistance(view1,200,800);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light1 = X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_LightSetDiffuseColor(light1,X3D_C_RED);
    X3D_ObjectSetPosition(light1,60,0,60);
	
	double light2 = X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_LightSetDiffuseColor(light2,X3D_C_BLUE);
    X3D_ObjectSetPosition(light2,-60,0,-60);
	
	double light3 = X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_LightSetDiffuseColor(light3,X3D_C_YELLOW);
    X3D_ObjectSetPosition(light3,60,0,-60);
	
	double light4 = X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_LightSetDiffuseColor(light4,X3D_C_LIME);
    X3D_ObjectSetPosition(light4,-60,0,60);
    
    double octcubes=X3D_DummycubeCreate(scene);

	double oct=X3D_OctreeCreate(8,24,0.1,X3D_CM_FINE_CULLING);
	double octspace=X3D_CubeCreate(-100*(2)+10,-100*(2)+10,-100*(2)+10,scene);
	X3D_MaterialCreate("mtransp","", 0);
	X3D_MaterialSetDiffuseColor("mtransp",X3D_C_BLUE,1);
	X3D_MaterialSetPolygonMode("mtransp",X3D_PM_LINES);
	X3D_MaterialCreate("mtransp2","", 0);
	X3D_MaterialSetDiffuseColor("mtransp2",X3D_C_RED,0.8);
	X3D_MaterialSetAmbientColor("mtransp2",X3D_C_RED,0.8);
	X3D_MaterialSetBlendingMode("mtransp2",X3D_BM_TRANSPARENCY);
	X3D_ObjectSetMaterial(octspace,"mtransp");
	double z1;
	double y1;
	double x1;
	double cube;
	for (z1=-10;z1<10;z1+=1)
		for (y1=-10;y1<10;y1+=1)
			for (x1=-10;x1<10;x1+=1)
			{
				cube=X3D_CubeCreate(8,8,8,octcubes);
				X3D_ObjectSetPosition(cube,x1*10,y1*10,z1*10);
				X3D_PartitionAddLeaf(oct,cube);
				X3D_ObjectHide(cube);
			}
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,20,300);
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,5000);
    X3D_ViewerSetCamera(view1,camera); 
	
	double spos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(spos,0,0,0);
	double bsphere=X3D_SphereCreate(20,16,16,spos);
	X3D_ObjectHide(bsphere);
	X3D_ObjectSetMaterial(bsphere,"mtransp2");
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
    
    double deltax = 0;
    double deltay = 1;
    double pit = 0;
    double mx = 320;
    double my = 240;
	
	double qr;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		if (GetKeyState('W')       & 0x80) X3D_ObjectMove(camPos,  -2);
		if (GetKeyState('S')       & 0x80) X3D_ObjectMove(camPos,   2);
		if (GetKeyState('A')       & 0x80) X3D_ObjectStrafe(camPos, 1);
		if (GetKeyState('D')       & 0x80) X3D_ObjectStrafe(camPos,-1);
		if (GetKeyState(VK_UP)     & 0x80) X3D_ObjectMove(spos,    -2);
		if (GetKeyState(VK_DOWN)   & 0x80) X3D_ObjectMove(spos,     2);
		if (GetKeyState(VK_LEFT)   & 0x80) X3D_ObjectStrafe(spos,   2);
		if (GetKeyState(VK_RIGHT)  & 0x80) X3D_ObjectStrafe(spos,  -2);
		if (GetKeyState(VK_PRIOR)  & 0x80) X3D_ObjectLift(spos,     2);
		if (GetKeyState(VK_NEXT)   & 0x80) X3D_ObjectLift(spos,    -2);
		if (GetKeyState(VK_ESCAPE) & 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) X3D_ObjectRotate(camera,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_Update();
		X3D_PartitionResultHide(oct);
		qr=X3D_PartitionQueryBSphere(oct,bsphere);
		X3D_PartitionResultShow(oct);
		X3D_ViewerRender(view1);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(60));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();
	
	return 0;
}
