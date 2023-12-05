/**
 * @file TkNGuiLayer.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/TkNGuiElementID.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/maths/geometry/TkBBox2d.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>

SKYSCRAPER_BEGIN

enum eNGuiAlignmentType
{
    eAlignment_TopLeft,
    eAlignment_TopCenter,
    eAlignment_TopRight,
    eAlignment_CenterLeft,
    eAlignment_Center,
    eAlignment_CenterRight,
    eAlignment_BottomLeft,
    eAlignment_BottomCenter,
    eAlignment_BottomRight,
    eAlignmentTypeMax,
};

class cTkNGuiLayer
{
    enum ELayoutType
    {
        eLayout_SameLine,
        eLayout_NextLine,
        eLayout_SetPosition,
        eLayout_MoveCursor,
    };

    cTkVector2 mContentSize;
    cTkVector2 mContentMin;
    cTkVector2 mPosition;
    cTkVector2 mSize;
    cTkVector2 mCursorPosition;
    cTkBBox2d mLastContentBox;
    cTkBBox2d mLastContentBoxInner;
    float mfScale;
    float mfIndent;
    float mfCurrentLineHeight;
    cTkNGuiLayer::ELayoutType meLayout;
    cTkNGuiElementID mID;
    eNGuiAlignmentType meAlignment;
    eNGuiInputType meInput;
    cTkVector2 mSavedCursor;
    eNGuiAlignmentType meSavedAlignment;
    float mfSavedLineHeight;
};

SKYSCRAPER_END