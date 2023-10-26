#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

struct sTransformedBasebuildingPart
{
    const TkID<128> mPartID;
    cTkMatrix34 mTransform;
    const float mfScale;
};

struct sWFCNavigationSubgraphNode
{
    cTkMatrix34 mTransform;
    bool mbIsPOI;
    float mfArriveDistance;
    cTkSmartResHandle mCustomInteractionResHandle;
};

class cGcWFCNavigationSubGraph
{
    cTkVector<sWFCNavigationSubgraphNode> mNodes;
    int maiConnections[6];
    cTkVector<std::pair<int,int> > mEdges;
    bool mbConnectNodesByDistance;
    cTkVector<std::pair<TkID<128>,cTkMatrix34> > mNPCs;
};


class cGcWFCScene
{
    cTkSmartResHandle mResHandle;
    bool mbNeedsToParseScene;
    bool mbParsedBasebuildingTerrainEditBoxes;
    cTkVector<sTransformedBasebuildingPart> maBasebuildingParts;
    cGcWFCNavigationSubGraph mNavigationSubGraph;
    cTkVector<std::pair<cTkAABB,cTkMatrix34> > maTerrainEditBoxes;
    cTkVector<std::pair<cTkAABB,cTkMatrix34> > maBasebuildingTerrainEditBoxes;
};

struct sWeightedWFCScene
{
    const cGcWFCScene *mScene;
    const float mfRelativeProbability;
};

class cGcWFCScenes
{
    cTkVector<sWeightedWFCScene> mItems;
};

SKYSCRAPER_END