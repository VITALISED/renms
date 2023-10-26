#pragma once

#include <skyscraper.h>
#include <graphics/ngui/NGuiAnimationEvent.h>
#include <graphics/ngui/NGuiInputType.h>
#include <toolkit/graphics/ngui/TkNGuiTypeUndoable.h>
#include <toolkit/maths/geometry/TkBBox2d.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <metadata/source/graphics/ngui/metadata/gcnguilayoutdata.meta.h>
#include <metadata/source/graphics/ngui/metadata/gcnguielementdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiLayer;

class cGcNGuiElement
{
    enum eLayoutChangeEvent
    {
        ELayoutChange_Nothing,
        ELayoutChange_PositionMode,
        ELayoutChange_WidthMode,
        ELayoutChange_HeightMode,
        ELayoutChange_ConstrainMode,
        ELayoutChange_Size,
        ELayoutChange_Width,
        ELayoutChange_Height,
        ELayoutChange_Value,
        ELayoutChange_ColourPreset,
    };

    struct sGcNGuiElementAnimSettings
    {
        __int8 mbRequestAnimActivate : 1;
        __int8 mbRequestAnimReset : 1;
    };

    cTkBBox2d mContentBBox;
    cTkVector2 mvParallaxOffset;
    cTkNGuiTypeUndoable<cGcNGuiLayoutData> *mpUndoMoveEvent;
    cTkNGuiTypeUndoable<cGcNGuiLayoutData> *mpUndoResizeEvent;
    cTkNGuiTypeUndoable<cGcNGuiLayoutData> *mpUndoLayoutEvent;
    cGcNGuiLayer *mpParent;
    cGcNGuiElementData *mpElementData;
    eNGuiInputType meInputThisFrame;
    cGcNGuiElement::eLayoutChangeEvent meLayoutChangeEvent;
    eNGuiAnimationEvent meRequestAnim;
    cGcNGuiElement::sGcNGuiElementAnimSettings mAnim;
    bool mbSelectedToEdit;
};

SKYSCRAPER_END