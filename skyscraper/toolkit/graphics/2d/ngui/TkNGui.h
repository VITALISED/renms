/**
 * @file TkNGui.h
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