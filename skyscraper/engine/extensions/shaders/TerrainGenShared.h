/**
 * @file TerrainGenShared.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// NOTE - this file doesnt actually map here, just not sure where to put it since it's "exported".
//  it's highly likely this is maybe just as volatile as metadata. need to keep tabs on this guy

#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

namespace GPU
{

struct vec3
{
    float x;
    float y;
    float z;
};

struct vec4
{
    float x;
    float y;
    float z;
    float w;
};

union $51FF97503943AB88CE860D641BF6512E {
    GPU::vec4 cols[4];
    float c[4][4];
    float x[16];
};

struct mat4x4
{
    union {
        GPU::vec4 cols[4];
        float c[4][4];
        float x[16];
    };
};

struct sGetTriangleCountOutput
{
    unsigned int muPosStart;
    unsigned int muPosCount;
    float mfRatio;
    unsigned int muSeed;
    unsigned int muMaterial;
    unsigned int muSecondaryMaterial;
};

struct sTerrainVertexUnpacked
{
    GPU::vec3 mPosition;
    float mfTileRatio;
    GPU::vec3 mSmoothNormal;
    float mfTileMaterialA;
    float mfTileMaterialB;
};

struct sObjectTypeInfo
{
    float mfMaxDensity;
};

struct sObjectTypePriorityMap
{
    unsigned int maTypeMapStart[256];
    unsigned int maTypeMapCount[256];
    long double maTypeMapRecipCount[256];
    GPU::sObjectTypeInfo maTypeInfo[256];
    unsigned int maiPriorityNums[3];
    unsigned int maiPriorityStarts[3];
};

struct sAddObjectPosIndex
{
    union {
        unsigned int muPosIndex_ObjectType;
        struct
        {
            uint16_t muPosIndex;
            uint16_t muObjectType;
        };
    };
    float mfDensity;
};

struct sSpawnObjectGlobalParams
{
    GPU::mat4x4 mRegionCubeMatrix;
    GPU::mat4x4 mRegionInvCubeMatrix;
    GPU::vec3 mRegionNormal;
    GPU::vec3 mRegionVoxelScale;
    int mRegionVoxelsX;
    int mRegionVoxelsY;
    int mRegionVoxelsZ;
    int mRegionBorder;
    GPU::vec3 mRegionMapPosition;
    float mfRegionMapRadius;
    float mfEnvMinPlacementBlendValuePatch;
    float mfEnvMaxPlacementBlendValuePatch;
    float mfEnvMinPlacementObjectScale;
    float mfPlanetSeaLevel;
    GPU::vec3 mPlanetPosition;
};

struct sSpawnObjectPerTypeParams
{
    int meTileType;
    int meGroundColourIndex;
    int mbRelativeToSeaLevel;
    float mfMinHeight;
    float mfMaxHeight;
    float mfMaxDensity;
    float mfSlopeDensity;
    float mfFlatDensity;
    float mfSlopeMultiplier;
    int mbNoiseActive;
    float mfNoiseRegionScale;
    float mfNoisePatchSize;
    float mfNoiseCoverage;
    int meNoiseCoverageType;
    unsigned int muNoiseSeed;
};

struct sSpawnObjectResult
{
    float mfBlend;
    float mfNoise;
};

} // namespace GPU

SKYSCRAPER_END