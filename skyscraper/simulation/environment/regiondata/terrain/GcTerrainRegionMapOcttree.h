/**
 * @file GcTerrainRegionMapOcttree.h
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

SKYSCRAPER_BEGIN

class cGcRegionTerrain;

class cGcTerrainRegionMapOcttree
{
  public:
    struct sTableEntry
    {
        uint16_t muFirstNode : 10;
        uint16_t muNumNodes : 6;
    };

    struct sNode
    {
        cGcRegionTerrain *mpRegion;
    };

    struct sNodePos
    {
        uint16_t muX;
        uint16_t muY;
        uint16_t muZ;
    };

    cGcTerrainRegionMapOcttree::sTableEntry maRootTable[2048];
    uint16_t mauRootNodeIndices[1024];
    uint16_t mauRootNodeHashes[10000];
    cGcTerrainRegionMapOcttree::sNode maNodes[10000];
    cGcTerrainRegionMapOcttree::sNodePos maPositions[10000];
    uint8_t mauDepths[10000];
    uint16_t mauParents[10000];
    uint16_t mauChildren[10000];
    uint16_t muNumNodes;
    uint16_t muNumRootNodes;
    uint16_t muNumLODs;
    uint16_t muRootMask;
    long double mfMapScale;
    long double mfMapOffset;
    bool mbAddingRoots;
};

SKYSCRAPER_END