/**
 * @file TkMetaData.h
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

#include <toolkit/core/types/TkTypes.h>
#include <toolkit/data/TkClassPointer.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>
#include <toolkit/voxel/TkHalfVectors.h>

SKYSCRAPER_BEGIN

class cTkMetaDataClass;

class cTkMetaDataFunctionLookup
{
  public:
    const cTkMetaDataClass *mpClassMetadata;
    void (*mCreateDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *);
    void (*mRenderFunction)(cTkClassPointer *);
    void (*mFixingFunction)(cTkClassPointer *, bool, uint64_t);
    void (*mValidateDataFunction)(cTkClassPointer *);
    bool (*mEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *);
    void (*mCopyFunction)(cTkClassPointer *, const cTkClassPointer *);
    cTkClassPointer *(*mCreatePtrFunction)(cTkClassPointer *result);
    uint64_t (*mHashFunction)(const cTkClassPointer *, uint64_t, bool);
    void (*mDestroyFunction)(cTkClassPointer *);
};

class cTkMetaData
{
  public:
    template <typename T>
    struct Registrar
    {
      public:
        void ClassPointerCreateDefault(cTkClassPointer *, cTkLinearMemoryPool *);
        void ClassPointerRender(cTkClassPointer *);
        void ClassPointerFix(cTkClassPointer *, bool, uint64_t);
        void ClassPointerValidate(cTkClassPointer *);
        bool ClassPointerEquals(const cTkClassPointer *, const cTkClassPointer *);
        void ClassPointerCopy(cTkClassPointer *, const cTkClassPointer *);
        cTkClassPointer *ClassPointerCreate(cTkClassPointer *result);
        uint64_t ClassPointerGenerateHash(const cTkClassPointer *, uint64_t, bool);
        void ClassPointerDestroy(cTkClassPointer *);
    };
};

SKYSCRAPER_END