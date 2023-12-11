/**
 * @file GcRegionKnowledge.h
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

#pragma once

#include <skyscraper.h>

#include <simulation/ecosystem/GcCreatureSwarm.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorCreatures.h>
#include <simulation/navigation/regionknowledge/GcNavChunkInfo.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

class cGcRegionTerrain;

enum eRegionKnowledgeDirection
{
    ERegionKnowledgeDirection_NegX,
    ERegionKnowledgeDirection_PosX,
    ERegionKnowledgeDirection_NegZ,
    ERegionKnowledgeDirection_PosZ,
    ERegionKnowledgeDirection_HorizontalCount,
    ERegionKnowledgeDirection_NegY,
    ERegionKnowledgeDirection_PosY,
    ERegionKnowledgeDirection_Count,
};

class cGcRegionKnowledge;

class cGcRegionKnowledgeRef
{
    const cGcRegionKnowledge *mpKnowledge;
    cGcRegionKnowledgeRef *mpPrev;
    cGcRegionKnowledgeRef *mpNext;
    TkHandle mNode;
};

class cGcRegionKnowledge
{
  public:
    struct Cell
    {
        float mfHeight;
        uint16_t miChunk;
        int8_t mbIsValid : 1;
        int8_t mbPassableNegX : 1;
        int8_t mbPassablePosX : 1;
        int8_t mbPassableNegZ : 1;
        int8_t mbPassablePosZ : 1;
        int8_t mbDnPortalNegX : 1;
        int8_t mbDnPortalPosX : 1;
        int8_t mbDnPortalNegZ : 1;
        int8_t mbDnPortalPosZ : 1;
        int8_t mbUpPortalNegX : 1;
        int8_t mbUpPortalPosX : 1;
        int8_t mbUpPortalNegZ : 1;
        int8_t mbUpPortalPosZ : 1;
        int8_t mbRegionPortalNegX : 1;
        int8_t mbRegionPortalPosX : 1;
        int8_t mbRegionPortalNegZ : 1;
        int8_t mbRegionPortalPosZ : 1;
    };

    struct Layer
    {
        cGcRegionKnowledge::Cell *maCells;
        char *maTempTerrainType;
        uint16_t *maTempTerrainExtra;
        float *maTempHeight;
        cTkVector3 *maTempPlanetPos;
        int miCellsX;
        int miCellsZ;
        int miBorderX;
        int miBorderZ;
        int miBeginChunk;
        int miEndChunk;
    };

    cTkVector3 mvPlanetPos;
    cTkVector3 mvRegionNormal;
    cTkVector3 mvSidePlaneNorm[4];
    cGcRegionKnowledge::Layer *mapLayers[12];
    cGcRegionKnowledge *mpNeighbors[6];
    cGcRegionTerrain *mpKnowledgeRegion;
    cGcNavChunkInfo *maChunkInfo;
    uint16_t *maChunkLinks;
    eRegionKnowledgeDirection *maLinkDirs;
    std::atomic<int> mbIsBuilt;
    bool mbRequestedNavMeshAlloc;
    int64_t miKnowledgeID;
    cGcRegionKnowledgeRef *mpUserList;
    cTkStackVector<cGcRegionKnowledge *, 37> maRoutineUsers;
    cGcCreatureRoutine *maRoutines;
    int miNumRoutines;
    bool mbHasRoutines;
    float mfCenterHeight;
    int miCellsX;
    int miCellsY;
    int miCellsZ;
    int miOffsetX;
    int miOffsetY;
    int miOffsetZ;
    int miCreatureIds[4];
    int miNumCreatureTypes;
    int miMaxNeighborLayerCount;
    int miNumLayers;
    int miNumChunks;
    int miLod;
    uint8_t miInterestRecomputeCount[6];
};
SKYSCRAPER_END