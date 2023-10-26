#pragma once

#include <skyscraper.h>
#include <toolkit/voxel/TkHalfVectors.h>

SKYSCRAPER_BEGIN

class cTkTerrainVertex
{
	cTkHalfVector4 mPosition;
	cTkHalfVector4 mTile;
	cTkHalfVector4 mTexCoords_Normal;
	cTkHalfVector4 mTexCenter_DPDU;
};

class cTkTerrainVertexData
{
	cTkTerrainVertex* maVertexArray;
	int miNumVertices;
	int miMaxNumVertices;
};

SKYSCRAPER_END