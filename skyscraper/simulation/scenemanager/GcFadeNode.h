/**
 * @file GcFadeNode.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <toolkit/core/types/TkHandle.h>

SKYSCRAPER_BEGIN

enum eFadeState
{
    EFade_In,
    EFade_Out,
    EFade_Visible,
    EFade_Hidden,
};

enum eFadeType : uint8_t
{
    FadeInThenFadeOut,
    CrossFade,
};

class cGcFadeNodeBase
{
  public:
    float mfTimer;
    float mfTotalTime;
    int miNodeParam;
    int miNodeSetIndex;
    eFadeState meFadeState;
    eFadeType meFadeType;

    virtual void SetNodeActivation(bool);
    virtual void CheckNodeActivation(bool);
    virtual void SetNodeParamF(float);
    virtual bool Update();
};

class cGcFadeNode : public cGcFadeNodeBase
{
  public:
    TkHandle mNode;
};

SKYSCRAPER_END