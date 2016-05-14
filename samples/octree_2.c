#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    
	X3D_MaterialCreate("heightmap","xception/octree_2/terrain.bmp",0);
	X3D_MaterialCreate("ground","xception/octree_2/ground.jpg",0);
	X3D_MaterialCreate("grass","xception/octree_2/grass.tga",0);
	X3D_MaterialSetBlendingMode("grass",X3D_BM_TRANSPARENCY);
	X3D_MaterialSetTextureImageAlpha("grass",X3D_TIA_DEFAULT);
	X3D_MaterialSetDiffuseColor("grass",X3D_C_WHITE,0.75);
	
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
    X3D_ViewerSetLighting(view1,0);
    X3D_ViewerSetBackgroundColor(view1,RGB(255, 218, 168));
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,RGB(255, 218, 168));
    X3D_ViewerSetFogDistance(view1,1500,3000);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double heightdata=X3D_BmpHDSCreate("heightmap");
	X3D_BmpHDSSetInfiniteWarp(heightdata,1);
	double terrain=X3D_TerrainCreate(scene);
	X3D_ObjectSetScale(terrain, 80, 80, 4);
	X3D_ObjectSetDirection(terrain,0, 1, 0);
	X3D_TerrainSetCLodPrecision(terrain, 50);
	X3D_TerrainSetTileSize(terrain,48);
	X3D_TerrainSetTilesPerTexture(terrain,0.05);
	X3D_TerrainSetQualityStyle(terrain, 0);
	X3D_TerrainSetHeightData(terrain,heightdata);
	//X3D_TerrainSetOcclusionTesselate(terrain,1);
	X3D_ObjectSetMaterial(terrain, "ground");

	double octcubes=X3D_DummycubeCreate(scene);

	double oct=X3D_OctreeCreate(8,24,0.1,X3D_CM_FINE_CULLING);
	double x1;
	double y1;
	double sprite1;
	time_t t;
	srand((unsigned)time(&t));
	for (y1=-30;y1<30;y1+=1)
		for (x1=-30;x1<30;x1+=1)
		{
			sprite1=X3D_SpriteCreate("grass",100,100,octcubes); 
			X3D_SpriteNoZWrite(sprite1,1); 
			X3D_ObjectSetPosition(sprite1,x1*70+rand()%20,0,y1*70+rand()%10);
			X3D_ObjectSetPositionY(sprite1,X3D_TerrainGetHeightAtObjectPosition(terrain,sprite1)+30);
			X3D_PartitionAddLeaf(oct,sprite1);
			X3D_ObjectHide(sprite1);
		}
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,0,0);
    double camera = X3D_CameraCreate(camPos);
	X3D_ObjectSetPosition(camera,0,50,0);
    X3D_CameraSetViewDepth(camera,3000);
    X3D_ViewerSetCamera(view1,camera); 
	
	double bsphere=X3D_SphereCreate(150,16,16,camPos);
	X3D_ObjectHide(bsphere);
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_BLACK,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
    
    double deltax = 0;
    double deltay = 1;
    double pit = 0;
    double mx = 320;
    double my = 240;
	
	double posy;
	double qr;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		
		posy=X3D_TerrainGetHeightAtObjectPosition(terrain,camPos);
		X3D_ObjectSetPositionY(camPos,posy+20);
		
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -6);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   6);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 6);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-6);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
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
