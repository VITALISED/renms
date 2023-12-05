/**
 * @file TkFSM.cpp
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

#include <toolkit/utilities/fsm/TkFSM.h>

SKYSCRAPER_BEGIN

cTkFSM::~cTkFSM()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cTkFSM::Construct(const cTkFSMStateOffset *, const TkID<128> *)
{
    EMPTY_CALL_VOID();
}

void cTkFSM::Update(float)
{
    EMPTY_CALL_VOID();
}

void cTkFSM::Destruct()
{
    EMPTY_CALL_VOID();
}

void cTkFSM::StatePrepare(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

void cTkFSM::StateRelease(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END