#pragma once

#include <skyscraper.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcMap.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModule.h>
#include <toolkit/maths/numeric/TkTuple.h>

SKYSCRAPER_BEGIN

struct sSlotDecoration
{
    const cGcWFCDecorationItem *mpData;
    eBlockRotation meRotation;
    int miSceneIndex;
    bool mbDisableDecoration;
};

class cGcSlot
{
    const cTkIntTuple3<int> mPosition;
    cGcMap *mMap;
    cGcModule *mpModule;
    int miModuleGeometryIndex;
    unsigned __int8 miAboveTerrain;
    cGcModuleSubset mModules;
    float mfEntropy;
    bool mbEntropyCached;
    bool mbIsInConstraintPropagationQueue;
    bool mbIsConnected;
    bool mbIsFrontier;
    bool mbReachable;
    sSlotDecoration mDecoration;
};

SKYSCRAPER_END