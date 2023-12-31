/**
 * @file GcNGuiLayer.cpp
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

#include <graphics/ngui/GcNGuiLayer.h>

SKYSCRAPER_BEGIN

cGcNGuiLayer::~cGcNGuiLayer()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcNGuiLayer::Render()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::EditElement()
{
    EMPTY_CALL_VOID();
}

bool cGcNGuiLayer::SelectableInEditor()
{
    EMPTY_CALL();
}

void cGcNGuiLayer::SetNeedsUpdate()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::Deselect()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::Resized()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::AttachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::DetachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

eNGuiEditorIcons cGcNGuiLayer::GetSceneTreeIcon()
{
    if (this->mapElements.size()) { return static_cast<eNGuiEditorIcons>(this->mbExpanded + EIcon_folder3); }
    else
        return EIcon_folder;
}

void cGcNGuiLayer::GetSceneTreeText(cTkFixedString<128, char> *)
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::RenderAdditionalOverlayIcons(const cTkVector2 *, const cTkVector2 *)
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::RenderTreeControls()
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END