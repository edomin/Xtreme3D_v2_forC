#ifndef XTREME3D_2C_H
#define XTREME3D_2C_H

#define X3D_INCLUDE_WINDOW_ROUTINES /* Undef if you will use other window creation lib */

#include <windows.h>

/* Errorcodes */
#define X3D_ERR_UNKNOWN 	0 /* No error or unknown error */
#ifdef X3D_INCLUDE_WINDOW_ROUTINES
	#define X3D_ERR_MH 		1 /* Could not get module handle */
	#define X3D_ERR_RWC 	2 /* Could not register window class */
	#define X3D_ERR_SM 		3 /* Could not get system metrics */
	#define X3D_ERR_CW 		4 /* Could not create window */
	#define X3D_ERR_DW 		5 /* Could not destroy window */
	/* ChangeDisplaySettings errors. */
	/* See http://msdn.microsoft.com/library/windows/desktop/dd183411.aspx for DISP_CHANGE_ errorcodes descriptions */
	#define X3D_ERR_CDS_CR 	(1000 + DISP_CHANGE_RESTART)
	#define X3D_ERR_CDS_CF 	(1000 + DISP_CHANGE_FAILED)
	#define X3D_ERR_CDS_CBM (1000 + DISP_CHANGE_BADMODE)
	#define X3D_ERR_CDS_CNU (1000 + DISP_CHANGE_NOTUPDATED)
	#define X3D_ERR_CDS_CBF (1000 + DISP_CHANGE_BADFLAGS)
	#define X3D_ERR_CDS_CBP (1000 + DISP_CHANGE_BADPARAM)
#endif

/* Written by Timur Gafarov <clocktower89@mail.ru> and edited by me */
typedef double (__stdcall * dFUNC)    ();
typedef double (__stdcall * dFUNC1d)  (double);
typedef double (__stdcall * dFUNC2d)  (double,double); 
typedef double (__stdcall * dFUNC3d)  (double,double,double); 
typedef double (__stdcall * dFUNC4d)  (double,double,double,double);
typedef double (__stdcall * dFUNC5d)  (double,double,double,double,double);
typedef double (__stdcall * dFUNC6d)  (double,double,double,double,double,double);
typedef double (__stdcall * dFUNC7d)  (double,double,double,double,double,double,double);
typedef double (__stdcall * dFUNC8d)  (double,double,double,double,double,double,double,double);
typedef double (__stdcall * dFUNC9d)  (double,double,double,double,double,double,double,double,double);
typedef double (__stdcall * dFUNC10d) (double,double,double,double,double,double,double,double,double,double);

typedef char * (__stdcall * pFUNC1d)  (double);
typedef double (__stdcall * dFUNC1p)  (char *); 
typedef double (__stdcall * dFUNC2p)  (char *,char *); 
typedef double (__stdcall * dFUNCdp)  (double,char *); 
typedef double (__stdcall * dFUNCpd)  (char *,double); 
typedef double (__stdcall * dFUNCppd) (char *,char *,double); 
typedef double (__stdcall * dFUNCpdd) (char *,double,double); 
typedef double (__stdcall * dFUNCddp) (double,double,char *);
typedef double (__stdcall * dFUNCdpd) (double,char *,double);
typedef double (__stdcall * dFUNCdpdd)(double,char *,double,double);
typedef double (__stdcall * dFUNCpddd)(char *,double,double,double);
typedef double (__stdcall * dFUNCdppp)(double,char *,char *,char *);

HMODULE hLibXtreme3D;
#ifdef X3D_INCLUDE_WINDOW_ROUTINES
	MSG msg;
	DEVMODE sDevMode;
	int s_real_width;
	int s_real_height;
	BOOL s_fullscreen;
	BOOL X3D_XED;
#endif

int X3D_ERR;

/* Written by Timur Gafarov <clocktower89@mail.ru> then ripped and edited by me */
/* actor */
dFUNCpd  X3D_ActorCreate;
dFUNC2d  X3D_ActorCopy;
dFUNC3d  X3D_ActorSetAnimationRange;
dFUNC1d  X3D_ActorGetCurrentFrame;
dFUNC2d  X3D_ActorSwitchToAnimation;
dFUNC2d  X3D_ActorSynchronize;
dFUNC2d  X3D_ActorSetInterval;
dFUNC2d  X3D_ActorSetAnimationMode;
dFUNC2d  X3D_ActorSetFrameInterpolation;
dFUNCdp  X3D_ActorAddObject;
pFUNC1d  X3D_ActorGetCurrentAnimation;
dFUNC1d  X3D_ActorGetFrameCount;
dFUNC1d  X3D_ActorGetBoneCount;
dFUNCdp  X3D_ActorGetBoneByName;
dFUNC5d  X3D_ActorRotateBone;
dFUNC3d  X3D_ObjectClueToBone;
dFUNC3d  X3D_ActorGetBoneRotation;
dFUNC5d  X3D_ActorMoveBone;
dFUNC3d  X3D_ActorGetBonePosition;
dFUNC2d  X3D_ActorShowSkeleton;

/* b3d */
dFUNCpd  X3D_LoadB3D;
dFUNC    X3D_ClearZones;
dFUNC    X3D_ZonesVisible;
dFUNC2d  X3D_CullZones;
dFUNC2d  X3D_ZoneAddPortal;
dFUNC2d  X3D_ZoneObjectInZone;
dFUNC1d  X3D_ZoneGetCurrent;
dFUNC2d  X3D_ZoneGetNew;
dFUNC1d  X3D_ZoneAdjustSize;
dFUNC2d  X3D_CreateZones;
dFUNC1d  X3D_ZoneGetPortalCount;
dFUNC2d  X3D_ZoneGetPortal;

/* blur */
dFUNC1d  X3D_BlurCreate;
dFUNC2d  X3D_BlurSetPreset;
dFUNC6d  X3D_BlurSetOptions;
dFUNC2d  X3D_BlurSetResolution;

/* camera */
dFUNC1d   X3D_CameraCreate;
dFUNC2d   X3D_CameraSetStyle;
dFUNC2d   X3D_CameraSetFocal;
dFUNC2d   X3D_CameraSetSceneScale;
dFUNC2d   X3D_CameraScaleScene;
dFUNC2d   X3D_CameraSetViewDepth;
dFUNC2d   X3D_CameraSetTargetObject;
dFUNC3d   X3D_CameraMoveAroundTarget;
dFUNC2d   X3D_CameraSetDistanceToTarget;
dFUNC1d   X3D_CameraGetDistanceToTarget;
dFUNCdpdd X3D_CameraCopyToTexture;

/* dce */
dFUNC    X3D_DceManagerCreate;
dFUNC2d  X3D_DceManagerStep;
dFUNC4d  X3D_DceManagerSetWorldDirection;
dFUNC2d  X3D_DceManagerSetWorldScale;
dFUNC2d  X3D_DceManagerSetMovementScale;
dFUNC2d  X3D_DceManagerSetLayers;
dFUNC2d  X3D_DceManagerSetManualStep;
dFUNC2d  X3D_DceSetManager;
dFUNC2d  X3D_DceSetActive;
dFUNC1d  X3D_DceIsActive;
dFUNC2d  X3D_DceSetUseGravity;
dFUNC2d  X3D_DceSetLayer;
dFUNC1d  X3D_DceGetLayer;
dFUNC2d  X3D_DceSetSolid;
dFUNC2d  X3D_DceSetFriction;
dFUNC2d  X3D_DceSetBounce;
dFUNC4d  X3D_DceSetSize;
dFUNC2d  X3D_DceSetSlideOrBounce;
dFUNC4d  X3D_DceApplyAcceleration;
dFUNC4d  X3D_DceApplyAbsAcceleration;
dFUNC1d  X3D_DceStopAcceleration;
dFUNC1d  X3D_DceStopAbsAcceleration;
dFUNC3d  X3D_DceJump;
dFUNC5d  X3D_DceMove;
dFUNC5d  X3D_DceMoveTo;
dFUNC4d  X3D_DceSetSpeed;
dFUNC1d  X3D_DceInGround;
dFUNC2d  X3D_DceSetMaxRecursionDepth;
dFUNC2d  X3D_DceStaticSetManager;
dFUNC2d  X3D_DceStaticSetActive;
dFUNC2d  X3D_DceStaticSetShape;
dFUNC2d  X3D_DceStaticSetLayer;
dFUNC4d  X3D_DceStaticSetSize;
dFUNC2d  X3D_DceStaticSetSolid;
dFUNC2d  X3D_DceStaticSetFriction;
dFUNC2d  X3D_DceStaticSetBounceFactor;
dFUNC2d  X3D_DceGetVelocity;
dFUNC2d  X3D_DceGetGravity;
dFUNC1d  X3D_DceVelocityCollided;
dFUNC1d  X3D_DceGravityCollided;
dFUNC1d  X3D_DceCountCollisions;
dFUNC2d  X3D_DceGetCollidedObject;
dFUNC3d  X3D_DceGetCollisionPosition;
dFUNC3d  X3D_DceGetCollisionNormal;

/* dummycube */
dFUNC1d  X3D_DummycubeCreate;
dFUNC2d  X3D_DummycubeAmalgamate;
dFUNC2d  X3D_DummycubeSetCameraMode;

/* engine */
dFUNC1d  X3D_EngineCreate;
dFUNC    X3D_EngineDestroy;
dFUNC1d  X3D_EngineSetObjectsSorting;
dFUNC1d  X3D_EngineSetCulling;
dFUNC    X3D_EngineGetMaxTextureSize;
dFUNC    X3D_EngineGetMaxTextureUnits;
dFUNC1p  X3D_SetPakArchive;
dFUNC    X3D_Update;
dFUNC    X3D_TrisRendered;

/* firefx */
dFUNC    X3D_FireFXManagerCreate;
dFUNC2d  X3D_FireFXCreate;
dFUNC5d  X3D_FireFXSetColor;
dFUNC2d  X3D_FireFXSetMaxParticles;
dFUNC2d  X3D_FireFXSetParticleSize;
dFUNC2d  X3D_FireFXSetDensity;
dFUNC2d  X3D_FireFXSetEvaporation;
dFUNC2d  X3D_FireFXSetCrown;
dFUNC2d  X3D_FireFXSetLife;
dFUNC2d  X3D_FireFXSetBurst;
dFUNC2d  X3D_FireFXSetRadius;
dFUNC4d  X3D_FireFXExplosion;

/* fonttext */
dFUNC8d   X3D_BmpfontCreate;
dFUNCdp   X3D_BmpfontLoad;
dFUNCpd   X3D_WindowsBitmapfontCreate;
dFUNCdpd  X3D_FlatTextCreate;
dFUNCdpd  X3D_HUDTextCreate;
dFUNC2d   X3D_HUDTextSetRotation;
dFUNCdpdd X3D_SpaceTextCreate;
dFUNC2d   X3D_SpaceTextSetExtrusion;
dFUNC3d   X3D_TextSetColor;
dFUNC2d   X3D_TextSetFont;
dFUNCdp   X3D_TextSetText;

/* fps */
dFUNC    X3D_FpsManagerCreate;
dFUNC2d  X3D_FpsManagerSetNavigator;
dFUNC2d  X3D_FpsManagerSetMovementScale;
dFUNC2d  X3D_FpsManagerAddMap;
dFUNC2d  X3D_FpsManagerRemoveMap;
dFUNC2d  X3D_FPSMapSetGroup;
dFUNC2d  X3D_FpsSetManager;
dFUNC2d  X3D_FpsSetGroup;
dFUNC1d  X3D_FpsSetSphereRadius;
dFUNC2d  X3D_FpsSetGravity;
dFUNC2d  X3D_FpsMove;
dFUNC2d  X3D_FpsStrafe;
dFUNC2d  X3D_FpsLift;
dFUNC2d  X3D_FpsGetVelocity;
dFUNC1d  X3D_FpsCountCollisions;
dFUNC1d  X3D_FpsClearCollisions;
dFUNC3d  X3D_FpsGetCollisionPosition;
dFUNC3d  X3D_FpsGetCollisionNormal;
dFUNC2d  X3D_FpsGetCollidedObject;

/* freeform */
dFUNCpd  X3D_FreeformCreate;
dFUNC4d  X3D_FreeformPointInMesh;
dFUNC4d  X3D_FreeformSphereSweepIntersect;
dFUNC4d  X3D_FreeformToFreeforms;
dFUNC2d  X3D_FreeformSetSecondTextureCoords;

/* lensfrare */
dFUNC1d  X3D_LensflareCreate;
dFUNC2d  X3D_LensflareSetSize;
dFUNC2d  X3D_LensflareSetSeed;
dFUNC2d  X3D_LensflareSetSqueeze;
dFUNC2d  X3D_LensflareSetStreaks;
dFUNC2d  X3D_LensflareSetStreakwidth;
dFUNC2d  X3D_LensflareSetSecs;
dFUNC2d  X3D_LensflareSetResolution;
dFUNC6d  X3D_LensflareSetElements;
dFUNC6d  X3D_LensflareSetGradients;

/* light */
dFUNC2d  X3D_LightCreate;
dFUNC2d  X3D_LightSetAmbientColor;
dFUNC2d  X3D_LightSetDiffuseColor;
dFUNC2d  X3D_LightSetSpecularColor;
dFUNC4d  X3D_LightSetAttenuation;
dFUNC2d  X3D_LightSetShining;
dFUNC2d  X3D_LightSetSpotCutoff;
dFUNC2d  X3D_LightSetSpotExponent;
dFUNC4d  X3D_LightSetSpotDirection;
dFUNC2d  X3D_LightSetStyle;

/* lines */
dFUNC1d  X3D_LinesCreate;
dFUNC4d  X3D_LinesAddNode;
dFUNC2d  X3D_LinesDeleteNode;
dFUNC5d  X3D_LinesSetColors;
dFUNC3d  X3D_LinesSetSize;
dFUNC2d  X3D_LinesSetSplineMode;
dFUNC2d  X3D_LinesSetNodesAspect;
dFUNC2d  X3D_LinesSetDivision;

/* material */
dFUNC    X3D_MaterialLibraryCreate;
dFUNC1d  X3D_MaterialLibraryActivate;
dFUNCdp  X3D_MaterialLibrarySetTexturePaths;
dFUNC1d  X3D_MaterialLibraryClear;
dFUNC1d  X3D_MaterialLibraryDeleteUnused;
dFUNCppd X3D_MaterialCreate;
dFUNC1p  X3D_MaterialAddCubeMap;
dFUNC2p  X3D_MaterialCubeMapLoadImage;
dFUNCpdd X3D_MaterialCubeMapFromScene;
dFUNCpdd X3D_MaterialSetAmbientColor;
dFUNCpdd X3D_MaterialSetDiffuseColor;
dFUNCpdd X3D_MaterialSetEmissionColor;
dFUNCpdd X3D_MaterialSetSpecularColor;
dFUNCpd  X3D_MaterialSetShininess;
dFUNCpd  X3D_MaterialSetPolygonMode;
dFUNCpd  X3D_MaterialSetTextureMappingMode;
dFUNCpd  X3D_MaterialSetTextureImageAlpha;
dFUNCpdd X3D_MaterialSetTextureScale;
dFUNC2p  X3D_MaterialGetFromLib;
dFUNCpdd X3D_MaterialSetTextureOffset;
dFUNCpd  X3D_MaterialSetTextureMode;
dFUNCpd  X3D_MaterialSetBlendingMode;
dFUNCpdd X3D_MaterialSetTextureFilter;
dFUNCpd  X3D_MaterialDisableTexture;
dFUNC2p  X3D_MaterialLoadTexture;
dFUNC    X3D_MaterialGetCount;
pFUNC1d  X3D_MaterialGetName;
dFUNCpd  X3D_MaterialSetFaceCulling;
dFUNC2p  X3D_MaterialSetSecondTexture;
dFUNCpd  X3D_MaterialSetTextureFormat;
dFUNCpd  X3D_MaterialSetTextureCompression;
dFUNC1p  X3D_MaterialTextureRequiredMemory;
dFUNCpd  X3D_MaterialSetFilteringQuality;
dFUNCpdd X3D_MaterialSetOptions;
dFUNCpd  X3D_MaterialSetShader;
dFUNC2p  X3D_MaterialAddTextureEx;
dFUNC1p  X3D_MaterialTextureExClear;
dFUNCpd  X3D_MaterialTextureExDelete;

/* mesh */
dFUNC1d  X3D_MeshCountObjects;
dFUNC5d  X3D_MeshRotate;
dFUNC6d  X3D_MeshExplode;
dFUNC3d  X3D_MeshSetVisible;
dFUNC2d  X3D_MeshCountVertices;
dFUNC1d  X3D_MeshOptimize;
dFUNC3d  X3D_MeshSmoothFaces;

/* mirror */
dFUNC2d  X3D_MirrorCreate;
dFUNC2d  X3D_MirrorSetObject;
dFUNC5d  X3D_MirrorSetOptions;

/* mouse */
dFUNC    X3D_MouseGetX;
dFUNC    X3D_MouseGetY;
dFUNC2d  X3D_MouseSetPosition;
dFUNC1d  X3D_MouseShowCursor;

/* navigator */
dFUNC    X3D_NavigatorCreate;
dFUNC2d  X3D_NavigatorSetObject;
dFUNC2d  X3D_NavigatorSetUseVirtualUp;
dFUNC4d  X3D_NavigatorSetVirtualUp;
dFUNC2d  X3D_NavigatorTurnHorizontal;
dFUNC2d  X3D_NavigatorTurnVertical;
dFUNC2d  X3D_NavigatorMoveForward;
dFUNC2d  X3D_NavigatorStrafeHorizontal;
dFUNC2d  X3D_NavigatorStrafeVertical;
dFUNC1d  X3D_NavigatorStraighten;
dFUNC2d  X3D_NavigatorFlyForward;
dFUNC2d  X3D_NavigatorMoveUpWhenMovingForward;
dFUNC2d  X3D_NavigatorInvertHorizontalWhenUpsideDown;
dFUNC2d  X3D_NavigatorSetAngleLock;
dFUNC3d  X3D_NavigatorSetAngles;

/* object */
dFUNC1d  X3D_ObjectHide;
dFUNC1d  X3D_ObjectShow;
dFUNC1d  X3D_ObjectIsVisible;
dFUNC2d  X3D_ObjectCopy;
dFUNC1d  X3D_ObjectDestroy;
dFUNC4d  X3D_ObjectSetPosition;
dFUNC2d  X3D_ObjectGetPosition;
dFUNC2d  X3D_ObjectGetAbsolutePosition;
dFUNC2d  X3D_ObjectSetPositionOfObject;
dFUNC2d  X3D_ObjectAlignWithObject;
dFUNC2d  X3D_ObjectSetPositionX;
dFUNC2d  X3D_ObjectSetPositionY;
dFUNC2d  X3D_ObjectSetPositionZ;
dFUNC4d  X3D_ObjectSetAbsolutePosition;
dFUNC4d  X3D_ObjectSetDirection;
dFUNC2d  X3D_ObjectGetDirection;
dFUNC4d  X3D_ObjectSetAbsoluteDirection;
dFUNC2d  X3D_ObjectGetAbsoluteDirection;
dFUNC1d  X3D_ObjectGetPitch;
dFUNC1d  X3D_ObjectGetTurn;
dFUNC1d  X3D_ObjectGetRoll;
dFUNC4d  X3D_ObjectSetRotation;
dFUNC2d  X3D_ObjectMove;
dFUNC2d  X3D_ObjectLift;
dFUNC4d  X3D_ObjectTranslate;
dFUNC2d  X3D_ObjectStrafe;
dFUNC4d  X3D_ObjectRotate;
dFUNC4d  X3D_ObjectScale;
dFUNC4d  X3D_ObjectSetScale;
dFUNC4d  X3D_ObjectSetUpVector;
dFUNC2d  X3D_ObjectPointToObject;
dFUNC2d  X3D_ObjectAlignToCamera;
dFUNC3d  X3D_ObjectGetAtXY;
dFUNC2d  X3D_ObjectShowAxes;
dFUNC2d  X3D_ObjectGetGroundHeight;
dFUNC2d  X3D_ObjectSceneRaycast;
dFUNC2d  X3D_ObjectRaycast;
dFUNC1d  X3D_ObjectGetCollisionPosition;
dFUNC1d  X3D_ObjectGetCollisionNormal;
dFUNC3d  X3D_ObjectSetDiffuseColor;
dFUNCdp  X3D_ObjectSetMaterial;
dFUNC2d  X3D_ObjectGetDistance;
dFUNC2d  X3D_ObjectCheckCubeVsFace;
dFUNC2d  X3D_ObjectCheckCubeVsCube;
dFUNC2d  X3D_ObjectCheckFaceVsFace;
dFUNC2d  X3D_ObjectCheckSphereVsSphere;
dFUNC2d  X3D_ObjectCheckSphereVsCube;
dFUNC4d  X3D_ObjectIsPointInObject;
dFUNC2d  X3D_ObjectSetCulling;
dFUNCdp  X3D_ObjectSetName;
pFUNC1d  X3D_ObjectGetName;
pFUNC1d  X3D_ObjectGetClassName;
dFUNC2d  X3D_ObjectSetID;
dFUNC1d  X3D_ObjectGetID;
dFUNC1d  X3D_ObjectGetParent;
dFUNC1d  X3D_ObjectGetChildCount;
dFUNC2d  X3D_ObjectGetChild;
dFUNC1d  X3D_ObjectGetBoundingsphereRadius;
dFUNC1d  X3D_ObjectGetIndex;
dFUNCdp  X3D_ObjectFindChild;
dFUNC2d  X3D_ObjectGetAbsoluteUp;
dFUNC4d  X3D_ObjectSetAbsoluteUp;
dFUNC2d  X3D_ObjectGetAbsoluteRight;
dFUNC2d  X3D_ObjectGetAbsoluteXVector;
dFUNC2d  X3D_ObjectGetAbsoluteYVector;
dFUNC2d  X3D_ObjectGetAbsoluteZVector;
dFUNC2d  X3D_ObjectGetRight;
dFUNC2d  X3D_ObjectMoveChildUp;
dFUNC2d  X3D_ObjectMoveChildDown;
dFUNC2d  X3D_ObjectSetParent;
dFUNC3d  X3D_ObjectRemoveChild;
dFUNC4d  X3D_ObjectMoveObjectAround;
dFUNC2d  X3D_ObjectPitch;
dFUNC2d  X3D_ObjectTurn;
dFUNC2d  X3D_ObjectRoll;
dFUNC2d  X3D_ObjectGetUpVector;
dFUNC1d  X3D_ObjectStructureChanged;
dFUNC4d  X3D_ObjectRotateAbsolute;
dFUNC5d  X3D_ObjectRotateAbsoluteVector;
dFUNC1d  X3D_ObjectInFrustrum;
dFUNC1d  X3D_ObjectIsClipped;

/* ode */
dFUNC    X3D_OdeManagerCreate;
dFUNC    X3D_OdeManagerDestroy;
dFUNC1d  X3D_OdeManagerStep;
dFUNC    X3D_OdeManagerGetNumContactJoints;
dFUNC3d  X3D_OdeManagerSetGravity;
dFUNC1d  X3D_OdeManagerSetSolver;
dFUNC1d  X3D_OdeManagerSetIterations;
dFUNC1d  X3D_OdeManagerSetMaxContacts;
dFUNC1d  X3D_OdeManagerSetVisible;
dFUNC1d  X3D_OdeManagerSetGeomColor;
dFUNC1d  X3D_OdeWorldSetAutoDisableFlag;
dFUNC1d  X3D_OdeWorldSetAutoDisableLinearThreshold;
dFUNC1d  X3D_OdeWorldSetAutoDisableAngularThreshold;
dFUNC1d  X3D_OdeWorldSetAutoDisableSteps;
dFUNC1d  X3D_OdeWorldSetAutoDisableTime;
dFUNC2d  X3D_OdeDynamicSetAutoDisableFlag;
dFUNC2d  X3D_OdeDynamicSetAutoDisableLinearThreshold;
dFUNC2d  X3D_OdeDynamicSetAutoDisableAngularThreshold;
dFUNC2d  X3D_OdeDynamicSetAutoDisableSteps;
dFUNC2d  X3D_OdeDynamicSetAutoDisableTime;
dFUNC1d  X3D_OdeStaticCreate;
dFUNC1d  X3D_OdeDynamicCreate;
dFUNC1d  X3D_OdeDynamicAlignObject;
dFUNC2d  X3D_OdeDynamicEnable;
dFUNC1d  X3D_OdeDynamicCalibrateCenterOfMass;
dFUNC4d  X3D_OdeDynamicAddForce;
dFUNC7d  X3D_OdeDynamicAddForceAtPos;
dFUNC7d  X3D_OdeDynamicAddForceAtRelPos;
dFUNC4d  X3D_OdeDynamicAddRelForce;
dFUNC7d  X3D_OdeDynamicAddRelForceAtPos;
dFUNC7d  X3D_OdeDynamicAddRelForceAtRelPos;
dFUNC4d  X3D_OdeDynamicAddTorque;
dFUNC4d  X3D_OdeDynamicAddRelTorque;
dFUNC1d  X3D_OdeDynamicGetContactCount;
dFUNC2d  X3D_OdeDynamicGetContact;
dFUNC1d  X3D_OdeStaticGetContactCount;
dFUNC2d  X3D_OdeStaticGetContact;
dFUNC4d  X3D_OdeAddBox;
dFUNC3d  X3D_OdeAddCapsule;
dFUNC3d  X3D_OdeAddCone;
dFUNC3d  X3D_OdeAddCylinder;
dFUNC1d  X3D_OdeAddPlane;
dFUNC2d  X3D_OdeAddSphere;
dFUNC1d  X3D_OdeAddTriMesh;
dFUNC2d  X3D_OdeSurfaceSetRollingFrictionCoeff;
dFUNC2d  X3D_OdeSurfaceEnableRollingFrictionCoeff;
dFUNC10d X3D_OdeSurfaceSetMode;
dFUNC2d  X3D_OdeSurfaceSetMu;
dFUNC2d  X3D_OdeSurfaceSetMu2;
dFUNC2d  X3D_OdeSurfaceSetBounce;
dFUNC2d  X3D_OdeSurfaceSetBounceVel;
dFUNC2d  X3D_OdeSurfaceSetSoftERP;
dFUNC2d  X3D_OdeSurfaceSetSoftCFM;
dFUNC2d  X3D_OdeSurfaceSetMotion1;
dFUNC2d  X3D_OdeSurfaceSetMotion2;
dFUNC2d  X3D_OdeSurfaceSetSlip1;
dFUNC2d  X3D_OdeSurfaceSetSlip2;
dFUNC    X3D_OdeAddJointBall;
dFUNC    X3D_OdeAddJointFixed;
dFUNC    X3D_OdeAddJointHinge;
dFUNC    X3D_OdeAddJointHinge2;
dFUNC    X3D_OdeAddJointSlider;
dFUNC    X3D_OdeAddJointUniversal;
dFUNC3d  X3D_OdeJointSetObjects;
dFUNC2d  X3D_OdeJointEnable;
dFUNC2d  X3D_OdeJointInitialize;
dFUNC4d  X3D_OdeJointSetAnchor;
dFUNC2d  X3D_OdeJointSetAnchorAtObject;
dFUNC4d  X3D_OdeJointSetAxis1;
dFUNC4d  X3D_OdeJointSetAxis2;
dFUNC3d  X3D_OdeJointSetBounce;
dFUNC3d  X3D_OdeJointSetCFM;
dFUNC3d  X3D_OdeJointSetFMax;
dFUNC3d  X3D_OdeJointSetFudgeFactor;
dFUNC3d  X3D_OdeJointSetHiStop;
dFUNC3d  X3D_OdeJointSetLoStop;
dFUNC3d  X3D_OdeJointSetStopCFM;
dFUNC3d  X3D_OdeJointSetStopERP;
dFUNC3d  X3D_OdeJointSetVel;

/* partition */
dFUNC4d  X3D_OctreeCreate;
dFUNC4d  X3D_QuadtreeCreate;
dFUNC1d  X3D_PartitionDestroy;
dFUNC2d  X3D_PartitionAddLeaf;
dFUNC1d  X3D_PartitionLeafChanged;
dFUNC2d  X3D_PartitionQueryFrustrum;
dFUNC2d  X3D_PartitionQueryLeaf;
dFUNC2d  X3D_PartitionQueryAABB;
dFUNC2d  X3D_PartitionQueryBSphere;
dFUNC1d  X3D_PartitionGetNodeTests;
dFUNC1d  X3D_PartitionGetNodeCount;
dFUNC2d  X3D_PartitionGetResult;
dFUNC1d  X3D_PartitionResultShow;
dFUNC1d  X3D_PartitionResultHide;

/* polygon */
dFUNC1d  X3D_PolygonCreate;
dFUNC4d  X3D_PolygonAddVertex;
dFUNC5d  X3D_PolygonSetVertexPosition;
dFUNC2d  X3D_PolygonDeleteVertex;

/* primitives */
dFUNC6d  X3D_PlaneCreate;
dFUNC4d  X3D_CubeCreate;
dFUNC2d  X3D_CubeSetNormalDirection;
dFUNC4d  X3D_SphereCreate;
dFUNC7d  X3D_CylinderCreate;
dFUNC6d  X3D_ConeCreate;
dFUNC7d  X3D_AnnulusCreate;
dFUNC5d  X3D_TorusCreate;
dFUNC7d  X3D_DiskCreate;

/* shaders */
dFUNC2d  X3D_ShaderEnable;
dFUNC1d  X3D_BumpShaderCreate;
dFUNC    X3D_CelShaderCreate;
dFUNC2d  X3D_CelShaderSetLineColor;
dFUNC2d  X3D_CelShaderSetLineWidth;
dFUNC    X3D_HiddenLineShaderCreate;
dFUNC2d  X3D_HiddenLineShaderSetLineSmooth;
dFUNC2d  X3D_HiddenLineShaderSetSolid;
dFUNC2d  X3D_HiddenLineShaderSetSurfaceLit;
dFUNC5d  X3D_HiddenLineShaderSetFrontLine;
dFUNC5d  X3D_HiddenLineShaderSetBackLine;
dFUNC1d  X3D_MultiMaterialShaderCreate;
dFUNC1d  X3D_OutlineShaderCreate;
dFUNC2d  X3D_OutlineShaderSetLineColor;
dFUNC2d  X3D_OutlineShaderSetLineWidth;

/* shadowplane */
dFUNC9d  X3D_ShadowplaneCreate;
dFUNC2d  X3D_ShadowplaneSetLight;
dFUNC2d  X3D_ShadowplaneSetObject;
dFUNC5d  X3D_ShadowplaneSetOptions;

/* shadowvolume */
dFUNC1d  X3D_ShadowvolumeCreate;
dFUNC2d  X3D_ShadowvolumeSetActive;
dFUNC2d  X3D_ShadowvolumeAddLight;
dFUNC2d  X3D_ShadowvolumeRemoveLight;
dFUNC2d  X3D_ShadowvolumeAddOccluder;
dFUNC2d  X3D_ShadowvolumeRemoveOccluder;
dFUNC3d  X3D_ShadowvolumeSetDarkeningColor;
dFUNC2d  X3D_ShadowvolumeSetMode;
dFUNC5d  X3D_ShadowvolumeSetOptions;

/* skybox */
dFUNC1d  X3D_SkyboxCreate;
dFUNCddp X3D_SkyboxSetMaterial;
dFUNC3d  X3D_SkyboxSetClouds;
dFUNC2d  X3D_SkyboxSetStyle;

/* skydome */
dFUNC3d  X3D_SkydomeCreate;
dFUNC3d  X3D_SkydomeSetOptions;
dFUNC2d  X3D_SkydomeSetDeepColor;
dFUNC2d  X3D_SkydomeSetHazeColor;
dFUNC2d  X3D_SkydomeSetNightColor;
dFUNC2d  X3D_SkydomeSetSkyColor;
dFUNC2d  X3D_SkydomeSetSunDawnColor;
dFUNC2d  X3D_SkydomeSetSunZenithColor;
dFUNC2d  X3D_SkydomeSetSunElevation;
dFUNC2d  X3D_SkydomeSetTurbidity;
dFUNC3d  X3D_SkydomeAddRandomStars;
dFUNC1d  X3D_SkydomeClearStars;
dFUNC2d  X3D_SkydomeTwinkleStars;

/* sprite */
dFUNCpddd X3D_HUDSpriteCreate;
dFUNCpddd X3D_SpriteCreate;
dFUNC3d   X3D_SpriteSetSize;
dFUNC3d   X3D_SpriteScale;
dFUNC2d   X3D_SpriteSetRotation;
dFUNC2d   X3D_SpriteRotate;
dFUNC3d   X3D_SpriteMirror;
dFUNC2d   X3D_SpriteNoZWrite;
dFUNC2d   X3D_ObjectUseObjectColor;

/* terrain */
dFUNC1p  X3D_BmpHDSCreate;
dFUNC2d  X3D_BmpHDSSetInfiniteWarp;
dFUNC2d  X3D_BmpHDSSetInverted;
dFUNC1d  X3D_TerrainCreate;
dFUNC2d  X3D_TerrainSetHeightData;
dFUNC2d  X3D_TerrainSetTileSize;
dFUNC2d  X3D_TerrainSetTilesPerTexture;
dFUNC2d  X3D_TerrainSetQualityDistance;
dFUNC2d  X3D_TerrainSetQualityStyle;
dFUNC2d  X3D_TerrainSetMaxCLodTriangles;
dFUNC2d  X3D_TerrainSetCLodPrecision;
dFUNC2d  X3D_TerrainSetOcclusionFrameSkip;
dFUNC2d  X3D_TerrainSetOcclusionTesselate;
dFUNC2d  X3D_TerrainGetHeightAtObjectPosition;
dFUNC1d  X3D_TerrainGetLastTriCount;

/* thorfx */
dFUNC   X3D_ThorFXManagerCreate;
dFUNC2d X3D_ThorFXCreate;
dFUNC7d X3D_ThorFXSetColor;
dFUNC2d X3D_ThorFXEnableCore;
dFUNC2d X3D_ThorFXEnableGlow;
dFUNC2d X3D_ThorFXSetMaxParticles;
dFUNC2d X3D_ThorFXSetGlowSize;
dFUNC2d X3D_ThorFXSetVibrate;
dFUNC2d X3D_ThorFXSetWildness;
dFUNC4d X3D_ThorFXSetTarget;
dFUNC2d X3D_ThorFXSetTargetAsObject;

/* trail */
dFUNC2d   X3D_TrailCreate;
dFUNC2d   X3D_TrailSetObject;
dFUNC3d   X3D_TrailSetAlpha;
dFUNC3d   X3D_TrailSetLimits;
dFUNC2d   X3D_TrailSetMinDistance;
dFUNC2d   X3D_TrailSetUVScale;
dFUNC2d   X3D_TrailSetMarkStyle;
dFUNC2d   X3D_TrailSetMarkWidth;
dFUNC2d   X3D_TrailSetEnabled;
dFUNC1d   X3D_TrailClearMarks;

/* tree */
dFUNC1d   X3D_TreeCreate;
dFUNCdppp X3D_TreeSetMaterials;
dFUNC2d   X3D_TreeSetBranchFacets;
dFUNC2d   X3D_TreeBuildMesh;
dFUNC2d   X3D_TreeSetBranchNoise;
dFUNC2d   X3D_TreeSetBranchAngle;
dFUNC2d   X3D_TreeSetBranchSize;
dFUNC2d   X3D_TreeSetBranchRadius;
dFUNC2d   X3D_TreeSetBranchTwist;
dFUNC2d   X3D_TreeSetDepth;
dFUNC2d   X3D_TreeSetLeafSize;
dFUNC2d   X3D_TreeSetLeafThreshold;
dFUNC2d   X3D_TreeSetSeed;

/* viewer */
dFUNC4d  X3D_ViewerCreate;
dFUNC2d  X3D_ViewerSetCamera;
dFUNC2d  X3D_ViewerEnableVSync;
dFUNC1d  X3D_ViewerRender;
dFUNC5d  X3D_ViewerResize;
dFUNC2d  X3D_ViewerSetVisible;
dFUNC3d  X3D_ViewerGetPixelColor;
dFUNC3d  X3D_ViewerGetPixelDepth;
dFUNC2d  X3D_ViewerSetLighting;
dFUNC2d  X3D_ViewerSetBackgroundColor;
dFUNC2d  X3D_ViewerSetAmbientColor;
dFUNC2d  X3D_ViewerEnableFog;
dFUNC2d  X3D_ViewerSetFogColor;
dFUNC3d  X3D_ViewerSetFogDistance;
dFUNC4d  X3D_ViewerScreenToWorld;
dFUNC4d  X3D_ViewerWorldToScreen;
dFUNCdp  X3D_ViewerCopyToTexture;

/* water */
dFUNC1d  X3D_WaterCreate;
dFUNC1d  X3D_WaterCreateRandomRipple;
dFUNC3d  X3D_WaterCreateRippleAtGridPosition;
dFUNCdp  X3D_WaterSetMask;
dFUNC2d  X3D_WaterSetActive;
dFUNC1d  X3D_WaterReset;
dFUNC2d  X3D_WaterSetRainTimeInterval;
dFUNC2d  X3D_WaterSetRainForce;
dFUNC2d  X3D_WaterSetViscosity;
dFUNC2d  X3D_WaterSetElastic;
dFUNC2d  X3D_WaterSetResolution;

#endif