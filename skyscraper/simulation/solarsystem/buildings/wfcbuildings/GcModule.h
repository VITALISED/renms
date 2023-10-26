#pragma once

#include <skyscraper.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSubset.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcWFCScene.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/data/TkMetaData.h>
#include <metadata/source/simulation/environment/wfcbuildings/decoration/gcwfcdecorationitem.meta.h>

SKYSCRAPER_BEGIN

class cGcModuleSet;

enum eBlockRotation
{
    EBlockRotation_0,
    EBlockRotation_90,
    EBlockRotation_180,
    EBlockRotation_270,
};

class cGcModule
{
    cGcModuleSet *mModuleSet;
    const int miIndex;
    const int miModuePrototypeIndex;
    const eBlockRotation meRotation;
    const float mfRelativeProbability;
    const float mfPLogP;
    const bool mbWalkable;
    const cTkBitArray<unsigned __int64, 128> maConnectors[6];
    const int miNextRotationIndex;
    const TkID<128> mLayoutGroup;
    cGcWFCScenes mGeometry;
    cGcModuleSubset maPossibleNeighbours[6];
    unsigned __int8 miRequireAboveTerrain;
    unsigned __int8 miRequireBelowTerrain;
    cGcModuleSubset mSymmetricPartners;
    cTkVector<cGcWFCDecorationItem const *> mapDecorationItems[2];
};
SKYSCRAPER_END