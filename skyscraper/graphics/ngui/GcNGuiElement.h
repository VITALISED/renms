/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <graphics/ngui/NGuiAnimationEvent.h>
#include <graphics/ngui/NGuiInputType.h>
#include <toolkit/graphics/ngui/TkNGuiTypeUndoable.h>
#include <toolkit/maths/geometry/TkBBox2d.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>

#include <graphics/ngui/metadata/gcnguielementdata.meta.h>
#include <graphics/ngui/metadata/gcnguilayoutdata.meta.h>

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