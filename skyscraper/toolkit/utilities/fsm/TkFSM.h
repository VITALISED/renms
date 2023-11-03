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
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/fsm/TkFSMState.h>

SKYSCRAPER_BEGIN

class cTkFSM
{
    const cTkFSMStateOffset *mpOffsetTable;
    cTkFSMState *mpState;
    TkID<128> mRequestedChangeNewState;
    const void *mpRequestedChangeUserData;
    bool mbRequestedChangeForceRestart;

    virtual ~cTkFSM();
    virtual void Construct(const cTkFSMStateOffset *, const TkID<128> *);
    virtual void Update(float);
    virtual void Destruct();
    virtual void StatePrepare(cTkFSMState *, const void *);
    virtual void StateRelease(cTkFSMState *, const void *);
};

SKYSCRAPER_END