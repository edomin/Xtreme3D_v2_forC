#ifndef X3D_XTREME3D_H
#define X3D_XTREME3D_H

#define X3D_INCLUDE_WINDOW_ROUTINES /* Undef if you will use external window creation lib */
#define X3D_INCLUDE_TIMER_ROUTINES  /* Undef if you will use external timer lib */
									/* I think it must be makefile options */

#if defined(X3D_INCLUDE_WINDOW_ROUTINES) || defined(X3D_INCLUDE_TIMER_ROUTINES)
	#include <windows.h>
#endif
#ifdef X3D_INCLUDE_TIMER_ROUTINES
	#include <stdint.h>
	#include <time.h>
#endif

#include "actor.h"
#include "b3d.h"
#include "blur.h"
#include "camera.h"
#include "dce.h"
#include "dummycube.h"
#include "engine.h"
#include "firefx.h"
#include "fonttext.h"
#include "fps.h"
#include "freeform.h"
#include "lensflare.h"
#include "light.h"
#include "lines.h"
#include "material.h"
#include "mesh.h"
#include "mirror.h"
#include "mouse.h"
#include "navigator.h"
#include "object.h"
#include "ode.h"
#include "partition.h"
#include "polygon.h"
#include "primitives.h"
#include "shaders.h"
#include "shadowplane.h"
#include "shadowvolume.h"
#include "skybox.h"
#include "skydome.h"
#include "sprite.h"
#include "terrain.h"
#include "thorfx.h"
#include "trail.h"
#include "tree.h"
#include "viewer.h"
#include "water.h"

/* Written by Timur Gafarov <clocktower89@mail.ru> and edited by me */

#define X3D_C_AQUA      16776960.0
#define X3D_C_BLACK     0.0
#define X3D_C_BLUE      16711680.0
#define X3D_C_DKGRAY    4210752.0
#define X3D_C_FUCHSIA   16711935.0
#define X3D_C_GRAY      8421504.0
#define X3D_C_GREEN     32768.0
#define X3D_C_LIME      65280.0
#define X3D_C_LTGRAY    12632256.0
#define X3D_C_MAROON    128.0
#define X3D_C_NAVY      8388608.0
#define X3D_C_OLIVE     32896.0
#define X3D_C_PURPLE    8388736.0
#define X3D_C_RED       255.0
#define X3D_C_SILVER    12632256.0
#define X3D_C_TEAL      8421376.0
#define X3D_C_WHITE     16777215.0
#define X3D_C_YELLOW    65535.0
#define X3D_C_ORANGE    33023.0

#define X3D_OS_INHERITED                      		0.0
#define X3D_OS_NONE                            		1.0
#define X3D_OS_RENDER_FARTHEST_FIRST             	2.0
#define X3D_OS_RENDER_BLENDED_LAST               	3.0
#define X3D_OS_RENDER_NEAREST_FIRST              	4.0

#define X3D_VC_INHERITED                       		0.0
#define X3D_VC_NONE                            		1.0
#define X3D_VC_OBJECT_BASED                     	2.0
#define X3D_VC_HIERARCHICAL                    		3.0

#define X3D_VSM_SYNC                           		0.0
#define X3D_VSM_NO_SYNC                         	1.0

#define X3D_CIM_NONE                           		0.0
#define X3D_CIM_POSITION                       		1.0
#define X3D_CIM_ORIENTATION                    		2.0

#define X3D_CS_PERSPECTIVE                     		0.0
#define X3D_CS_ORTHOGONAL                      		1.0
#define X3D_CS_ORTHO_2D                         	2.0
#define X3D_CS_INFINITE_PERSPECTIVE             	3.0

#define X3D_LS_SPOT                            		0.0
#define X3D_LS_OMNI                            		1.0
#define X3D_LS_PARALLEL                        		2.0

#define X3D_ND_OUTSIDE                         		0.0
#define X3D_ND_INSIDE                          		1.0

#define X3D_AAM_NONE                           		0.0
#define X3D_AAM_PLAY_ONCE                       	1.0
#define X3D_AAM_LOOP                           		2.0
#define X3D_AAM_BOUNCE_FORWARD                  	3.0
#define X3D_AAM_BOUNCE_BACKWARD                 	4.0
#define X3D_AAM_LOOP_BACKWARD                   	5.0

#define X3D_HRS_FULL_GEOMETRY                   	0.0
#define X3D_HRS_TESSELATED                     		1.0

#define X3D_TOT_TESSELATE_ALWAYS                	0.0
#define X3D_TOT_TESSELATE_IF_VISIBLE             	1.0

#define X3D_SC_NO_OVERLAP                       	0.0
#define X3D_SC_CONTAINS_FULLY                   	1.0
#define X3D_SC_CONTAINS_PARTIALLY               	2.0

#define X3D_PM_FILL                            		0.0
#define X3D_PM_LINES                           		1.0
#define X3D_PM_POINTS                          		2.0

#define X3D_TMM_USER                           		0.0
#define X3D_TMM_OBJECT_LINEAR                   	1.0
#define X3D_TMM_EYE_LINEAR                      	2.0
#define X3D_TMM_SPHERE                         		3.0
#define X3D_TMM_CUBE_MAP_REFLECTION              	4.0
#define X3D_TMM_CUBE_MAP_NORMAL                  	5.0
#define X3D_TMM_CUBE_MAP_LIGHT_0                  	6.0
#define X3D_TMM_CUBE_MAP_CAMERA                  	7.0

#define X3D_TIA_DEFAULT                       		0.0
#define X3D_TIA_ALPHA_FROM_INTENSITY            	1.0
#define X3D_TIA_SUPER_BLACK_TRANSPARENT         	2.0
#define X3D_TIA_LUMINANCE                     		3.0
#define X3D_TIA_LUMINANCE_SQRT                 		4.0
#define X3D_TIA_OPAQUE                         		5.0
#define X3D_TIA_TOP_LEFT_POINT_COLOR_TRANSPARENT   	6.0
#define X3D_TIA_INVERSE_LUMINANCE               	7.0
#define X3D_TIA_INVERSE_LUMINANCE_SQRT           	8.0

#define X3D_TM_DECAL                           		0.0
#define X3D_TM_MODULATE                        		1.0
#define X3D_TM_BLEND                           		2.0
#define X3D_TM_REPLACE                         		3.0

#define X3D_BM_OPAQUE                          		0.0
#define X3D_BM_TRANSPARENCY                    		1.0
#define X3D_BM_ADDITIVE                        		2.0
#define X3D_BM_ALPHA_TEST_50                     	3.0
#define X3D_BM_ALPHA_TEST_100                    	4.0
#define X3D_BM_MODULATE                        		5.0

#define X3D_MI_NEAREST                         		0.0
#define X3D_MI_LINEAR                          		1.0
#define X3D_MI_NEAREST_MIPMAP_NEAREST            	2.0
#define X3D_MI_LINEAR_MIPMAP_NEAREST             	3.0
#define X3D_MI_NEAREST_MIPMAP_LINEAR             	4.0
#define X3D_MI_LINEAR_MIPMAP_LINEAR              	5.0

#define X3D_MA_NEAREST                         		0.0
#define X3D_MA_LINEAR                          		1.0

#define X3D_FC_CULL                            		1.0
#define X3D_FC_NO_CULL                          	2.0

#define X3D_TF_DEFAULT                         		0.0
#define X3D_TF_RGB                             		1.0
#define X3D_TF_RGBA                            		2.0
#define X3D_TF_RGB_16                          		3.0
#define X3D_TF_RGBA_16                         		4.0
#define X3D_TF_ALPHA                          		5.0
#define X3D_TF_LUMINANCE                      		6.0
#define X3D_TF_LUMINANCE_ALPHA                 		7.0
#define X3D_TF_INTENSITY                      		8.0
#define X3D_TF_NORMAL_MAP                      		9.0
#define X3D_TF_RGBA_FLOAT_16                    	10.0
#define X3D_TF_RGBA_FLOAT_32                    	11.0

#define X3D_TC_DEFAULT                        		0.0
#define X3D_TC_NONE                           		1.0
#define X3D_TC_STANDARD                       		2.0
#define X3D_TC_HIGH_QUALITY                    		3.0
#define X3D_TC_HIGH_SPEED                      		4.0
 
#define X3D_TF_ISOTROPIC                      		0.0
#define X3D_TF_ANISOTROPIC                    		1.0

#define X3D_P_NONE                            		0.0
#define X3D_P_GLOSSY                          		1.0
#define X3D_P_BEAST_VIEW                       		2.0
#define X3D_P_OCEAN_DEPTH                      		3.0
#define X3D_P_DREAM                           		4.0
#define X3D_P_OVER_BLUR                        		5.0

#define X3D_SBM_TOP                           		0.0
#define X3D_SBM_BOTTOM                        		1.0
#define X3D_SBM_LEFT                          		2.0

#define X3D_SBM_RIGHT                         		3.0
#define X3D_SBM_FRONT                         		4.0
#define X3D_SBM_BACK                          		5.0
#define X3D_SBM_CLOUDS                        		6.0

#define X3D_SBS_FULL                          		0.0
#define X3D_SBS_TOP_HALF                       		1.0
#define X3D_SBS_BOTTOM_HALF                    		2.0
#define X3D_SBS_TOP_TWO_THIRDS                  	3.0
#define X3D_SBS_TOP_HALF_CLAMPED                	4.0

#define X3D_LSM_LINES                         		0.0
#define X3D_LSM_CUBIC_SPLINE                   		1.0
#define X3D_LSM_BEZIER_SPLINE                  		2.0
#define X3D_LSM_NURBS_CURVE                    		3.0
#define X3D_LSM_SEGMENTS                      		4.0

#define X3D_LNA_INVISIBLE                     		0.0
#define X3D_LNA_AXES                          		1.0
#define X3D_LNA_CUBE                          		2.0
#define X3D_LNA_DODECAHEDRON                  		3.0

#define X3D_MS_UP                             		0.0
#define X3D_MS_DIRECTION                      		1.0
#define X3D_MS_FACE_CAMERA                     		2.0

#define X3D_SVM_ACCURATE                      		0.0
#define X3D_SVM_DARKENING                     		1.0
#define X3D_SVM_OFF                           		2.0

#define X3D_CCS_DCE_STANDARD                   		0.0
#define X3D_CCS_COLLISION_STANDARD             		1.0
#define X3D_CCS_HYBRID                        		1.0

#define X3D_CSB_SLIDE                         		0.0
#define X3D_CSB_BOUNCE                        		1.0

#define X3D_CS_ELLIPSOID                      		0.0
#define X3D_CS_BOX                            		1.0
#define X3D_CS_FREEFORM                       		1.0

#define X3D_OSM_STEP                          		0.0
#define X3D_OSM_STEP_FAST                      		1.0
#define X3D_OSM_QUICK_STEP                     		1.0

#define X3D_CM_FINE_CULLING                    		0.0
#define X3D_CM_GROSS_CULLING                   		1.0

/* Errorcodes */
#define X3D_ERR_UNKNOWN 							0 /* No error or unknown error */
#ifdef X3D_INCLUDE_WINDOW_ROUTINES
	#define X3D_ERR_MH 								1 /* Could not get module handle */
	#define X3D_ERR_RWC 							2 /* Could not register window class */
	#define X3D_ERR_SM 								3 /* Could not get system metrics */
	#define X3D_ERR_CW 								4 /* Could not create window */
	#define X3D_ERR_DW 								5 /* Could not destroy window */
	/* ChangeDisplaySettings errors. */
	/* See http://msdn.microsoft.com/library/windows/desktop/dd183411.aspx for DISP_CHANGE_ errorcodes descriptions */
	#define X3D_ERR_CDS_CR 							(1000 + DISP_CHANGE_RESTART)
	#define X3D_ERR_CDS_CF 							(1000 + DISP_CHANGE_FAILED)
	#define X3D_ERR_CDS_CBM 						(1000 + DISP_CHANGE_BADMODE)
	#define X3D_ERR_CDS_CNU 						(1000 + DISP_CHANGE_NOTUPDATED)
	#define X3D_ERR_CDS_CBF 						(1000 + DISP_CHANGE_BADFLAGS)
	#define X3D_ERR_CDS_CBP 						(1000 + DISP_CHANGE_BADPARAM)
#endif

void X3D_Init(void);
void X3D_Quit(void);
#ifdef X3D_INCLUDE_WINDOW_ROUTINES
	HWND X3D_WindowCreate(int width, int height, int depth, BOOL fullscreen, char *caption);
	int X3D_WindowDestroy(HWND hwnd);
	BOOL X3D_WindowXed();
#endif
#ifdef X3D_INCLUDE_TIMER_ROUTINES
	void X3D_TimerStart(void);
	uint32_t X3D_TimerDelay(uint32_t ms);
	uint32_t X3D_TimerDelayForFPS(uint32_t fps);
#endif
int X3D_GetLastErrorCode(void);

#endif
