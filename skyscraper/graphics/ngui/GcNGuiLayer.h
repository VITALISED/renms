/**
 * @file GcNGuiLayer.h
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

#include <graphics/ngui/GcNGuiElement.h>
#include <toolkit/graphics/2d/ngui/TkHashedNGuiElement.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>

#include <graphics/ngui/metadata/gcnguilayerdata.meta.h>
#include <toolkit/ngui/tknguigraphicstyledata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiLayer : public cGcNGuiElement
{
  public:
    cTkVector<cGcNGuiElement *> mapElements;
    cTkVector<cGcNGuiLayer *> mapLayerElements;
    cTkVector<cTkVector2> maPinnedPositions;
    cTkNGuiGraphicStyleData mPreviousGraphicsStyle;
    void (*mpRenderFunction)(void *);
    void *mpRenderFunctionData;
    cGcNGuiLayerData *mpLayerData;
    cTkLinearHashTable<cTkHashedNGuiElement, cGcNGuiElement *, cTkHashedNGuiElement> *mpElementHashTable;
    uint64_t muUniqueID;
    bool mbExpanded;

    ~cGcNGuiLayer();
    void Render();
    int GetType() { return NULL; }
    void EditElement();
    bool SelectableInEditor();
    void SetNeedsUpdate();
    void Deselect();
    void Resized();
    void AttachMetadata(cTkClassPointer *);
    void DetachMetadata(cTkClassPointer *);
    eNGuiEditorIcons GetSceneTreeIcon();
    void GetSceneTreeText(cTkFixedString<128, char> *);
    void RenderAdditionalOverlayIcons(const cTkVector2 *, const cTkVector2 *);
    void RenderTreeControls();
};

SKYSCRAPER_END