#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/NGuiAnimationEvent.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/graphics/2d/ngui/TkNGuiLayer.h>
#include <toolkit/graphics/2d/ngui/TkNGuiStyleEntry.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/ngui/tknguiforcedstyle.meta.h>

SKYSCRAPER_BEGIN

template <typename T>
struct cTkUiDataMap
{
    cTkVector<T> maUiData;
    cTkVector<cTkNGuiElementID> maElementIndices;
};

struct cTkNGui
{
    cTkVector<eNGuiInputType> mInputStack;
    float mafFrameInverseMatrix[6];
    eNGuiInputType meLastInput;
    int miInputDepth;
    cTkVector2 mScreenSize;
    bool mbRendering;
    cTkVector<eNGuiForcedStyle> maeForcedStyleStack;
    eNGuiAnimationEvent meNextElementAnimateEvent;
    bool mbNextElementAnimateIn;
    bool mbNextElementAnimateReset;
    cTkUiDataMap<cTkNGuiElementData> mElementDataMap;
    cTkVector<cTkNGuiElementID> maIDStack;
    cTkVector<cTkNGuiLayer> maLayerStack;
    cTkVector<cTkVector<cTkNGuiGraphicStyleEntry>> maGraphicStyleArray;
    cTkVector<cTkVector<cTkNGuiGraphicStyleEntry>> maTextStyleArray;
    robin_hood::detail::Table<
        true, 80, unsigned __int64, unsigned int, robin_hood::hash<unsigned __int64, void>,
        std::equal_to<unsigned __int64>>
        maIDUseCounts;
    bool mbForceSpecialtextRebuild;
    bool mbRebuildSpecialText;
    bool mbClippingEnabled;
    bool mbUsingWindowClipRegion;
    bool mbNodeGraphNodeActive;
    cTkBBox2d mWindowClipRegion;
};

SKYSCRAPER_END