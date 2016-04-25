#include "xtreme3d_2c.h"

void X3D_Init(void)
{
	hLibXtreme3D = LoadLibrary("Xtreme3D.dll");
	X3D_ERR = 0;
	/* Written by Timur Gafarov <clocktower89@mail.ru> then ripped and edited by me */
	/* actor */
	X3D_ActorCreate = (dFUNCpd)GetProcAddress(hLibXtreme3D, "ActorCreate");
	X3D_ActorCopy = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorCopy");
	X3D_ActorSetAnimationRange = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ActorSetAnimationRange");
	X3D_ActorGetCurrentFrame = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ActorGetCurrentFrame");
	X3D_ActorSwitchToAnimation = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorSwitchToAnimation");
	X3D_ActorSynchronize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorSynchronize");
	X3D_ActorSetInterval = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorSetInterval");
	X3D_ActorSetAnimationMode = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorSetAnimationMode");
	X3D_ActorSetFrameInterpolation = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorSetFrameInterpolation");
	X3D_ActorAddObject = (dFUNCdp)GetProcAddress(hLibXtreme3D, "ActorAddObject");
	X3D_ActorGetCurrentAnimation = (pFUNC1d)GetProcAddress(hLibXtreme3D, "ActorGetCurrentAnimation");
	X3D_ActorGetFrameCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ActorGetFrameCount");
	X3D_ActorGetBoneCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ActorGetBoneCount");
	X3D_ActorGetBoneByName = (dFUNCdp)GetProcAddress(hLibXtreme3D, "ActorGetBoneByName");
	X3D_ActorRotateBone = (dFUNC5d)GetProcAddress(hLibXtreme3D, "ActorRotateBone");
	X3D_ObjectClueToBone = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ObjectClueToBone");
	X3D_ActorGetBoneRotation = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ActorGetBoneRotation");
	X3D_ActorMoveBone = (dFUNC5d)GetProcAddress(hLibXtreme3D, "ActorMoveBone");
	X3D_ActorGetBonePosition = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ActorGetBonePosition");
	X3D_ActorShowSkeleton = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ActorShowSkeleton");
	
	/* b3d */
	X3D_LoadB3D = (dFUNCpd)GetProcAddress(hLibXtreme3D, "LoadB3D");
	X3D_ClearZones = (dFUNC)GetProcAddress(hLibXtreme3D, "ClearZones");
	X3D_ZonesVisible = (dFUNC)GetProcAddress(hLibXtreme3D, "ZonesVisible");
	X3D_CullZones = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CullZones");
	X3D_ZoneAddPortal = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ZoneAddPortal");
	X3D_ZoneObjectInZone = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ZoneObjectInZone");
	X3D_ZoneGetCurrent = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ZoneGetCurrent");
	X3D_ZoneGetNew = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ZoneGetNew");
	X3D_ZoneAdjustSize = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ZoneAdjustSize");
	X3D_CreateZones = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CreateZones");
	X3D_ZoneGetPortalCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ZoneGetPortalCount");
	X3D_ZoneGetPortal = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ZoneGetPortal");
	
	/* blur */
	X3D_BlurCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "BlurCreate");
	X3D_BlurSetPreset = (dFUNC2d)GetProcAddress(hLibXtreme3D, "BlurSetPreset");
	X3D_BlurSetOptions = (dFUNC6d)GetProcAddress(hLibXtreme3D, "BlurSetOptions");
	X3D_BlurSetResolution = (dFUNC2d)GetProcAddress(hLibXtreme3D, "BlurSetResolution");
	
	/* camera */
	X3D_CameraCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "CameraCreate");
	X3D_CameraSetStyle = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraSetStyle");
	X3D_CameraSetFocal = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraSetFocal");
	X3D_CameraSetSceneScale = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraSetSceneScale");
	X3D_CameraScaleScene = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraScaleScene");
	X3D_CameraSetViewDepth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraSetViewDepth");
	X3D_CameraSetTargetObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraSetTargetObject");
	X3D_CameraMoveAroundTarget = (dFUNC3d)GetProcAddress(hLibXtreme3D, "CameraMoveAroundTarget");
	X3D_CameraSetDistanceToTarget = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CameraSetDistanceToTarget");
	X3D_CameraGetDistanceToTarget = (dFUNC1d)GetProcAddress(hLibXtreme3D, "CameraGetDistanceToTarget");
	X3D_CameraCopyToTexture = (dFUNCdpdd)GetProcAddress(hLibXtreme3D, "CameraCopyToTexture");
	
	/* dce */
	X3D_DceManagerCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "DceManagerCreate");
	X3D_DceManagerStep = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceManagerStep");
	X3D_DceManagerSetWorldDirection = (dFUNC4d)GetProcAddress(hLibXtreme3D, "DceManagerSetWorldDirection");
	X3D_DceManagerSetWorldScale = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceManagerSetWorldScale");
	X3D_DceManagerSetMovementScale = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceManagerSetMovementScale");
	X3D_DceManagerSetLayers = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceManagerSetLayers");
	X3D_DceManagerSetManualStep = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceManagerSetManualStep");
	X3D_DceSetManager = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetManager");
	X3D_DceSetActive = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetActive");
	X3D_DceIsActive = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceIsActive");
	X3D_DceSetUseGravity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetUseGravity");
	X3D_DceSetLayer = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetLayer");
	X3D_DceGetLayer = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceGetLayer");
	X3D_DceSetSolid = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetSolid");
	X3D_DceSetFriction = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetFriction");
	X3D_DceSetBounce = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetBounce");
	X3D_DceSetSize = (dFUNC4d)GetProcAddress(hLibXtreme3D, "DceSetSize");
	X3D_DceSetSlideOrBounce = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetSlideOrBounce");
	X3D_DceApplyAcceleration = (dFUNC4d)GetProcAddress(hLibXtreme3D, "DceApplyAcceleration");
	X3D_DceApplyAbsAcceleration = (dFUNC4d)GetProcAddress(hLibXtreme3D, "DceApplyAbsAcceleration");
	X3D_DceStopAcceleration = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceStopAcceleration");
	X3D_DceStopAbsAcceleration = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceStopAbsAcceleration");
	X3D_DceJump = (dFUNC3d)GetProcAddress(hLibXtreme3D, "DceJump");
	X3D_DceMove = (dFUNC5d)GetProcAddress(hLibXtreme3D, "DceMove");
	X3D_DceMoveTo = (dFUNC5d)GetProcAddress(hLibXtreme3D, "DceMoveTo");
	X3D_DceSetSpeed = (dFUNC4d)GetProcAddress(hLibXtreme3D, "DceSetSpeed");
	X3D_DceInGround = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceInGround");
	X3D_DceSetMaxRecursionDepth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceSetMaxRecursionDepth");
	X3D_DceStaticSetManager = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetManager");
	X3D_DceStaticSetActive = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetActive");
	X3D_DceStaticSetShape = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetShape");
	X3D_DceStaticSetLayer = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetLayer");
	X3D_DceStaticSetSize = (dFUNC4d)GetProcAddress(hLibXtreme3D, "DceStaticSetSize");
	X3D_DceStaticSetSolid = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetSolid");
	X3D_DceStaticSetFriction = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetFriction");
	X3D_DceStaticSetBounceFactor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceStaticSetBounceFactor");
	X3D_DceGetVelocity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceGetVelocity");
	X3D_DceGetGravity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceGetGravity");
	X3D_DceVelocityCollided = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceVelocityCollided");
	X3D_DceGravityCollided = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceGravityCollided");
	X3D_DceCountCollisions = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DceCountCollisions");
	X3D_DceGetCollidedObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DceGetCollidedObject");
	X3D_DceGetCollisionPosition = (dFUNC3d)GetProcAddress(hLibXtreme3D, "DceGetCollisionPosition");
	X3D_DceGetCollisionNormal = (dFUNC3d)GetProcAddress(hLibXtreme3D, "DceGetCollisionNormal");
	
	/* dummycube */
	X3D_DummycubeCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "DummycubeCreate");
	X3D_DummycubeAmalgamate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DummycubeAmalgamate");
	X3D_DummycubeSetCameraMode = (dFUNC2d)GetProcAddress(hLibXtreme3D, "DummycubeSetCameraMode");
	
	/* engine */
	X3D_EngineCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "EngineCreate");
	X3D_EngineDestroy = (dFUNC)GetProcAddress(hLibXtreme3D, "EngineDestroy");
	X3D_EngineSetObjectsSorting = (dFUNC1d)GetProcAddress(hLibXtreme3D, "EngineSetObjectsSorting");
	X3D_EngineSetCulling = (dFUNC1d)GetProcAddress(hLibXtreme3D, "EngineSetCulling");
	X3D_EngineGetMaxTextureSize = (dFUNC)GetProcAddress(hLibXtreme3D, "EngineGetMaxTextureSize");
	X3D_EngineGetMaxTextureUnits = (dFUNC)GetProcAddress(hLibXtreme3D, "EngineGetMaxTextureUnits");
	X3D_SetPakArchive = (dFUNC1p)GetProcAddress(hLibXtreme3D, "SetPakArchive");
	X3D_Update = (dFUNC)GetProcAddress(hLibXtreme3D, "Update");
	X3D_TrisRendered = (dFUNC)GetProcAddress(hLibXtreme3D, "TrisRendered");
	
	/* firefx */
	X3D_FireFXManagerCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "FireFXManagerCreate");
	X3D_FireFXCreate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXCreate");
	X3D_FireFXSetColor = (dFUNC5d)GetProcAddress(hLibXtreme3D, "FireFXSetColor");
	X3D_FireFXSetMaxParticles = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetMaxParticles");
	X3D_FireFXSetParticleSize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetParticleSize");
	X3D_FireFXSetDensity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetDensity");
	X3D_FireFXSetEvaporation = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetEvaporation");
	X3D_FireFXSetCrown = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetCrown");
	X3D_FireFXSetLife = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetLife");
	X3D_FireFXSetBurst = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetBurst");
	X3D_FireFXSetRadius = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FireFXSetRadius");
	X3D_FireFXExplosion = (dFUNC4d)GetProcAddress(hLibXtreme3D, "FireFXExplosion");
	
	/* fonttext */
	X3D_BmpfontCreate = (dFUNC8d)GetProcAddress(hLibXtreme3D, "BmpfontCreate");
	X3D_BmpfontLoad = (dFUNCdp)GetProcAddress(hLibXtreme3D, "BmpfontLoad");
	X3D_WindowsBitmapfontCreate = (dFUNCpd)GetProcAddress(hLibXtreme3D, "WindowsBitmapfontCreate");
	X3D_FlatTextCreate = (dFUNCdpd)GetProcAddress(hLibXtreme3D, "FlatTextCreate");
	X3D_HUDTextCreate = (dFUNCdpd)GetProcAddress(hLibXtreme3D, "HUDTextCreate");
	X3D_HUDTextSetRotation = (dFUNC2d)GetProcAddress(hLibXtreme3D, "HUDTextSetRotation");
	X3D_SpaceTextCreate = (dFUNCdpdd)GetProcAddress(hLibXtreme3D, "SpaceTextCreate");
	X3D_SpaceTextSetExtrusion = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SpaceTextSetExtrusion");
	X3D_TextSetColor = (dFUNC3d)GetProcAddress(hLibXtreme3D, "TextSetColor");
	X3D_TextSetFont = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TextSetFont");
	X3D_TextSetText = (dFUNCdp)GetProcAddress(hLibXtreme3D, "TextSetText");
	
	/* fps */
	X3D_FpsManagerCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "FpsManagerCreate");
	X3D_FpsManagerSetNavigator = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsManagerSetNavigator");
	X3D_FpsManagerSetMovementScale = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsManagerSetMovementScale");
	X3D_FpsManagerAddMap = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsManagerAddMap");
	X3D_FpsManagerRemoveMap = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsManagerRemoveMap");
	X3D_FPSMapSetGroup = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FPSMapSetGroup");
	X3D_FpsSetManager = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsSetManager");
	X3D_FpsSetGroup = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsSetGroup");
	X3D_FpsSetSphereRadius = (dFUNC1d)GetProcAddress(hLibXtreme3D, "FpsSetSphereRadius");
	X3D_FpsSetGravity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsSetGravity");
	X3D_FpsMove = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsMove");
	X3D_FpsStrafe = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsStrafe");
	X3D_FpsLift = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsLift");
	X3D_FpsGetVelocity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsGetVelocity");
	X3D_FpsCountCollisions = (dFUNC1d)GetProcAddress(hLibXtreme3D, "FpsCountCollisions");
	X3D_FpsClearCollisions = (dFUNC1d)GetProcAddress(hLibXtreme3D, "FpsClearCollisions");
	X3D_FpsGetCollisionPosition = (dFUNC3d)GetProcAddress(hLibXtreme3D, "FpsGetCollisionPosition");
	X3D_FpsGetCollisionNormal = (dFUNC3d)GetProcAddress(hLibXtreme3D, "FpsGetCollisionNormal");
	X3D_FpsGetCollidedObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FpsGetCollidedObject");
	
	/* freeform */
	X3D_FreeformCreate = (dFUNCpd)GetProcAddress(hLibXtreme3D, "FreeformCreate");
	X3D_FreeformPointInMesh = (dFUNC4d)GetProcAddress(hLibXtreme3D, "FreeformPointInMesh");
	X3D_FreeformSphereSweepIntersect = (dFUNC4d)GetProcAddress(hLibXtreme3D, "FreeformSphereSweepIntersect");
	X3D_FreeformToFreeforms = (dFUNC4d)GetProcAddress(hLibXtreme3D, "FreeformToFreeforms");
	X3D_FreeformSetSecondTextureCoords = (dFUNC2d)GetProcAddress(hLibXtreme3D, "FreeformSetSecondTextureCoords");
	
	/* lensfrare */
	X3D_LensflareCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "LensflareCreate");
	X3D_LensflareSetSize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetSize");
	X3D_LensflareSetSeed = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetSeed");
	X3D_LensflareSetSqueeze = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetSqueeze");
	X3D_LensflareSetStreaks = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetStreaks");
	X3D_LensflareSetStreakwidth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetStreakwidth");
	X3D_LensflareSetSecs = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetSecs");
	X3D_LensflareSetResolution = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LensflareSetResolution");
	X3D_LensflareSetElements = (dFUNC6d)GetProcAddress(hLibXtreme3D, "LensflareSetElements");
	X3D_LensflareSetGradients = (dFUNC6d)GetProcAddress(hLibXtreme3D, "LensflareSetGradients");
	
	/* light */
	X3D_LightCreate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightCreate");
	X3D_LightSetAmbientColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetAmbientColor");
	X3D_LightSetDiffuseColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetDiffuseColor");
	X3D_LightSetSpecularColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetSpecularColor");
	X3D_LightSetAttenuation = (dFUNC4d)GetProcAddress(hLibXtreme3D, "LightSetAttenuation");
	X3D_LightSetShining = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetShining");
	X3D_LightSetSpotCutoff = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetSpotCutoff");
	X3D_LightSetSpotExponent = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetSpotExponent");
	X3D_LightSetSpotDirection = (dFUNC4d)GetProcAddress(hLibXtreme3D, "LightSetSpotDirection");
	X3D_LightSetStyle = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LightSetStyle");
	
	/* lines */
	X3D_LinesCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "LinesCreate");
	X3D_LinesAddNode = (dFUNC4d)GetProcAddress(hLibXtreme3D, "LinesAddNode");
	X3D_LinesDeleteNode = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LinesDeleteNode");
	X3D_LinesSetColors = (dFUNC5d)GetProcAddress(hLibXtreme3D, "LinesSetColors");
	X3D_LinesSetSize = (dFUNC3d)GetProcAddress(hLibXtreme3D, "LinesSetSize");
	X3D_LinesSetSplineMode = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LinesSetSplineMode");
	X3D_LinesSetNodesAspect = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LinesSetNodesAspect");
	X3D_LinesSetDivision = (dFUNC2d)GetProcAddress(hLibXtreme3D, "LinesSetDivision");
	
	/* material */
	X3D_MaterialLibraryCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "MaterialLibraryCreate");
	X3D_MaterialLibraryActivate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MaterialLibraryActivate");
	X3D_MaterialLibrarySetTexturePaths = (dFUNCdp)GetProcAddress(hLibXtreme3D, "MaterialLibrarySetTexturePaths");
	X3D_MaterialLibraryClear = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MaterialLibraryClear");
	X3D_MaterialLibraryDeleteUnused = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MaterialLibraryDeleteUnused");
	X3D_MaterialCreate = (dFUNCppd)GetProcAddress(hLibXtreme3D, "MaterialCreate");
	X3D_MaterialAddCubeMap = (dFUNC1p)GetProcAddress(hLibXtreme3D, "MaterialAddCubeMap");
	X3D_MaterialCubeMapLoadImage = (dFUNC2p)GetProcAddress(hLibXtreme3D, "MaterialCubeMapLoadImage");
	X3D_MaterialCubeMapFromScene = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialCubeMapFromScene");
	X3D_MaterialSetAmbientColor = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetAmbientColor");
	X3D_MaterialSetDiffuseColor = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetDiffuseColor");
	X3D_MaterialSetEmissionColor = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetEmissionColor");
	X3D_MaterialSetSpecularColor = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetSpecularColor");
	X3D_MaterialSetShininess = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetShininess");
	X3D_MaterialSetPolygonMode = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetPolygonMode");
	X3D_MaterialSetTextureMappingMode = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureMappingMode");
	X3D_MaterialSetTextureImageAlpha = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureImageAlpha");
	X3D_MaterialSetTextureScale = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureScale");
	X3D_MaterialGetFromLib = (dFUNC2p)GetProcAddress(hLibXtreme3D, "MaterialGetFromLib");
	X3D_MaterialSetTextureOffset = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureOffset");
	X3D_MaterialSetTextureMode = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureMode");
	X3D_MaterialSetBlendingMode = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetBlendingMode");
	X3D_MaterialSetTextureFilter = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureFilter");
	X3D_MaterialDisableTexture = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialDisableTexture");
	X3D_MaterialLoadTexture = (dFUNC2p)GetProcAddress(hLibXtreme3D, "MaterialLoadTexture");
	X3D_MaterialGetCount = (dFUNC)GetProcAddress(hLibXtreme3D, "MaterialGetCount");
	X3D_MaterialGetName = (pFUNC1d)GetProcAddress(hLibXtreme3D, "MaterialGetName");
	X3D_MaterialSetFaceCulling = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetFaceCulling");
	X3D_MaterialSetSecondTexture = (dFUNC2p)GetProcAddress(hLibXtreme3D, "MaterialSetSecondTexture");
	X3D_MaterialSetTextureFormat = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureFormat");
	X3D_MaterialSetTextureCompression = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetTextureCompression");
	X3D_MaterialTextureRequiredMemory = (dFUNC1p)GetProcAddress(hLibXtreme3D, "MaterialTextureRequiredMemory");
	X3D_MaterialSetFilteringQuality = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetFilteringQuality");
	X3D_MaterialSetOptions = (dFUNCpdd)GetProcAddress(hLibXtreme3D, "MaterialSetOptions");
	X3D_MaterialSetShader = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialSetShader");
	X3D_MaterialAddTextureEx = (dFUNC2p)GetProcAddress(hLibXtreme3D, "MaterialAddTextureEx");
	X3D_MaterialTextureExClear = (dFUNC1p)GetProcAddress(hLibXtreme3D, "MaterialTextureExClear");
	X3D_MaterialTextureExDelete = (dFUNCpd)GetProcAddress(hLibXtreme3D, "MaterialTextureExDelete");
	
	/* mesh */
	X3D_MeshCountObjects = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MeshCountObjects");
	X3D_MeshRotate = (dFUNC5d)GetProcAddress(hLibXtreme3D, "MeshRotate");
	X3D_MeshExplode = (dFUNC6d)GetProcAddress(hLibXtreme3D, "MeshExplode");
	X3D_MeshSetVisible = (dFUNC3d)GetProcAddress(hLibXtreme3D, "MeshSetVisible");
	X3D_MeshCountVertices = (dFUNC2d)GetProcAddress(hLibXtreme3D, "MeshCountVertices");
	X3D_MeshOptimize = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MeshOptimize");
	X3D_MeshSmoothFaces = (dFUNC3d)GetProcAddress(hLibXtreme3D, "MeshSmoothFaces");
	
	/* mirror */
	X3D_MirrorCreate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "MirrorCreate");
	X3D_MirrorSetObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "MirrorSetObject");
	X3D_MirrorSetOptions = (dFUNC5d)GetProcAddress(hLibXtreme3D, "MirrorSetOptions");
	
	/* mouse */
	X3D_MouseGetX = (dFUNC)GetProcAddress(hLibXtreme3D, "MouseGetX");
	X3D_MouseGetY = (dFUNC)GetProcAddress(hLibXtreme3D, "MouseGetY");
	X3D_MouseSetPosition = (dFUNC2d)GetProcAddress(hLibXtreme3D, "MouseSetPosition");
	X3D_MouseShowCursor = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MouseShowCursor");
	
	/* navigator */
	X3D_NavigatorCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "NavigatorCreate");
	X3D_NavigatorSetObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorSetObject");
	X3D_NavigatorSetUseVirtualUp = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorSetUseVirtualUp");
	X3D_NavigatorSetVirtualUp = (dFUNC4d)GetProcAddress(hLibXtreme3D, "NavigatorSetVirtualUp");
	X3D_NavigatorTurnHorizontal = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorTurnHorizontal");
	X3D_NavigatorTurnVertical = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorTurnVertical");
	X3D_NavigatorMoveForward = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorMoveForward");
	X3D_NavigatorStrafeHorizontal = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorStrafeHorizontal");
	X3D_NavigatorStrafeVertical = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorStrafeVertical");
	X3D_NavigatorStraighten = (dFUNC1d)GetProcAddress(hLibXtreme3D, "NavigatorStraighten");
	X3D_NavigatorFlyForward = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorFlyForward");
	X3D_NavigatorMoveUpWhenMovingForward = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorMoveUpWhenMovingForward");
	X3D_NavigatorInvertHorizontalWhenUpsideDown = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorInvertHorizontalWhenUpsideDown");
	X3D_NavigatorSetAngleLock = (dFUNC2d)GetProcAddress(hLibXtreme3D, "NavigatorSetAngleLock");
	X3D_NavigatorSetAngles = (dFUNC3d)GetProcAddress(hLibXtreme3D, "NavigatorSetAngles");
	
	/* object */
	X3D_ObjectHide = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectHide");
	X3D_ObjectShow = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectShow");
	X3D_ObjectIsVisible = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectIsVisible");
	X3D_ObjectCopy = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectCopy");
	X3D_ObjectDestroy = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectDestroy");
	X3D_ObjectSetPosition = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetPosition");
	X3D_ObjectGetPosition = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetPosition");
	X3D_ObjectGetAbsolutePosition = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsolutePosition");
	X3D_ObjectSetPositionOfObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetPositionOfObject");
	X3D_ObjectAlignWithObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectAlignWithObject");
	X3D_ObjectSetPositionX = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetPositionX");
	X3D_ObjectSetPositionY = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetPositionY");
	X3D_ObjectSetPositionZ = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetPositionZ");
	X3D_ObjectSetAbsolutePosition = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetAbsolutePosition");
	X3D_ObjectSetDirection = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetDirection");
	X3D_ObjectGetDirection = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetDirection");
	X3D_ObjectSetAbsoluteDirection = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetAbsoluteDirection");
	X3D_ObjectGetAbsoluteDirection = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsoluteDirection");
	X3D_ObjectGetPitch = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetPitch");
	X3D_ObjectGetTurn = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetTurn");
	X3D_ObjectGetRoll = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetRoll");
	X3D_ObjectSetRotation = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetRotation");
	X3D_ObjectMove = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectMove");
	X3D_ObjectLift = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectLift");
	X3D_ObjectTranslate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectTranslate");
	X3D_ObjectStrafe = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectStrafe");
	X3D_ObjectRotate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectRotate");
	X3D_ObjectScale = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectScale");
	X3D_ObjectSetScale = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetScale");
	X3D_ObjectSetUpVector = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetUpVector");
	X3D_ObjectPointToObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectPointToObject");
	X3D_ObjectAlignToCamera = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectAlignToCamera");
	X3D_ObjectGetAtXY = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ObjectGetAtXY");
	X3D_ObjectShowAxes = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectShowAxes");
	X3D_ObjectGetGroundHeight = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetGroundHeight");
	X3D_ObjectSceneRaycast = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSceneRaycast");
	X3D_ObjectRaycast = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectRaycast");
	X3D_ObjectGetCollisionPosition = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetCollisionPosition");
	X3D_ObjectGetCollisionNormal = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetCollisionNormal");
	X3D_ObjectSetDiffuseColor = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ObjectSetDiffuseColor");
	X3D_ObjectSetMaterial = (dFUNCdp)GetProcAddress(hLibXtreme3D, "ObjectSetMaterial");
	X3D_ObjectGetDistance = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetDistance");
	X3D_ObjectCheckCubeVsFace = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectCheckCubeVsFace");
	X3D_ObjectCheckCubeVsCube = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectCheckCubeVsCube");
	X3D_ObjectCheckFaceVsFace = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectCheckFaceVsFace");
	X3D_ObjectCheckSphereVsSphere = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectCheckSphereVsSphere");
	X3D_ObjectCheckSphereVsCube = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectCheckSphereVsCube");
	X3D_ObjectIsPointInObject = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectIsPointInObject");
	X3D_ObjectSetCulling = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetCulling");
	X3D_ObjectSetName = (dFUNCdp)GetProcAddress(hLibXtreme3D, "ObjectSetName");
	X3D_ObjectGetName = (pFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetName");
	X3D_ObjectGetClassName = (pFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetClassName");
	X3D_ObjectSetID = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetID");
	X3D_ObjectGetID = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetID");
	X3D_ObjectGetParent = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetParent");
	X3D_ObjectGetChildCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetChildCount");
	X3D_ObjectGetChild = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetChild");
	X3D_ObjectGetBoundingsphereRadius = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetBoundingsphereRadius");
	X3D_ObjectGetIndex = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectGetIndex");
	X3D_ObjectFindChild = (dFUNCdp)GetProcAddress(hLibXtreme3D, "ObjectFindChild");
	X3D_ObjectGetAbsoluteUp = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsoluteUp");
	X3D_ObjectSetAbsoluteUp = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectSetAbsoluteUp");
	X3D_ObjectGetAbsoluteRight = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsoluteRight");
	X3D_ObjectGetAbsoluteXVector = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsoluteXVector");
	X3D_ObjectGetAbsoluteYVector = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsoluteYVector");
	X3D_ObjectGetAbsoluteZVector = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetAbsoluteZVector");
	X3D_ObjectGetRight = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetRight");
	X3D_ObjectMoveChildUp = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectMoveChildUp");
	X3D_ObjectMoveChildDown = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectMoveChildDown");
	X3D_ObjectSetParent = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectSetParent");
	X3D_ObjectRemoveChild = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ObjectRemoveChild");
	X3D_ObjectMoveObjectAround = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectMoveObjectAround");
	X3D_ObjectPitch = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectPitch");
	X3D_ObjectTurn = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectTurn");
	X3D_ObjectRoll = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectRoll");
	X3D_ObjectGetUpVector = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectGetUpVector");
	X3D_ObjectStructureChanged = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectStructureChanged");
	X3D_ObjectRotateAbsolute = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ObjectRotateAbsolute");
	X3D_ObjectRotateAbsoluteVector = (dFUNC5d)GetProcAddress(hLibXtreme3D, "ObjectRotateAbsoluteVector");
	X3D_ObjectInFrustrum = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectInFrustrum");
	X3D_ObjectIsClipped = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ObjectIsClipped");
	
	/* ode */
	X3D_OdeManagerCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeManagerCreate");
	X3D_OdeManagerDestroy = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeManagerDestroy");
	X3D_OdeManagerStep = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeManagerStep");
	X3D_OdeManagerGetNumContactJoints = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeManagerGetNumContactJoints");
	X3D_OdeManagerSetGravity = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeManagerSetGravity");
	X3D_OdeManagerSetSolver = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeManagerSetSolver");
	X3D_OdeManagerSetIterations = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeManagerSetIterations");
	X3D_OdeManagerSetMaxContacts = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeManagerSetMaxContacts");
	X3D_OdeManagerSetVisible = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeManagerSetVisible");
	X3D_OdeManagerSetGeomColor = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeManagerSetGeomColor");
	X3D_OdeWorldSetAutoDisableFlag = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeWorldSetAutoDisableFlag");
	X3D_OdeWorldSetAutoDisableLinearThreshold = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeWorldSetAutoDisableLinearThreshold");
	X3D_OdeWorldSetAutoDisableAngularThreshold = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeWorldSetAutoDisableAngularThreshold");
	X3D_OdeWorldSetAutoDisableSteps = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeWorldSetAutoDisableSteps");
	X3D_OdeWorldSetAutoDisableTime = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeWorldSetAutoDisableTime");
	X3D_OdeDynamicSetAutoDisableFlag = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicSetAutoDisableFlag");
	X3D_OdeDynamicSetAutoDisableLinearThreshold = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicSetAutoDisableLinearThreshold");
	X3D_OdeDynamicSetAutoDisableAngularThreshold = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicSetAutoDisableAngularThreshold");
	X3D_OdeDynamicSetAutoDisableSteps = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicSetAutoDisableSteps");
	X3D_OdeDynamicSetAutoDisableTime = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicSetAutoDisableTime");
	X3D_OdeStaticCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeStaticCreate");
	X3D_OdeDynamicCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeDynamicCreate");
	X3D_OdeDynamicAlignObject = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeDynamicAlignObject");
	X3D_OdeDynamicEnable = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicEnable");
	X3D_OdeDynamicCalibrateCenterOfMass = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeDynamicCalibrateCenterOfMass");
	X3D_OdeDynamicAddForce = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddForce");
	X3D_OdeDynamicAddForceAtPos = (dFUNC7d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddForceAtPos");
	X3D_OdeDynamicAddForceAtRelPos = (dFUNC7d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddForceAtRelPos");
	X3D_OdeDynamicAddRelForce = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddRelForce");
	X3D_OdeDynamicAddRelForceAtPos = (dFUNC7d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddRelForceAtPos");
	X3D_OdeDynamicAddRelForceAtRelPos = (dFUNC7d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddRelForceAtRelPos");
	X3D_OdeDynamicAddTorque = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddTorque");
	X3D_OdeDynamicAddRelTorque = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeDynamicAddRelTorque");
	X3D_OdeDynamicGetContactCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeDynamicGetContactCount");
	X3D_OdeDynamicGetContact = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeDynamicGetContact");
	X3D_OdeStaticGetContactCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeStaticGetContactCount");
	X3D_OdeStaticGetContact = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeStaticGetContact");
	X3D_OdeAddBox = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeAddBox");
	X3D_OdeAddCapsule = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeAddCapsule");
	X3D_OdeAddCone = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeAddCone");
	X3D_OdeAddCylinder = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeAddCylinder");
	X3D_OdeAddPlane = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeAddPlane");
	X3D_OdeAddSphere = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeAddSphere");
	X3D_OdeAddTriMesh = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OdeAddTriMesh");
	X3D_OdeSurfaceSetRollingFrictionCoeff = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetRollingFrictionCoeff");
	X3D_OdeSurfaceEnableRollingFrictionCoeff = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceEnableRollingFrictionCoeff");
	X3D_OdeSurfaceSetMode = (dFUNC10d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetMode");
	X3D_OdeSurfaceSetMu = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetMu");
	X3D_OdeSurfaceSetMu2 = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetMu2");
	X3D_OdeSurfaceSetBounce = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetBounce");
	X3D_OdeSurfaceSetBounceVel = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetBounceVel");
	X3D_OdeSurfaceSetSoftERP = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetSoftERP");
	X3D_OdeSurfaceSetSoftCFM = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetSoftCFM");
	X3D_OdeSurfaceSetMotion1 = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetMotion1");
	X3D_OdeSurfaceSetMotion2 = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetMotion2");
	X3D_OdeSurfaceSetSlip1 = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetSlip1");
	X3D_OdeSurfaceSetSlip2 = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeSurfaceSetSlip2");
	X3D_OdeAddJointBall = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeAddJointBall");
	X3D_OdeAddJointFixed = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeAddJointFixed");
	X3D_OdeAddJointHinge = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeAddJointHinge");
	X3D_OdeAddJointHinge2 = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeAddJointHinge2");
	X3D_OdeAddJointSlider = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeAddJointSlider");
	X3D_OdeAddJointUniversal = (dFUNC)GetProcAddress(hLibXtreme3D, "OdeAddJointUniversal");
	X3D_OdeJointSetObjects = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetObjects");
	X3D_OdeJointEnable = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeJointEnable");
	X3D_OdeJointInitialize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeJointInitialize");
	X3D_OdeJointSetAnchor = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeJointSetAnchor");
	X3D_OdeJointSetAnchorAtObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OdeJointSetAnchorAtObject");
	X3D_OdeJointSetAxis1 = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeJointSetAxis1");
	X3D_OdeJointSetAxis2 = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OdeJointSetAxis2");
	X3D_OdeJointSetBounce = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetBounce");
	X3D_OdeJointSetCFM = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetCFM");
	X3D_OdeJointSetFMax = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetFMax");
	X3D_OdeJointSetFudgeFactor = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetFudgeFactor");
	X3D_OdeJointSetHiStop = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetHiStop");
	X3D_OdeJointSetLoStop = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetLoStop");
	X3D_OdeJointSetStopCFM = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetStopCFM");
	X3D_OdeJointSetStopERP = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetStopERP");
	X3D_OdeJointSetVel = (dFUNC3d)GetProcAddress(hLibXtreme3D, "OdeJointSetVel");
	
	/* partition */
	X3D_OctreeCreate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "OctreeCreate");
	X3D_QuadtreeCreate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "QuadtreeCreate");
	X3D_PartitionDestroy = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PartitionDestroy");
	X3D_PartitionAddLeaf = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PartitionAddLeaf");
	X3D_PartitionLeafChanged = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PartitionLeafChanged");
	X3D_PartitionQueryFrustrum = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PartitionQueryFrustrum");
	X3D_PartitionQueryLeaf = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PartitionQueryLeaf");
	X3D_PartitionQueryAABB = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PartitionQueryAABB");
	X3D_PartitionQueryBSphere = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PartitionQueryBSphere");
	X3D_PartitionGetNodeTests = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PartitionGetNodeTests");
	X3D_PartitionGetNodeCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PartitionGetNodeCount");
	X3D_PartitionGetResult = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PartitionGetResult");
	X3D_PartitionResultShow = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PartitionResultShow");
	X3D_PartitionResultHide = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PartitionResultHide");
	
	/* polygon */
	X3D_PolygonCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "PolygonCreate");
	X3D_PolygonAddVertex = (dFUNC4d)GetProcAddress(hLibXtreme3D, "PolygonAddVertex");
	X3D_PolygonSetVertexPosition = (dFUNC5d)GetProcAddress(hLibXtreme3D, "PolygonSetVertexPosition");
	X3D_PolygonDeleteVertex = (dFUNC2d)GetProcAddress(hLibXtreme3D, "PolygonDeleteVertex");
	
	/* primitives */
	X3D_PlaneCreate = (dFUNC6d)GetProcAddress(hLibXtreme3D, "PlaneCreate");
	X3D_CubeCreate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "CubeCreate");
	X3D_CubeSetNormalDirection = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CubeSetNormalDirection");
	X3D_SphereCreate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "SphereCreate");
	X3D_CylinderCreate = (dFUNC7d)GetProcAddress(hLibXtreme3D, "CylinderCreate");
	X3D_ConeCreate = (dFUNC6d)GetProcAddress(hLibXtreme3D, "ConeCreate");
	X3D_AnnulusCreate = (dFUNC7d)GetProcAddress(hLibXtreme3D, "AnnulusCreate");
	X3D_TorusCreate = (dFUNC5d)GetProcAddress(hLibXtreme3D, "TorusCreate");
	X3D_DiskCreate = (dFUNC7d)GetProcAddress(hLibXtreme3D, "DiskCreate");
	
	/* shaders */
	X3D_ShaderEnable = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShaderEnable");
	X3D_BumpShaderCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "BumpShaderCreate");
	X3D_CelShaderCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "CelShaderCreate");
	X3D_CelShaderSetLineColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CelShaderSetLineColor");
	X3D_CelShaderSetLineWidth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "CelShaderSetLineWidth");
	X3D_HiddenLineShaderCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "HiddenLineShaderCreate");
	X3D_HiddenLineShaderSetLineSmooth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "HiddenLineShaderSetLineSmooth");
	X3D_HiddenLineShaderSetSolid = (dFUNC2d)GetProcAddress(hLibXtreme3D, "HiddenLineShaderSetSolid");
	X3D_HiddenLineShaderSetSurfaceLit = (dFUNC2d)GetProcAddress(hLibXtreme3D, "HiddenLineShaderSetSurfaceLit");
	X3D_HiddenLineShaderSetFrontLine = (dFUNC5d)GetProcAddress(hLibXtreme3D, "HiddenLineShaderSetFrontLine");
	X3D_HiddenLineShaderSetBackLine = (dFUNC5d)GetProcAddress(hLibXtreme3D, "HiddenLineShaderSetBackLine");
	X3D_MultiMaterialShaderCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "MultiMaterialShaderCreate");
	X3D_OutlineShaderCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "OutlineShaderCreate");
	X3D_OutlineShaderSetLineColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OutlineShaderSetLineColor");
	X3D_OutlineShaderSetLineWidth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "OutlineShaderSetLineWidth");
	
	/* shadowplane */
	X3D_ShadowplaneCreate = (dFUNC9d)GetProcAddress(hLibXtreme3D, "ShadowplaneCreate");
	X3D_ShadowplaneSetLight = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowplaneSetLight");
	X3D_ShadowplaneSetObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowplaneSetObject");
	X3D_ShadowplaneSetOptions = (dFUNC5d)GetProcAddress(hLibXtreme3D, "ShadowplaneSetOptions");
	
	/* shadowvolume */
	X3D_ShadowvolumeCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ShadowvolumeCreate");
	X3D_ShadowvolumeSetActive = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowvolumeSetActive");
	X3D_ShadowvolumeAddLight = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowvolumeAddLight");
	X3D_ShadowvolumeRemoveLight = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowvolumeRemoveLight");
	X3D_ShadowvolumeAddOccluder = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowvolumeAddOccluder");
	X3D_ShadowvolumeRemoveOccluder = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowvolumeRemoveOccluder");
	X3D_ShadowvolumeSetDarkeningColor = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ShadowvolumeSetDarkeningColor");
	X3D_ShadowvolumeSetMode = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ShadowvolumeSetMode");
	X3D_ShadowvolumeSetOptions = (dFUNC5d)GetProcAddress(hLibXtreme3D, "ShadowvolumeSetOptions");
	
	/* skybox */
	X3D_SkyboxCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "SkyboxCreate");
	X3D_SkyboxSetMaterial = (dFUNCddp)GetProcAddress(hLibXtreme3D, "SkyboxSetMaterial");
	X3D_SkyboxSetClouds = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SkyboxSetClouds");
	X3D_SkyboxSetStyle = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkyboxSetStyle");
	
	/* skydome */
	X3D_SkydomeCreate = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SkydomeCreate");
	X3D_SkydomeSetOptions = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SkydomeSetOptions");
	X3D_SkydomeSetDeepColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetDeepColor");
	X3D_SkydomeSetHazeColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetHazeColor");
	X3D_SkydomeSetNightColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetNightColor");
	X3D_SkydomeSetSkyColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetSkyColor");
	X3D_SkydomeSetSunDawnColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetSunDawnColor");
	X3D_SkydomeSetSunZenithColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetSunZenithColor");
	X3D_SkydomeSetSunElevation = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetSunElevation");
	X3D_SkydomeSetTurbidity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeSetTurbidity");
	X3D_SkydomeAddRandomStars = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SkydomeAddRandomStars");
	X3D_SkydomeClearStars = (dFUNC1d)GetProcAddress(hLibXtreme3D, "SkydomeClearStars");
	X3D_SkydomeTwinkleStars = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SkydomeTwinkleStars");
	
	/* sprite */
	X3D_HUDSpriteCreate = (dFUNCpddd)GetProcAddress(hLibXtreme3D, "HUDSpriteCreate");
	X3D_SpriteCreate = (dFUNCpddd)GetProcAddress(hLibXtreme3D, "SpriteCreate");
	X3D_SpriteSetSize = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SpriteSetSize");
	X3D_SpriteScale = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SpriteScale");
	X3D_SpriteSetRotation = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SpriteSetRotation");
	X3D_SpriteRotate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SpriteRotate");
	X3D_SpriteMirror = (dFUNC3d)GetProcAddress(hLibXtreme3D, "SpriteMirror");
	X3D_SpriteNoZWrite = (dFUNC2d)GetProcAddress(hLibXtreme3D, "SpriteNoZWrite");
	X3D_ObjectUseObjectColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ObjectUseObjectColor");
	
	/* terrain */
	X3D_BmpHDSCreate = (dFUNC1p)GetProcAddress(hLibXtreme3D, "BmpHDSCreate");
	X3D_BmpHDSSetInfiniteWarp = (dFUNC2d)GetProcAddress(hLibXtreme3D, "BmpHDSSetInfiniteWarp");
	X3D_BmpHDSSetInverted = (dFUNC2d)GetProcAddress(hLibXtreme3D, "BmpHDSSetInverted");
	X3D_TerrainCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "TerrainCreate");
	X3D_TerrainSetHeightData = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetHeightData");
	X3D_TerrainSetTileSize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetTileSize");
	X3D_TerrainSetTilesPerTexture = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetTilesPerTexture");
	X3D_TerrainSetQualityDistance = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetQualityDistance");
	X3D_TerrainSetQualityStyle = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetQualityStyle");
	X3D_TerrainSetMaxCLodTriangles = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetMaxCLodTriangles");
	X3D_TerrainSetCLodPrecision = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetCLodPrecision");
	X3D_TerrainSetOcclusionFrameSkip = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetOcclusionFrameSkip");
	X3D_TerrainSetOcclusionTesselate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainSetOcclusionTesselate");
	X3D_TerrainGetHeightAtObjectPosition = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TerrainGetHeightAtObjectPosition");
	X3D_TerrainGetLastTriCount = (dFUNC1d)GetProcAddress(hLibXtreme3D, "TerrainGetLastTriCount");
	
	/* thorfx */
	X3D_ThorFXManagerCreate = (dFUNC)GetProcAddress(hLibXtreme3D, "ThorFXManagerCreate");
	X3D_ThorFXCreate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXCreate");
	X3D_ThorFXSetColor = (dFUNC7d)GetProcAddress(hLibXtreme3D, "ThorFXSetColor");
	X3D_ThorFXEnableCore = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXEnableCore");
	X3D_ThorFXEnableGlow = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXEnableGlow");
	X3D_ThorFXSetMaxParticles = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXSetMaxParticles");
	X3D_ThorFXSetGlowSize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXSetGlowSize");
	X3D_ThorFXSetVibrate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXSetVibrate");
	X3D_ThorFXSetWildness = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXSetWildness");
	X3D_ThorFXSetTarget = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ThorFXSetTarget");
	X3D_ThorFXSetTargetAsObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ThorFXSetTargetAsObject");
	
	/* trail */
	X3D_TrailCreate = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailCreate");
	X3D_TrailSetObject = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailSetObject");
	X3D_TrailSetAlpha = (dFUNC3d)GetProcAddress(hLibXtreme3D, "TrailSetAlpha");
	X3D_TrailSetLimits = (dFUNC3d)GetProcAddress(hLibXtreme3D, "TrailSetLimits");
	X3D_TrailSetMinDistance = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailSetMinDistance");
	X3D_TrailSetUVScale = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailSetUVScale");
	X3D_TrailSetMarkStyle = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailSetMarkStyle");
	X3D_TrailSetMarkWidth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailSetMarkWidth");
	X3D_TrailSetEnabled = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TrailSetEnabled");
	X3D_TrailClearMarks = (dFUNC1d)GetProcAddress(hLibXtreme3D, "TrailClearMarks");
	
	/* tree */
	X3D_TreeCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "TreeCreate");
	X3D_TreeSetMaterials = (dFUNCdppp)GetProcAddress(hLibXtreme3D, "TreeSetMaterials");
	X3D_TreeSetBranchFacets = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetBranchFacets");
	X3D_TreeBuildMesh = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeBuildMesh");
	X3D_TreeSetBranchNoise = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetBranchNoise");
	X3D_TreeSetBranchAngle = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetBranchAngle");
	X3D_TreeSetBranchSize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetBranchSize");
	X3D_TreeSetBranchRadius = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetBranchRadius");
	X3D_TreeSetBranchTwist = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetBranchTwist");
	X3D_TreeSetDepth = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetDepth");
	X3D_TreeSetLeafSize = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetLeafSize");
	X3D_TreeSetLeafThreshold = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetLeafThreshold");
	X3D_TreeSetSeed = (dFUNC2d)GetProcAddress(hLibXtreme3D, "TreeSetSeed");
	
	/* viewer */
	X3D_ViewerCreate = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ViewerCreate");
	X3D_ViewerSetCamera = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerSetCamera");
	X3D_ViewerEnableVSync = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerEnableVSync");
	X3D_ViewerRender = (dFUNC1d)GetProcAddress(hLibXtreme3D, "ViewerRender");
	X3D_ViewerResize = (dFUNC5d)GetProcAddress(hLibXtreme3D, "ViewerResize");
	X3D_ViewerSetVisible = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerSetVisible");
	X3D_ViewerGetPixelColor = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ViewerGetPixelColor");
	X3D_ViewerGetPixelDepth = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ViewerGetPixelDepth");
	X3D_ViewerSetLighting = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerSetLighting");
	X3D_ViewerSetBackgroundColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerSetBackgroundColor");
	X3D_ViewerSetAmbientColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerSetAmbientColor");
	X3D_ViewerEnableFog = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerEnableFog");
	X3D_ViewerSetFogColor = (dFUNC2d)GetProcAddress(hLibXtreme3D, "ViewerSetFogColor");
	X3D_ViewerSetFogDistance = (dFUNC3d)GetProcAddress(hLibXtreme3D, "ViewerSetFogDistance");
	X3D_ViewerScreenToWorld = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ViewerScreenToWorld");
	X3D_ViewerWorldToScreen = (dFUNC4d)GetProcAddress(hLibXtreme3D, "ViewerWorldToScreen");
	X3D_ViewerCopyToTexture = (dFUNCdp)GetProcAddress(hLibXtreme3D, "ViewerCopyToTexture");
	
	/* water */
	X3D_WaterCreate = (dFUNC1d)GetProcAddress(hLibXtreme3D, "WaterCreate");
	X3D_WaterCreateRandomRipple = (dFUNC1d)GetProcAddress(hLibXtreme3D, "WaterCreateRandomRipple");
	X3D_WaterCreateRippleAtGridPosition = (dFUNC3d)GetProcAddress(hLibXtreme3D, "WaterCreateRippleAtGridPosition");
	X3D_WaterSetMask = (dFUNCdp)GetProcAddress(hLibXtreme3D, "WaterSetMask");
	X3D_WaterSetActive = (dFUNC2d)GetProcAddress(hLibXtreme3D, "WaterSetActive");
	X3D_WaterReset = (dFUNC1d)GetProcAddress(hLibXtreme3D, "WaterReset");
	X3D_WaterSetRainTimeInterval = (dFUNC2d)GetProcAddress(hLibXtreme3D, "WaterSetRainTimeInterval");
	X3D_WaterSetRainForce = (dFUNC2d)GetProcAddress(hLibXtreme3D, "WaterSetRainForce");
	X3D_WaterSetViscosity = (dFUNC2d)GetProcAddress(hLibXtreme3D, "WaterSetViscosity");
	X3D_WaterSetElastic = (dFUNC2d)GetProcAddress(hLibXtreme3D, "WaterSetElastic");
	X3D_WaterSetResolution = (dFUNC2d)GetProcAddress(hLibXtreme3D, "WaterSetResolution");
}

void X3D_Quit(void)
{
	FreeLibrary(hLibXtreme3D);
}

LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    /* copypasted from sample Xtreme3DCpp/template.cpp of Xtreme3D v2 for CPP */
	/* and edited by me */
	switch (message)
    {
		case WM_CREATE:
			return 0;
			
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;

		case WM_DESTROY:
			return 0;

		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
				{
					/* PostQuitMessage(0); */
					return 0;
				}
			}
			return 0;

		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
    }
}

HWND X3D_WindowCreate(int s_width, int s_height, int s_depth, BOOL fullscreen, char *caption)
{
	/* copypasted from sample Xtreme3DCpp/template.cpp of Xtreme3D v2 for CPP */
	/* and edited by me */
	WNDCLASS wc;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    BOOL bQuit = FALSE;
    HINSTANCE hInstance = GetModuleHandle(NULL);
	X3D_XED = FALSE;
	s_fullscreen = fullscreen;
	if (hInstance == NULL)
	{
		X3D_ERR = 1;
		return NULL;
	}

    /* Register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Xtreme3D";
    if (RegisterClass(&wc) == 0)
	{
		X3D_ERR = 2;
		return NULL;
	}
		
	/* Screen options */
    s_real_width = GetSystemMetrics(SM_CXSCREEN);
    s_real_height = GetSystemMetrics(SM_CYSCREEN);
	if ((s_real_width == 0) || (s_real_height == 0))
	{
		X3D_ERR = 3;
		return NULL;
	}
		
	/* Create main window */
    if (fullscreen) 
    {
      hwnd = CreateWindow (
      "Xtreme3D", caption, 
      WS_POPUPWINDOW | WS_VISIBLE,
      160, 120, s_width, s_height,
      NULL, NULL, hInstance, NULL);
      SetWindowPos(hwnd,HWND_TOP,0,0,s_width,s_height,SWP_NOSIZE);
    }
    else 
    {
      hwnd = CreateWindow (
      "Xtreme3D", caption, 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      160, 120, s_width, s_height,
      NULL, NULL, hInstance, NULL);
    }
	if (hwnd == NULL)
	{
		X3D_ERR = 4;
		return NULL;
	}
    ZeroMemory(&sDevMode, sizeof(DEVMODE));
    sDevMode.dmSize = sizeof(DEVMODE);
    sDevMode.dmPelsWidth = s_width;
    sDevMode.dmFields |= DM_PELSWIDTH;
    sDevMode.dmPelsHeight = s_height;
    sDevMode.dmFields |= DM_PELSHEIGHT;
    sDevMode.dmBitsPerPel = s_depth;
    sDevMode.dmFields |= DM_BITSPERPEL;
	int cds_result;
    if (fullscreen)
	{
		cds_result = ChangeDisplaySettings(&sDevMode, CDS_UPDATEREGISTRY);
		if (cds_result != DISP_CHANGE_SUCCESSFUL)
		{
			X3D_ERR = (1000 + cds_result);
			return NULL;
		}
	}
	
	return hwnd;
}

int X3D_WindowDestroy(HWND hwnd)
{
	/* copypasted from sample Xtreme3DCpp/template.cpp of Xtreme3D v2 for CPP */
	/* and edited by me */
	int cds_result;
	if (!DestroyWindow(hwnd))
	{
		X3D_ERR = X3D_ERR_DW;
		return X3D_ERR;
	}
	sDevMode.dmPelsWidth = s_real_width;
    sDevMode.dmPelsHeight = s_real_height;
    if (s_fullscreen)
	{
		cds_result = ChangeDisplaySettings(&sDevMode, CDS_UPDATEREGISTRY);
		if (cds_result != DISP_CHANGE_SUCCESSFUL)
		{
			X3D_ERR = (1000 + cds_result);
			return X3D_ERR;
		}
	}
	return 0;
}

BOOL X3D_WindowXed()
{
	if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return TRUE;
		}
		else
		{
			TranslateMessage (&msg);
			DispatchMessage (&msg);
		}
	}
	return FALSE;
}

int X3D_GetLastErrorCode(void)
{
	return X3D_ERR;
}

/*
static float X3D_GetFPS(void)
{
   static float FPSc = 0.0f;
   static float FPSr = 0.0f;
   float nextSecond = 0.0f;
   static float prevSecond = 0.0f;
   FPSc++;
   nextSecond = GetTickCount() * 0.001f;
   if(nextSecond - prevSecond > 1.0f)
      {
	  prevSecond = nextSecond;  
      FPSr = FPSc;
      FPSc = 0;
      }
   return FPSr;
}*/