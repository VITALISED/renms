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

#include <graphics/ngui/GcNGuiStyledString.h>
#include <graphics/ngui/GcNGuiText.h>
#include <toolkit/system/memory/TkMemoryManager.h>

SKYSCRAPER_BEGIN

class cGcNGuiTextSpecial : public cGcNGuiText
{
  public:
    cGcNGuiStyledString::StyledStringLayout mStyledStringLayout;
    std::string msDisplayString;
    bool mbBigString;
    bool mbUpdateLayout;

    ~cGcNGuiTextSpecial();
    void Render();
    int GetType() { return NULL; }
    void EditElement();
    void SetNeedsUpdate();
    eNGuiEditorIcons GetSceneTreeIcon();
};

SKYSCRAPER_END