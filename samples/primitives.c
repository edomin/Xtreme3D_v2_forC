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
    X3D_ViewerSetBackgroundColor(view1,X3D_C_BLACK);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_BLACK);
    X3D_ViewerSetFogDistance(view1,64,128);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light=X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_LightSetDiffuseColor(light,(double)0x9BD1FD);
	X3D_ObjectSetPosition(light,0,60,0);
	double light2=X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_LightSetDiffuseColor(light2,(double)0x9BD1FD);
	X3D_ObjectSetPosition(light2,0,40,0);
	X3D_LightSetAttenuation(light,0,0,0.001);
	X3D_LightSetAttenuation(light2,0,0,0.001);
    
    X3D_MaterialCreate("mfloor","xception/primitives/floor.jpg", 0);
	X3D_MaterialSetTextureScale("mfloor",0.0625,0.0625);
	double shadows=X3D_DummycubeCreate(scene);
	double sp=X3D_ShadowplaneCreate(128,128, 16,16, shadows, light, X3D_C_BLACK, 0.8, scene);
	X3D_ObjectSetMaterial(sp,"mfloor");
	X3D_ObjectPitch(sp,90);

	X3D_MaterialCreate("mp01","", 0);
	X3D_MaterialSetDiffuseColor("mp01",(double)0x7652BA,1);
	X3D_MaterialSetAmbientColor("mp01",(double)0x003FF9,0.5);

	X3D_MaterialCreate("mp02","", 0);
	X3D_MaterialSetDiffuseColor("mp02",(double)0x72DAE9,1);
	X3D_MaterialSetAmbientColor("mp02",(double)0x003FF9,0.1);
	X3D_MaterialSetSpecularColor("mp02",(double)0xAEDBEA,1);
	X3D_MaterialSetShininess("mp02",10);

	X3D_MaterialCreate("mp03","", 0);
	X3D_MaterialSetDiffuseColor("mp03",(double)0x444400,1);
	X3D_MaterialSetAmbientColor("mp03",(double)0x000000,0.5);
	X3D_MaterialSetSpecularColor("mp03",(double)0x888800,1);
	X3D_MaterialSetShininess("mp03",10);

	X3D_MaterialCreate("mp04","", 0);
	X3D_MaterialSetDiffuseColor("mp04",(double)0xAEDBEA,1);
	X3D_MaterialSetAmbientColor("mp04",(double)0x003FF9,0.5);
	X3D_MaterialSetShininess("mp04",0);

	X3D_MaterialCreate("mp05","", 0);
	X3D_MaterialSetDiffuseColor("mp05",(double)0x333333,1);

	X3D_MaterialCreate("mg01","", 0);
	X3D_MaterialSetDiffuseColor("mg01",(double)0xE1DEBD,1);
	X3D_MaterialSetAmbientColor("mg01",(double)0x753C38,1);
	X3D_MaterialCreate("mg02","", 0);
	X3D_MaterialSetDiffuseColor("mg02",(double)0xE1DEBD,1);
	X3D_MaterialSetAmbientColor("mg02",(double)0x9E3A33,1);
	X3D_MaterialCreate("mg03","", 0);
	X3D_MaterialSetDiffuseColor("mg03",(double)0xE1DEBD,1);
	X3D_MaterialSetAmbientColor("mg03",(double)0xC72D22,1);
	X3D_MaterialCreate("mg04","", 0);
	X3D_MaterialSetDiffuseColor("mg04",(double)0xE1DEBD,1);
	X3D_MaterialSetAmbientColor("mg04",(double)0xED1000,1);

	double pencil=X3D_DummycubeCreate(shadows);
	X3D_ObjectSetPosition(pencil,0,0,15);
	X3D_ObjectRoll(pencil,30);
	X3D_ObjectPitch(pencil,90);
	double pencil0_1=X3D_TorusCreate(0.77,0.2,16,20,pencil); 
	X3D_ObjectSetPositionY(pencil0_1,1);
	X3D_ObjectPitch(pencil0_1,90);
	X3D_ObjectSetMaterial(pencil0_1,"mp01");
	double pencil0_2=X3D_CylinderCreate(0.75,0.75,0.3,16,20,2,pencil);
	X3D_ObjectSetPositionY(pencil0_2,0.951);
	X3D_ObjectSetMaterial(pencil0_2,"mp01");
	double pencil1=X3D_CylinderCreate(0.97,0.97,1.5,16,20,2,pencil);
	X3D_ObjectSetPositionY(pencil1,1.75);
	X3D_ObjectSetMaterial(pencil1,"mp01");
	double pencil2=X3D_CylinderCreate(0.98,0.98,4,12,20,2,pencil);
	X3D_ObjectSetPositionY(pencil2,4.5);
	X3D_ObjectSetMaterial(pencil2,"mp02");
	double pencil3=X3D_CylinderCreate(1,1,20,6,20,2,pencil);
	X3D_ObjectSetPositionY(pencil3,16.5);
	X3D_ObjectSetMaterial(pencil3,"mp03");
	double pencil4=X3D_CylinderCreate(0.25,1,4,6,20,2,pencil);
	X3D_ObjectSetPositionY(pencil4,28.5);
	X3D_ObjectSetMaterial(pencil4,"mp04");
	double pencil5=X3D_CylinderCreate(0.02,0.20,1.5,24,20,2,pencil);
	X3D_ObjectSetPositionY(pencil5,31.25);
	X3D_ObjectSetMaterial(pencil5,"mp05");
	X3D_ObjectHide(pencil);

	pencil2=X3D_ObjectCopy(pencil,shadows);
	X3D_ObjectShow(pencil2);
	X3D_ObjectSetPosition(pencil2,14,0.9,-7);
	X3D_ObjectTurn(pencil2,-27);

	pencil3=X3D_ObjectCopy(pencil,shadows);
	X3D_ObjectShow(pencil3);
	X3D_ObjectSetPosition(pencil3,7,0.9,8);
	X3D_ObjectTurn(pencil3,-5);

	double glass=X3D_DummycubeCreate(shadows);
	X3D_ObjectSetPosition(glass,-10,0,0);
	double glass1=X3D_AnnulusCreate(5,5.5, 5,32,1,1,glass);
	X3D_ObjectSetPositionY(glass1,5/2);
	X3D_ObjectSetMaterial(glass1,"mg01");
	double glass2=X3D_AnnulusCreate(5.5,6, 5,32,1,1,glass);
	X3D_ObjectSetPositionY(glass2,5+5/2);
	X3D_ObjectSetMaterial(glass2,"mg02");
	double glass3=X3D_AnnulusCreate(6,6.5, 5,32,1,1,glass);
	X3D_ObjectSetPositionY(glass3,5+5+5/2);
	X3D_ObjectSetMaterial(glass3,"mg03");
	double glass4=X3D_AnnulusCreate(6.5,7, 5,32,1,1,glass);
	X3D_ObjectSetPositionY(glass4,5+5+5+5/2);
	X3D_ObjectSetMaterial(glass4,"mg04");

	pencil4=X3D_ObjectCopy(pencil,shadows);
	X3D_ObjectShow(pencil4);
	X3D_ObjectSetPosition(pencil4,-12.5,14,0);
	X3D_ObjectPitch(pencil4,-90);
	X3D_ObjectTurn(pencil4,-25);

	pencil4=X3D_ObjectCopy(pencil,shadows);
	X3D_ObjectShow(pencil4);
	X3D_ObjectSetPosition(pencil4,-12.5,14,3);
	X3D_ObjectPitch(pencil4,-105);
	X3D_ObjectTurn(pencil4,-5);
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,35,40);
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,5000);
    X3D_ViewerSetCamera(view1,camera); 
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_WHITE,0.6);
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
