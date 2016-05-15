#include <stdio.h>
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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D SMD Skeleton Trinity Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
	X3D_MaterialLibrarySetTexturePaths(matlib,"xception/smd_skeleton_trinity/Trinity");
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height);
	
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,(double)0xC0C0C0);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
	X3D_MaterialCreate("logo","xception/smd_skeleton_trinity/logo.tga",1);
	X3D_MaterialSetOptions("logo",1,1);
	X3D_MaterialSetTextureImageAlpha("logo",X3D_TIA_DEFAULT);
	double logo=X3D_HUDSpriteCreate("logo",192,96,front);
	X3D_ObjectSetPosition(logo,800-192/2,600-96/2,0);
	
    double light=X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_ObjectSetPosition(light,5,30,5);
	X3D_LightSetDiffuseColor(light,RGB(255,128,0));
	X3D_LightSetAmbientColor(light,RGB(0,128,255));
	double light2=X3D_LightCreate(X3D_LS_OMNI,0);
	X3D_ObjectSetPosition(light2,-10,50,-10);
	X3D_LightSetDiffuseColor(light2,RGB(0,128,255));
	X3D_LightSetAmbientColor(light2,RGB(255,128,0));
    
    double shadow_caster=X3D_DummycubeCreate(scene);

	double plane=X3D_ShadowplaneCreate(100,100,5,5,shadow_caster,light,X3D_C_BLACK, 0.3,scene);
	X3D_MaterialCreate("plane_tex","", 0);
	X3D_MaterialSetOptions("plane_tex",1,1);
	X3D_MaterialSetDiffuseColor("plane_tex",(double)0xC0C0C0,1);
	X3D_ObjectSetMaterial(plane,"plane_tex");
	X3D_ObjectSetPosition(plane,0,0,0);
	X3D_ObjectSetDirection(plane,0,1,0);

	double actor_dummy=X3D_DummycubeCreate(shadow_caster);
	X3D_ObjectShowAxes(actor_dummy,0);
	X3D_ObjectSetPosition(actor_dummy,0,9,0);
	double actor=X3D_ActorCreate("xception/smd_skeleton_trinity/Trinity/trinity_mesh.smd",actor_dummy);
	X3D_ObjectShowAxes(actor,0);
	X3D_ActorShowSkeleton(actor,0);
	X3D_ActorSetInterval(actor,45);
	X3D_ObjectSetScale(actor,0.25,0.25,0.25);
	X3D_ObjectRotate(actor,90,0,0);
	X3D_ActorAddObject(actor,"xception/smd_skeleton_trinity/Trinity/trinity_walk.smd");
	X3D_ActorAddObject(actor,"xception/smd_skeleton_trinity/Trinity/trinity_run.smd");
	X3D_ActorAddObject(actor,"xception/smd_skeleton_trinity/Trinity/trinity_jump.smd");
	double anim=1;
	X3D_ActorSwitchToAnimation(actor,anim);

	double Bip01=X3D_ActorGetBoneByName(actor,"Bip01");
	double Bip01_Pelvis=X3D_ActorGetBoneByName(actor,"Bip01 Pelvis");
	double Bip01_L_Leg=X3D_ActorGetBoneByName(actor,"Bip01 L Leg");
	double Bip01_L_Leg1=X3D_ActorGetBoneByName(actor,"Bip01 L Leg1");
	double Bip01_L_Foot=X3D_ActorGetBoneByName(actor,"Bip01 L Foot");
	double Bip01_L_Toe0=X3D_ActorGetBoneByName(actor,"Bip01 L Toe0");
	double Bip01_L_Toe01=X3D_ActorGetBoneByName(actor,"Bip01 L Toe01");
	double Bip01_L_Toe02=X3D_ActorGetBoneByName(actor,"Bip01 L Toe02");
	double Bip01_R_Leg=X3D_ActorGetBoneByName(actor,"Bip01 R Leg");
	double Bip01_R_Leg1=X3D_ActorGetBoneByName(actor,"Bip01 R Leg1");
	double Bip01_R_Foot=X3D_ActorGetBoneByName(actor,"Bip01 R Foot");
	double Bip01_R_Toe0=X3D_ActorGetBoneByName(actor,"Bip01 R Toe0");
	double Bip01_R_Toe01=X3D_ActorGetBoneByName(actor,"Bip01 R Toe01");
	double Bip01_R_Toe02=X3D_ActorGetBoneByName(actor,"Bip01 R Toe02"); 
	double Bip01_Spine=X3D_ActorGetBoneByName(actor,"Bip01 Spine");
	double Bip01_Spine1=X3D_ActorGetBoneByName(actor,"Bip01 Spine1");
	double Bip01_Spine2=X3D_ActorGetBoneByName(actor,"Bip01 Spine2");
	double Bip01_Spine3=X3D_ActorGetBoneByName(actor,"Bip01 Spine3");
	double Bip01_Neck=X3D_ActorGetBoneByName(actor,"Bip01 Neck");
	double Bip01_Head=X3D_ActorGetBoneByName(actor,"Bip01 Head");
	double Bip01_L_Arm=X3D_ActorGetBoneByName(actor,"Bip01 L Arm");
	double Bip01_L_Arm1=X3D_ActorGetBoneByName(actor,"Bip01 L Arm1");
	double Bip01_L_Arm2=X3D_ActorGetBoneByName(actor,"Bip01 L Arm2");
	double Bip01_L_Hand=X3D_ActorGetBoneByName(actor,"Bip01 L Hand");
	double Bip01_L_Finger0=X3D_ActorGetBoneByName(actor,"Bip01 L Finger0");
	double Bip01_L_Finger01=X3D_ActorGetBoneByName(actor,"Bip01 L Finger01");
	double Bip01_L_Finger02=X3D_ActorGetBoneByName(actor,"Bip01 L Finger02");
	double Bip01_L_Finger1=X3D_ActorGetBoneByName(actor,"Bip01 L Finger1");
	double Bip01_L_Finger11=X3D_ActorGetBoneByName(actor,"Bip01 L Finger11");
	double Bip01_L_Finger12=X3D_ActorGetBoneByName(actor,"Bip01 L Finger12");
	double Bip01_R_Arm=X3D_ActorGetBoneByName(actor,"Bip01 R Arm");
	double Bip01_R_Arm1=X3D_ActorGetBoneByName(actor,"Bip01 R Arm1");
	double Bip01_R_Arm2=X3D_ActorGetBoneByName(actor,"Bip01 R Arm2");
	double Bip01_R_Hand=X3D_ActorGetBoneByName(actor,"Bip01 R Hand");
	double Bip01_R_Finger0=X3D_ActorGetBoneByName(actor,"Bip01 R Finger0");
	double Bip01_R_Finger01=X3D_ActorGetBoneByName(actor,"Bip01 R Finger01");
	double Bip01_R_Finger02=X3D_ActorGetBoneByName(actor,"Bip01 R Finger02");
	double Bip01_R_Finger1=X3D_ActorGetBoneByName(actor,"Bip01 R Finger1");
	double Bip01_R_Finger11=X3D_ActorGetBoneByName(actor,"Bip01 R Finger11");
	double Bip01_R_Finger12=X3D_ActorGetBoneByName(actor,"Bip01 R Finger12");

	double Bip01_cube=X3D_DummycubeCreate(actor);
		X3D_ObjectSetPosition(Bip01_cube,X3D_ActorGetBonePosition(actor,Bip01,0),X3D_ActorGetBonePosition(actor,Bip01,1),X3D_ActorGetBonePosition(actor,Bip01,2));
	double Bip01_Pelvis_cube=X3D_DummycubeCreate(Bip01_cube);
		X3D_ObjectSetPosition(Bip01_Pelvis_cube,X3D_ActorGetBonePosition(actor,Bip01_Pelvis,0),X3D_ActorGetBonePosition(actor,Bip01_Pelvis,1),X3D_ActorGetBonePosition(actor,Bip01_Pelvis,2));
	double Bip01_Spine_cube=X3D_DummycubeCreate(Bip01_Pelvis_cube); 
		X3D_ObjectSetPosition(Bip01_Spine_cube,X3D_ActorGetBonePosition(actor,Bip01_Spine,0),X3D_ActorGetBonePosition(actor,Bip01_Spine,1),X3D_ActorGetBonePosition(actor,Bip01_Spine,2));
	double Bip01_Spine1_cube=X3D_DummycubeCreate(Bip01_Spine_cube); 
		X3D_ObjectSetPosition(Bip01_Spine1_cube,X3D_ActorGetBonePosition(actor,Bip01_Spine1,0),X3D_ActorGetBonePosition(actor,Bip01_Spine1,1),X3D_ActorGetBonePosition(actor,Bip01_Spine1,2));
	double Bip01_Spine2_cube=X3D_DummycubeCreate(Bip01_Spine1_cube); 
		X3D_ObjectSetPosition(Bip01_Spine2_cube,X3D_ActorGetBonePosition(actor,Bip01_Spine2,0),X3D_ActorGetBonePosition(actor,Bip01_Spine2,1),X3D_ActorGetBonePosition(actor,Bip01_Spine2,2));
	double Bip01_Spine3_cube=X3D_DummycubeCreate(Bip01_Spine2_cube); 
		X3D_ObjectSetPosition(Bip01_Spine3_cube,X3D_ActorGetBonePosition(actor,Bip01_Spine3,0),X3D_ActorGetBonePosition(actor,Bip01_Spine3,1),X3D_ActorGetBonePosition(actor,Bip01_Spine3,2));
	double Bip01_Neck_cube=X3D_DummycubeCreate(Bip01_Spine3_cube); 
		X3D_ObjectSetPosition(Bip01_Neck_cube,X3D_ActorGetBonePosition(actor,Bip01_Neck,0),X3D_ActorGetBonePosition(actor,Bip01_Neck,1),X3D_ActorGetBonePosition(actor,Bip01_Neck,2));
	double Bip01_R_Arm_cube=X3D_DummycubeCreate(Bip01_Neck_cube); 
		X3D_ObjectSetPosition(Bip01_R_Arm_cube,X3D_ActorGetBonePosition(actor,Bip01_R_Arm,0),X3D_ActorGetBonePosition(actor,Bip01_R_Arm,1),X3D_ActorGetBonePosition(actor,Bip01_R_Arm,2));
	double Bip01_R_Arm1_cube=X3D_DummycubeCreate(Bip01_R_Arm_cube); 
		X3D_ObjectSetPosition(Bip01_R_Arm1_cube,X3D_ActorGetBonePosition(actor,Bip01_R_Arm1,0),X3D_ActorGetBonePosition(actor,Bip01_R_Arm1,1),X3D_ActorGetBonePosition(actor,Bip01_R_Arm1,2));
	double Bip01_R_Arm2_cube=X3D_DummycubeCreate(Bip01_R_Arm1_cube); 
		X3D_ObjectSetPosition(Bip01_R_Arm2_cube,X3D_ActorGetBonePosition(actor,Bip01_R_Arm2,0),X3D_ActorGetBonePosition(actor,Bip01_R_Arm2,1),X3D_ActorGetBonePosition(actor,Bip01_R_Arm2,2));
	double Bip01_R_Hand_cube=X3D_DummycubeCreate(Bip01_R_Arm2_cube); 
		X3D_ObjectSetPosition(Bip01_R_Hand_cube,X3D_ActorGetBonePosition(actor,Bip01_R_Hand,0),X3D_ActorGetBonePosition(actor,Bip01_R_Hand,1),X3D_ActorGetBonePosition(actor,Bip01_R_Hand,2));
		
	double pistol=X3D_FreeformCreate("xception/smd_skeleton_trinity/Weapons/pistol.3ds",Bip01_R_Hand_cube);
	X3D_MaterialCreate("mPistol","xception/smd_skeleton_trinity/Weapons/pistol.jpg", 0);
	X3D_ObjectSetMaterial(pistol,"mPistol");
	X3D_ObjectSetScale(pistol,-0.2,-0.2,0.2);
	X3D_ObjectRotate(pistol,0,0,90);
	X3D_ObjectHide(pistol);

	double rifle=X3D_FreeformCreate("xception/smd_skeleton_trinity/Weapons/rifle.3ds",Bip01_R_Hand_cube);
	X3D_MaterialCreate("mRifle","xception/smd_skeleton_trinity/Weapons/rifle.jpg", 0);
	X3D_ObjectSetMaterial(rifle,"mRifle");
	X3D_ObjectSetScale(rifle,-0.2,-0.2,0.2);
	X3D_ObjectRotate(rifle,0,0,90);
	X3D_ObjectHide(rifle);

	double weapon=rifle;
	X3D_ObjectShow(weapon);
       
    double camPos = X3D_DummycubeCreate(scene);
    X3D_ObjectSetPosition(camPos,0,17,40);
    
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
    double mx = 400;
    double my = 300;
    
    X3D_MouseSetPosition(mx,my);
   
    static char FPS[256];
	
	BOOL previous_return = FALSE;
	BOOL current_return = FALSE;

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		
		X3D_ObjectClueToBone(Bip01_cube,actor,Bip01);
		X3D_ObjectClueToBone(Bip01_Pelvis_cube,actor,Bip01_Pelvis);
		X3D_ObjectClueToBone(Bip01_Spine_cube,actor,Bip01_Spine);
		X3D_ObjectClueToBone(Bip01_Spine1_cube,actor,Bip01_Spine1);
		X3D_ObjectClueToBone(Bip01_Spine2_cube,actor,Bip01_Spine2);
		X3D_ObjectClueToBone(Bip01_Spine3_cube,actor,Bip01_Spine3);
		X3D_ObjectClueToBone(Bip01_Neck_cube,actor,Bip01_Neck);
		X3D_ObjectClueToBone(Bip01_R_Arm_cube,actor,Bip01_R_Arm);
		X3D_ObjectClueToBone(Bip01_R_Arm1_cube,actor,Bip01_R_Arm1);
		X3D_ObjectClueToBone(Bip01_R_Arm2_cube,actor,Bip01_R_Arm2);
		X3D_ObjectClueToBone(Bip01_R_Hand_cube,actor,Bip01_R_Hand);
		
		if (GetKeyState('1')      & 0x80)
		{
			X3D_ObjectHide(weapon); 
			weapon=pistol; 
			X3D_ObjectShow(weapon);
		}
		if (GetKeyState('2')      & 0x80)
		{
			X3D_ObjectHide(weapon); 
			weapon=rifle; 
			X3D_ObjectShow(weapon);
		}
		previous_return = current_return;
		if (GetKeyState(VK_RETURN)& 0x80)
			current_return = TRUE;
		else
			current_return = FALSE;
		if (current_return && !previous_return)
		{
			anim+=1;
			if (anim==4) 
				anim=1;
			if (anim==1) 
				X3D_ActorSetAnimationRange(actor,1 ,23); //walk
			if (anim==2) 
				X3D_ActorSetAnimationRange(actor,24,46); //run
			if (anim==3) 
				X3D_ActorSetAnimationRange(actor,47,80); //jump
		}
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
