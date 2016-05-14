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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Terrain Demo");
    
    /* Xtreme3D functions */     
    X3D_EngineCreate((double)((int)hwnd));         
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);  
    X3D_ViewerSetLighting(view1,0);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_WHITE);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_WHITE);
    X3D_ViewerSetFogDistance(view1,300,800);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    //RGB(0,0,255)
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0);
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light = X3D_LightCreate(X3D_LS_OMNI,0);
    X3D_ObjectSetPosition(light,5,40,5);
        
    // double shadows = X3D_DummycubeCreate(scene);
	X3D_DummycubeCreate(scene);
    
    X3D_MaterialCreate("mHDS","media/terrain_8bit.bmp",0);
    double hds = X3D_BmpHDSCreate("mHDS");
    double terrain = X3D_TerrainCreate(scene);
    X3D_TerrainSetHeightData(terrain,hds);
    X3D_TerrainSetTileSize(terrain,32);
    X3D_TerrainSetTilesPerTexture(terrain,8);
    X3D_TerrainSetQualityDistance(terrain,150);
    X3D_TerrainSetQualityStyle(terrain,0);
    X3D_TerrainSetMaxCLodTriangles(terrain,10000);
    X3D_TerrainSetOcclusionFrameSkip(terrain,0);
    X3D_TerrainSetOcclusionTesselate(terrain,1);
    X3D_ObjectSetScale(terrain,1,1,0.1);
    X3D_ObjectRotate(terrain,90,0,0);

    X3D_MaterialCreate("mTerrain","media/snow.jpg",0);
    X3D_MaterialCreate("detmap","media/detmap.jpg",0);
    X3D_MaterialSetTextureScale("detmap",32,32);
    X3D_MaterialSetBlendingMode("detmap",X3D_BM_TRANSPARENCY);
    X3D_MaterialSetSecondTexture("mTerrain","detmap");
    X3D_MaterialSetOptions("mTerrain",0,1);
    X3D_MaterialSetOptions("mTerrain",0,1);
    X3D_ObjectSetMaterial(terrain,"mTerrain");
    
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,50,40);
    
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,800);
    X3D_CameraSetFocal(camera,120);
    X3D_CameraSetSceneScale(camera,0.5);
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
	
	while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		if (GetKeyState('W')      & 0x80) X3D_ObjectMove(camPos,  -0.5);
		if (GetKeyState('S')      & 0x80) X3D_ObjectMove(camPos,   0.5);
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 0.5);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-0.5);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		X3D_ObjectSetPositionY(camPos,X3D_TerrainGetHeightAtObjectPosition(terrain,camPos)+4);
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_ObjectRotate(camPos,0,deltax,0);
		pit = X3D_ObjectGetPitch(camera)+deltay;
		if (pit<89 || pit>-89) X3D_ObjectRotate(camera,deltay,0,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_ViewerRender(view1);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(60));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();

    return 0;
}