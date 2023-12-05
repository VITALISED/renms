/**
 * @file TkFSMState.h
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

#include <engine/source/engine/EgRenderer.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cTkFSM;

class cTkFSMStateOffset
{
    TkID<128> mID;
    uint64_t mnOffset;
};

class cTkFSMState
{
  public:
    TkID<128> mID;
    cTkFSM *mpFSM;
    uint64_t mu64StateTimingStart;

    virtual ~cTkFSMState();
    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(float);
    virtual void Event(unsigned int, const void *);
    virtual void Release(cTkFSMState *, const void *);
    virtual void Destruct();
    virtual void Render(EgRenderParity::List);
    virtual bool SupportsEvenOddRendering();
};

SKYSCRAPER_END