#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	hwnd = (HWND)X3D_WindowCreate(s_width, s_height, 32, FALSE, "Xtreme3D FPS Demo");
    X3D_EngineCreate((double)((int)hwnd));        
    X3D_MouseShowCursor(0);    
    
    double matlib = X3D_MaterialLibraryCreate();
    X3D_MaterialLibraryActivate(matlib); 
    
    double view1 = X3D_ViewerCreate(0,0,s_width,s_height); 
	
    X3D_ViewerSetLighting(view1,1);
    X3D_ViewerSetBackgroundColor(view1,X3D_C_BLACK);
    X3D_ViewerEnableFog(view1,1);
    X3D_ViewerSetFogColor(view1,X3D_C_BLACK);
    X3D_ViewerSetFogDistance(view1,100,250);
    X3D_ViewerEnableVSync(view1,X3D_VSM_NO_SYNC);
    
    // double back = X3D_DummycubeCreate(0);
	X3D_DummycubeCreate(0); /* back */
    double scene = X3D_DummycubeCreate(0); 
    double front = X3D_DummycubeCreate(0);
    
    X3D_MaterialCreate("plane_tex","xception/fps_demo/texture.png", 0);

	double pick_object=X3D_DummycubeCreate(scene);
	int maxobjects=20;
	int i;
	int type[20];
	int number[2];
	int status[20];
	double object[20];
	char *name[20];

	time_t t;
	srand((unsigned)time(&t));
	
	for (i=1; i<maxobjects+1; i+=1)
	{
		type[i]=(int)(rand()%2);
		if (type[i]==0) 
		{
			object[i]=X3D_CubeCreate(8,8,8,pick_object); 
			name[i]="Cube";
		}
		if (type[i]==1) 
		{
			object[i]=X3D_SphereCreate(4,24,16,pick_object); 
			name[i]="Sphere";
		}
		number[type[i]]=0;
		X3D_ObjectSetPosition(object[i],rand()%250,10,rand()%250);
		status[i]=0;
	}

	double plane=X3D_PlaneCreate(0,1000,1000,25,25,scene);
	X3D_ObjectRotate(plane,90,0,0);
	X3D_ObjectSetMaterial(plane,"plane_tex");

	double camPos=X3D_DummycubeCreate(scene);
	X3D_ObjectSetPosition(camPos,0,20,40);
	double camera=X3D_CameraCreate(camPos);
	X3D_CameraSetViewDepth(camera,5000);
	X3D_ViewerSetCamera(view1,camera);
	double camTurn_angle_target=0;
	double camTurn_angle_current=0;
	double camPitch_angle_target=0;
	double camPitch_angle_current=0;
	double camMouseSensitivity=6;
	double camSmooth=16;

	double spot=X3D_LightCreate(X3D_LS_SPOT,camera);
	double collision_sphere=X3D_SphereCreate(5,24,1,camera);
	X3D_ObjectHide(collision_sphere);

	double shoe_size=0.10;
	double head_bang_X=1.6/1.5;
	double head_bang_Y=1.5/1.5;
	double a1=0;
	double walking=0;
	double footstep_needed=1;

	double font_arial20=X3D_WindowsBitmapfontCreate("Arial",20);
	char message_text[256]=" ";
	double message_status=0;
	double message_color=X3D_C_WHITE;
	double message_alpham=1.5;
	double message_alphav=message_alpham;
	double message=X3D_HUDTextCreate(font_arial20,message_text,front);
	X3D_TextSetColor(message,message_color,message_alphav);
	X3D_ObjectSetPosition(message,8,8,0);

	double font_arial10=X3D_WindowsBitmapfontCreate("Arial",10);
	double counter1=X3D_HUDTextCreate(font_arial10,"Cubes: 0",front);
	X3D_TextSetColor(counter1,X3D_C_WHITE,0.5);
	X3D_ObjectSetPosition(counter1,8,480-20,0);
	double counter2=X3D_HUDTextCreate(font_arial10,"Spheres: 0",front);
	X3D_TextSetColor(counter2,X3D_C_WHITE,0.5);
	X3D_ObjectSetPosition(counter2,128,480-20,0);
    
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
	static char counter1_text[256];
	static char counter2_text[256];
	
	double t1;
	double t2;
	double t3;
	double p1;
	double p2;
	double p3;

    /* Program main loop */
    while ((!X3D_WindowXed()) && (!app_quit))
    {
		X3D_TimerStart();
		
		for (i=1; i<maxobjects+1; i+=1)
		{
			if (status[i]==0)
			{
				X3D_ObjectRotate(object[i],1,1,1);
				if ((BOOL)X3D_ObjectCheckSphereVsCube(collision_sphere,object[i]))
				{
					X3D_ObjectHide(object[i]);
					status[i]=1;
					message_status=1;
					message_alphav=message_alpham;
					sprintf(message_text, "You picked up a %s", name[i]);
					number[type[i]]+=1;
				}
			}
		}
		
		if (message_status==0)
		{
			X3D_ObjectHide(message);
		}
		if (message_status==1)
		{
			X3D_ObjectShow(message);
			if (message_alphav>0) 
				message_alphav-=0.01;
			else 
				message_status=0;
			X3D_TextSetColor(message,message_color,message_alphav);
			X3D_TextSetText(message,message_text);
		}

		sprintf(counter1_text, "Cubes: %.u", number[1]);
		sprintf(counter2_text, "Spheres: %.u", number[2]);
		X3D_TextSetText(counter1,counter1_text);
		X3D_TextSetText(counter2,counter2_text);
		
		if (GetKeyState('W')      & 0x80) 
		{
			X3D_ObjectMove(camPos,  -1);
			walking = 1;
		}
		else if (GetKeyState('S')      & 0x80)
		{
			X3D_ObjectMove(camPos,  1);
			walking = 1;
		}
		else
			walking = 0; 
		if (GetKeyState('A')      & 0x80) X3D_ObjectStrafe(camPos, 1);
		if (GetKeyState('D')      & 0x80) X3D_ObjectStrafe(camPos,-1);
		if (GetKeyState(VK_ESCAPE)& 0x80) app_quit = TRUE;
		
		deltax = (mx-X3D_MouseGetX())/camMouseSensitivity;
		deltay = (my-X3D_MouseGetY())/camMouseSensitivity;
		X3D_MouseSetPosition(mx,my);
		camTurn_angle_target+=deltax;
		t1=camTurn_angle_target;
		t2=camTurn_angle_current;
		t3=(t1-t2)/camSmooth;
		camTurn_angle_current+=t3;
		X3D_ObjectRotate(camPos,0,t3,0);

		camPitch_angle_target+=deltay;
		p1=camPitch_angle_target;
		p2=camPitch_angle_current;
		p3=(p1-p2)/camSmooth;
		pit=X3D_ObjectGetPitch(camera)+p3;
		if (pit<89 && pit>-89)
		{
			camPitch_angle_current+=p3;
			X3D_ObjectRotate(camera,p3,0,0);
		}

		if (walking==1) 
		{
			a1=(double)((int)(a1+shoe_size) % 360);
			if (sin(90+a1*2)<-0.85)
			{
				if (footstep_needed!=0)
				{
					if (cos(a1)<0) 
						;//sound_play(sfx_step1);
					if (cos(a1)>0)  
						;//sound_play(sfx_step2);
				}
				footstep_needed=0;
			}
			else
			{
				footstep_needed=1;
			}
		}
		X3D_ObjectSetPosition(camera,cos(a1)*head_bang_X,sin(90+a1*2)*head_bang_Y,0);
		
		X3D_Update();
		X3D_ViewerRender(view1);
		
		sprintf(FPS, "FPS = %.u", X3D_TimerDelayForFPS(120));
		X3D_TextSetText(text_fps, FPS);
    }

    X3D_EngineDestroy();
	X3D_WindowDestroy(hwnd);
    X3D_Quit();
	
	return 0;
}
