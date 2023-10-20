#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eInsideOutside
{
    EInsideOutside_Both = 0,
    EInsideOutside_InteriorOnly = 1,
    EInsideOutside_ExteriorOnly = 2,
}
#include <?>

class cGcWFCDecorationItem
{
    static unsigned long long muNameHash = 0x9DDB490E0E777CD8;
    static unsigned long long muTemplateHash = 0x37516E17AC76EC4E;

    TkID<128> mName;
    TkID<128> mGroup;
    float mfRelativeProbability;
    float mfNoSceneProbability;
    bool mbInclude;
    cTkDynamicArray<cGcWeightedResource> maScenes;
    cTkDynamicArray<TkID<128>> maApplicableModules;
    bool mbRotate;
    bool mbRequireReachable;
    int miMaxPerBuilding;
    int miMinPerBuilding;
    bool mbRequireAboveTerrain;
    eInsideOutside InsideOutside;
    eLevel Level;
    cGcWFCDecorationFace Left;
    cGcWFCDecorationFace Down;
    cGcWFCDecorationFace Back;
    cGcWFCDecorationFace Right;
    cGcWFCDecorationFace Up;
    cGcWFCDecorationFace Forward;
}
