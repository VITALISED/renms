/**
 * @file GcNGuiGraphic.cpp
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

#include <graphics/ngui/GcNGuiGraphic.h>

SKYSCRAPER_BEGIN

cGcNGuiGraphic::~cGcNGuiGraphic()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcNGuiGraphic::Render()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiGraphic::EditElement()
{
    EMPTY_CALL_VOID();
}

bool cGcNGuiGraphic::SelectableInEditor()
{
    EMPTY_CALL();
}

void cGcNGuiGraphic::AttachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

eNGuiEditorIcons cGcNGuiGraphic::GetSceneTreeIcon()
{
    return EIcon_photo;
}

void cGcNGuiGraphic::GetSceneTreeText(cTkFixedString<128, char> *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END