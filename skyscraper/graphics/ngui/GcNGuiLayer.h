#pragma once

#include <skyscraper.h>

#include <graphics/ngui/GcNGuiElement.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/graphics/ngui/TkHashedNGuiElement.h>
#include <metadata/ngui/tknguigraphicstyledata.meta.h>
#include <metadata/graphics/ngui/metadata/gcnguilayerdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiLayer : public cGcNGuiElement
{
    cTkVector<cGcNGuiElement*> mapElements;
    cTkVector<cGcNGuiLayer*> mapLayerElements;
    cTkVector<cTkVector2> maPinnedPositions;
    cTkNGuiGraphicStyleData mPreviousGraphicsStyle;
    void (*mpRenderFunction)(void *);
    void *mpRenderFunctionData;
    cGcNGuiLayerData *mpLayerData;
    cTkLinearHashTable<cTkHashedNGuiElement, cGcNGuiElement*, cTkHashedNGuiElement> *mpElementHashTable;
    unsigned __int64 muUniqueID;
    bool mbExpanded;
};

SKYSCRAPER_END