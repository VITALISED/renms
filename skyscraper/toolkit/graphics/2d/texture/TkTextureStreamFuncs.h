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

#include <toolkit/graphics/2d/texture/TkGnmxContext.h>
#include <toolkit/graphics/2d/texture/TkMipReportBuffer.h>
#include <toolkit/utilities/TkStrongType.h>

SKYSCRAPER_BEGIN

class cTkTexture;

class cTkTextureStreamFuncs
{
  public:
    bool (*mStreamFunc)(TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, void *, int, int, int, int);
    bool (*mStreamDeleteFunc)(void *);
    void (*mAbortBakeFunc)(void *);
    void (*mEvictFunc)(cTkTexture *, void *, int);
    bool (*mBeginProbeFunc)(TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, void *, int, int);
    void (*mCompleteProbeFunc)(cTkGnmxContext *, cTkTexture *, void *, int, int);
    uint64_t (*mGatherProbeFunc)(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, void *, TkMipReportBuffer *, int *, int, int, bool *, bool *,
        bool *);
    bool mbIsVirtualTexture;
};

SKYSCRAPER_END