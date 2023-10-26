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

#include <graphics/ngui/GcNGuiElement.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/graphics/ngui/TkHashedNGuiElement.h>
#include <metadata/toolkit/ngui/tknguigraphicstyledata.meta.h>
#include <metadata/source/graphics/ngui/metadata/gcnguilayerdata.meta.h>

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