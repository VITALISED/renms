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

#include <toolkit/data/TkClassPointer.h>
#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>
#include <toolkit/utilities/engine/TkEngineUtils.h>
#include <toolkit/voxel/TkHalfVectors.h>

SKYSCRAPER_BEGIN

template <int32_t liSize>
union TkID {
    TkID() {}

    TkID(const char *lpacString)
    {
        // uses hashes pretty sure, gonna have to figure out spookyhash later
        strcpy_s(mChars, liSize, lpacString);
    }

    char mChars[liSize / 8];
    uint64_t mUInt64[liSize / 64];
};

template <int32_t liSize>
struct TkIDHashed
{
    TkID<liSize> mID;
    uint64_t mHash;
};

class cTkMetaDataFunctionLookup
{
  public:
    const cTkMetaDataClass *mpClassMetadata;
    void (*mCreateDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *);
    void (*mRenderFunction)(cTkClassPointer *);
    void (*mFixingFunction)(cTkClassPointer *, bool, unsigned __int64);
    void (*mValidateDataFunction)(cTkClassPointer *);
    bool (*mEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *);
    void (*mCopyFunction)(cTkClassPointer *, const cTkClassPointer *);
    cTkClassPointer *(*mCreatePtrFunction)(cTkClassPointer *result);
    unsigned __int64 (*mHashFunction)(const cTkClassPointer *, unsigned __int64, bool);
    void (*mDestroyFunction)(cTkClassPointer *);
};

SKYSCRAPER_END