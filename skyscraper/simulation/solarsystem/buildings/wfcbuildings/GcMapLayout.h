#pragma once

#include <skyscraper.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSet.h>

SKYSCRAPER_BEGIN

struct sModulePreset
{
    cGcModule *mModule;
    const cTkIntTuple3<int> mPosition;
};

class cGcMapLayout
{
    const cGcModuleSet *mModuleSet;
    const float mfRelativeProbability;
    cGcWFCScene mScene;
    cTkVector<sModulePreset> mModulePresets;
    cTkVector<cTkIntTuple3<int> > mSlotsWithDecorationDisabled;
    cTkVector<cTkIntTuple3<int> > mNonWalkableSlots;
    cTkIntTuple3<int> mWFCStartPosition;
    bool mbHasWFCStartPosition;
    cTkIntTuple3<int> mSize;
    bool mbSymmetric;
    bool *mapActiveSlots;
    cTkSmartResHandle mResHandle;
    bool mbHasFinishedParsing;
};

SKYSCRAPER_END