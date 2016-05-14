#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "xtreme3d.h"

#define STATE_IDLE 0
#define STATE_RUN  1
#define STATE_JUMP 2
#define STATE_LAND 3

static double CreateDceBox(double width, double height, double depth, double x, double y, double z, PCHAR material, double turn, double dce, double parent)
{ 
   static double col;
   col = X3D_CubeCreate(width,height,depth, parent);
   X3D_ObjectSetPosition(col,x,y,z);
   X3D_ObjectTurn(col,turn);
   X3D_DceStaticSetManager(col,dce);
   X3D_DceStaticSetActive(col,1);
   X3D_DceStaticSetSize(col,width,height,depth);  
   X3D_DceStaticSetShape(col,1); 
   X3D_DceStaticSetSolid(col,1);
   X3D_ObjectSetMaterial(col,material);
   return col; 
}

static double CreateSceneBox(double width, double height, double depth, double x, double y, double z, PCHAR material, double turn, double parent)
{ 
  static double col;
  col = X3D_CubeCreate(width,height,depth,parent);
  X3D_ObjectSetPosition(col,x,y,z);
  X3D_ObjectTurn(col,turn);
  X3D_ObjectSetMaterial(col,material);
  return col;
}

int main(int argc, char **argv)
{
    HWND hwnd;
	int s_width = 640;
    int s_height = 480;
	BOOL app_quit = FALSE;
	/* Xtreme3D functions */  
	X3D_Init();
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D Demo");
    
    /* Xtreme3D functions */    
    X3D_EngineCreate((double)((int)hwnd));     
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);    
    X3D_ViewerEnableVSync(view1,1);
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_BLACK);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_BLACK);
    X3D_ViewerSetFogDistance(view1,100,500);
    
    //RGB(0,0,255)
    
    double back = X3D_DummycubeCreate(0);
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    double light = X3D_LightCreate(X3D_LS_PARALLEL,0);
    X3D_LightSetDiffuseColor(light,RGB(255,128,0));
    X3D_LightSetAmbientColor(light,RGB(0,128,255));
    X3D_ObjectSetDirection(light,-1,-1,0);
    double light2 = X3D_LightCreate(X3D_LS_PARALLEL,0);
    X3D_LightSetDiffuseColor(light2,RGB(0,128,255));
    X3D_LightSetAmbientColor(light2,RGB(255,128,0));
    X3D_ObjectSetDirection(light2,1,-1,0);
    
    X3D_MaterialCreate("skyTop","media/sky_top.jpg",0);
    X3D_MaterialCreate("skyBottom","media/sky_bottom.jpg",0);
    X3D_MaterialCreate("skyLeft","media/sky_left.jpg",0);
    X3D_MaterialCreate("skyRight","media/sky_right.jpg",0);
    X3D_MaterialCreate("skyFront","media/sky_front.jpg",0);
    X3D_MaterialCreate("skyBack","media/sky_back.jpg",0);
    double sky = X3D_SkyboxCreate(back);
    X3D_SkyboxSetMaterial(sky,0,"skyTop");
    X3D_SkyboxSetMaterial(sky,1,"skyBottom");
    X3D_SkyboxSetMaterial(sky,2,"skyLeft");
    X3D_SkyboxSetMaterial(sky,3,"skyRight");
    X3D_SkyboxSetMaterial(sky,4,"skyFront");
    X3D_SkyboxSetMaterial(sky,5,"skyBack");
        
    double plane = X3D_PlaneCreate(0,100,100, 8,8, scene);
    X3D_MaterialCreate("plane_tex","media/ground.jpg",0);
    X3D_ObjectSetMaterial(plane,"plane_tex");
    X3D_ObjectSetPosition(plane,0,0.5,0);
    X3D_ObjectSetDirection(plane,0,1,0);
    
    double dce = X3D_DceManagerCreate();
    X3D_DceManagerSetManualStep(dce,1);
    X3D_DceManagerSetMovementScale(dce,2);
    double level = X3D_DummycubeCreate(scene);
    X3D_MaterialCreate("mbbox","",0);
    X3D_MaterialSetOptions("mbbox",0,1);
    X3D_MaterialSetPolygonMode("mbbox",X3D_PM_LINES);
    X3D_MaterialSetBlendingMode("mbbox",X3D_BM_TRANSPARENCY);
    X3D_MaterialSetDiffuseColor("mbbox",X3D_C_WHITE,0);
    
    X3D_MaterialCreate("mbricks","media/wall.jpg",0);
    X3D_MaterialSetTextureScale("mbricks",5,1);
    X3D_MaterialCreate("mbricks2","media/wall2.jpg",0);
    X3D_MaterialCreate("mcolumn","media/column.jpg",0);
    X3D_MaterialSetTextureScale("mcolumn",1,10);

    // double plane_col = CreateDceBox(100,100,100, 0,-50,0, "mbricks2", 0, dce, level);
	CreateDceBox(100,100,100, 0,-50,0, "mbricks2", 0, dce, level);

    // double blo1_col = CreateDceBox(100,10,10,     0,0,-55, "mbricks", 0, dce, level);
    // double blo2_col = CreateDceBox(100,10,10,     0,0, 55, "mbricks", 0, dce, level);
    // double blo3_col = CreateDceBox(100,10,10,   -55,0,  0, "mbricks", 90, dce, level);
    // double blo4_col = CreateDceBox(100,10,10,    55,0,  0, "mbricks", 90, dce, level);
	CreateDceBox(100,10,10,     0,0,-55, "mbricks", 0, dce, level);
    CreateDceBox(100,10,10,     0,0, 55, "mbricks", 0, dce, level);
    CreateDceBox(100,10,10,   -55,0,  0, "mbricks", 90, dce, level);
    CreateDceBox(100,10,10,    55,0,  0, "mbricks", 90, dce, level);

    // double blo5 = CreateSceneBox(100,10,10,     0,95,-55, "mbricks", 0, level);
    // double blo6 = CreateSceneBox(100,10,10,     0,95, 55, "mbricks", 0, level);
    // double blo7 = CreateSceneBox(100,10,10,   -55,95,  0, "mbricks", 90, level);
    // double blo8 = CreateSceneBox(100,10,10,    55,95,  0, "mbricks", 90, level);
	CreateSceneBox(100,10,10,     0,95,-55, "mbricks", 0, level);
    CreateSceneBox(100,10,10,     0,95, 55, "mbricks", 0, level);
    CreateSceneBox(100,10,10,   -55,95,  0, "mbricks", 90, level);
    CreateSceneBox(100,10,10,    55,95,  0, "mbricks", 90, level);

    // double colu1_col = CreateDceBox(10,200,10,    -55,0,-55, "mcolumn", 0, dce, level);
    // double colu2_col = CreateDceBox(10,200,10,    -55,0, 55, "mcolumn", 0, dce, level);
    // double colu3_col = CreateDceBox(10,200,10,     55,0, 55, "mcolumn", 0, dce, level);
    // double colu4_col = CreateDceBox(10,200,10,     55,0,-55, "mcolumn", 0, dce, level);
	CreateDceBox(10,200,10,    -55,0,-55, "mcolumn", 0, dce, level);
    CreateDceBox(10,200,10,    -55,0, 55, "mcolumn", 0, dce, level);
    CreateDceBox(10,200,10,     55,0, 55, "mcolumn", 0, dce, level);
    CreateDceBox(10,200,10,     55,0,-55, "mcolumn", 0, dce, level);
    
    double player_col = X3D_SphereCreate(5,8,8,scene);
    X3D_ObjectSetMaterial(player_col,"mbbox");
    X3D_DceSetManager(player_col,dce);
    X3D_DceSetUseGravity(player_col,0);
    X3D_DceSetActive(player_col,1);
    X3D_DceSetSize(player_col,5,5,5);
    X3D_DceSetSolid(player_col,1);
    X3D_DceSetSlideOrBounce(player_col,0);
    X3D_ObjectSetPosition(player_col,0,5,0);
    X3D_DceSetFriction(player_col,1.5); 
    double grav = 0;
    double jump = 0;
    double floory = X3D_ObjectGetGroundHeight(player_col,level) + 5;
    X3D_ObjectRotate(player_col,0,90,0);
    
    double player_dummy = X3D_DummycubeCreate(scene);
    X3D_MaterialCreate("mPlayer","media/quake2model/player_tex.jpg",0);
    X3D_MaterialCreate("mWeapon","media/quake2model/weapon_tex.jpg",0);
    double actor = X3D_ActorCreate("media/quake2model/player_geom.md2",player_dummy);
    X3D_ObjectSetMaterial(actor,"mPlayer");
    X3D_ObjectSetScale(actor,0.2,0.2,0.2);
    X3D_ObjectRotate(actor,90,0,0);
    X3D_ObjectSetPosition(actor,0,-0.25,0);
    X3D_ActorSwitchToAnimation(actor,0);
    X3D_ActorSetInterval(actor, 80);
    double weapon = X3D_ActorCreate("media/quake2model/weapon_geom.md2",player_dummy);
    X3D_MaterialSetTextureCompression("mWeapon", X3D_TC_HIGH_QUALITY);
    X3D_ObjectSetMaterial(weapon,"mWeapon");
    X3D_ObjectSetScale(weapon,0.2,0.2,0.2);
    X3D_ActorSwitchToAnimation(weapon,0);
    int state = STATE_IDLE;
    // double current_frame;
    
    double camPos = X3D_DummycubeCreate(scene);
    double camera = X3D_CameraCreate(camPos);
    X3D_CameraSetViewDepth(camera,1000);
    X3D_CameraSetFocal(camera,120);
    X3D_CameraSetSceneScale(camera,0.5);
    X3D_ObjectSetPosition(camera,0,10,15);
    X3D_ViewerSetCamera(view1,camera);
    X3D_CameraSetTargetObject(camera,player_col);
    
    double font = X3D_WindowsBitmapfontCreate("Arial",10);
    double text_fps = X3D_HUDTextCreate(font,"FPS: ",front);
    X3D_TextSetColor(text_fps,X3D_C_WHITE,0.6);
    X3D_ObjectSetPosition(text_fps,16,8,0);
    
    double deltax = 0;
    double deltay = 1;
    // double pit = 0;
    double mx = 320;
    double my = 240;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		/* Xtreme3D functions */
		state = STATE_IDLE;
		if (GetKeyState('W') & 0x80) 
		{
			if (state!=STATE_LAND) 
			{
				X3D_DceApplyAcceleration(player_col, 10,0,0); 
				if (state!=STATE_JUMP) 
					state=STATE_RUN;
			}
		}
		else if (GetKeyState('S') & 0x80) 
		{
			if (state!=STATE_LAND) 
			{
				X3D_DceApplyAcceleration(player_col,-10,0,0); 
				if (state!=STATE_JUMP) 
					state=STATE_RUN;
			}
		}  
		if (GetKeyState(VK_SPACE) & 0x80) 
		{
			if (state!=STATE_LAND) 
				jump=1.3;
		}
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		X3D_DceMove(player_col,0,jump-grav,0, 0.5);
		floory = X3D_ObjectGetGroundHeight(player_col,level)+5;
		if (floor(X3D_ObjectGetPosition(player_col,1)) > floory)
		{
			state=STATE_JUMP;
			if (jump>0) 
				jump-=0.05;
			grav+=0.05;
		}
		else
		{
			jump=0;
			grav=0;
		}
				 
		if (state==STATE_IDLE) {X3D_ActorSetInterval(actor, 100); X3D_ActorSetAnimationRange(actor,0 ,39); X3D_ActorSetAnimationMode(actor,X3D_AAM_LOOP);}
		if (state==STATE_RUN)  {X3D_ActorSetInterval(actor, 80); X3D_ActorSetAnimationRange(actor,40,45); X3D_ActorSetAnimationMode(actor,X3D_AAM_LOOP);}
		if (state==STATE_JUMP) {X3D_ActorSetInterval(actor, 200); X3D_ActorSetAnimationRange(actor,66,73); X3D_ActorSetAnimationMode(actor,X3D_AAM_PLAY_ONCE);}
		
		X3D_ObjectAlignWithObject(player_dummy,player_col);
		X3D_ObjectSetPositionOfObject(player_dummy,player_col);
		X3D_ObjectAlignWithObject(weapon,actor);
		X3D_ObjectSetPositionOfObject(weapon,actor);
		X3D_ActorSynchronize(weapon,actor);
		
		double cx=X3D_ObjectGetAbsolutePosition(camPos,0);
		double cy=X3D_ObjectGetAbsolutePosition(camPos,1);
		double cz=X3D_ObjectGetAbsolutePosition(camPos,2);
		double tx=X3D_ObjectGetAbsolutePosition(player_col,0);
		double ty=X3D_ObjectGetAbsolutePosition(player_col,1);
		double tz=X3D_ObjectGetAbsolutePosition(player_col,2);
		double dx=tx-cx; 
		double dy=ty+2-cy; 
		double dz=tz-cz;
		X3D_ObjectTranslate(camPos,dx,dy*0.05,dz);
		
		deltax = (mx-X3D_MouseGetX())/6;
		deltay = (my-X3D_MouseGetY())/6;
		X3D_CameraMoveAroundTarget(camera,0,deltax);
		X3D_ObjectRotate(player_col,0,deltax,0);
		X3D_CameraMoveAroundTarget(camera,deltay,0);
		X3D_MouseSetPosition(mx,my);
		
		X3D_DceManagerStep(dce,0.1);
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