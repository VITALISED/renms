#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkArray.h>
#include <metadata/tkpalettetexture.meta.h>
#include <metadata/simulation/environment/gcobjectspawndata.meta.h>
#include <metadata/simulation/ecosystem/gccreaturespawndata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet;

enum eTerrainAtlasTextures
{
	ETerrainAtlas_Base_Slope,
	ETerrainAtlas_Base,
	ETerrainAtlas_BaseAlt_Slope,
	ETerrainAtlas_BaseAlt,
	ETerrainAtlas_Mount_Slope,
	ETerrainAtlas_Mount,
	ETerrainAtlas_MountAlt_Slope,
	ETerrainAtlas_MountAlt,
	ETerrainAtlas_Detail_Base_Slope,
	ETerrainAtlas_Detail_Base,
	ETerrainAtlas_Detail_BaseAlt_Slope,
	ETerrainAtlas_Detail_BaseAlt,
	ETerrainAtlas_Detail_Mount_Slope,
	ETerrainAtlas_Detail_Mount,
	ETerrainAtlas_Detail_MountAlt_Slope,
	ETerrainAtlas_Detail_MountAlt,
	ETerrainAtlas_Num,
};

class cGcPlanetControls
{
	class cGcPlanetGenerateRequest
	{
		bool mbRequired;
		eTerrainAtlasTextures mAtlasElement;
		ePalette mePalette;
		cGcObjectSpawnData* mpObjectData;
		cGcCreatureSpawnData* mpCreatureData;
		eTileType meTileType;
		cTkSeed mSeed;
	};

	cTkBitArray<unsigned int, 32> mTerrainNoiseLayers;
	cGcPlanetControls::cGcPlanetGenerateRequest maGenerateRequests[36];
	bool mbShowVisibilityOptions;
	bool mbShowColourOptions;
	float mfRegionGenerateStart;
	float mfRegionGenerateEnd;
	bool mbRegionGenerateActive;
	float mfEditDistance;
	bool mbEditPosition;
	eBuildingClass meTargetBuilding;
	cTkPersonalRNG mBuildingJumpRNG;
	cGcPlanetControls::BuildingJumpRequest meBuildingJumpRequest;
	int miNumBuildingJumpAttempts;
	bool mbSwitchedToDebugCam;
	cGcPlanet* mpPlanet;
};

SKYSCRAPER_END