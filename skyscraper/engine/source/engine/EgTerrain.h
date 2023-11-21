#pragma once

#include <skyscraper.h>

#define EGTERRAIN_FLAG 10000

SKYSCRAPER_BEGIN

class cEgTerrain
{
  public:
    enum List
    {
        ActionI                       = EGTERRAIN_FLAG + 1,
        ShapeI                        = EGTERRAIN_FLAG + 2,
        NumRegionsI                   = EGTERRAIN_FLAG + 3,
        ModeI                         = EGTERRAIN_FLAG + 4,
        StartPosF                     = EGTERRAIN_FLAG + 5,
        PathVectorAddressI            = EGTERRAIN_FLAG + 6,
        PathStartPosF                 = EGTERRAIN_FLAG + 7,
        PathTargetPosF                = EGTERRAIN_FLAG + 8,
        AddSceneryCallbackAddressI    = EGTERRAIN_FLAG + 9,
        RemoveSceneryCallbackAddressI = EGTERRAIN_FLAG + 10,
        AddCreaturesCallbackAddressI  = EGTERRAIN_FLAG + 11,
        VoxelToGetF                   = EGTERRAIN_FLAG + 12,
        VoxelDensityF                 = EGTERRAIN_FLAG + 13,
        VoxelTileI                    = EGTERRAIN_FLAG + 14,
        ShapePosF                     = EGTERRAIN_FLAG + 15,
        ShapeSizeF                    = EGTERRAIN_FLAG + 16,
    };

    enum Actions
    {
        Add,
        Subtract,
        IncreaseSize,
        DecreaseSize,
        Regenerate,
        CalculatePath,
    };
};

SKYSCRAPER_END