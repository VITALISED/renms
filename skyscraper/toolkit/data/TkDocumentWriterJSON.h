/**
 * @file TkDocumentWriterJSON.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/string/TkStringAssembler.h>
#include <toolkit/voxel/TkHalfVectors.h>

SKYSCRAPER_BEGIN

class ITkDocumentWriter
{
  public:
    virtual ~ITkDocumentWriter();
    virtual TkID<128> *GetWriterFormat(TkID<128> *result);
    virtual void Clear();
    virtual void PushContext(const char *);
    virtual void PopContext();
    virtual void OpenArray(const char *);
    virtual void OpenObject(const char *);
    virtual void Close();
    virtual void AddValue(unsigned int);
    virtual void AddValue(int);
    virtual void AddValue(float);
    virtual void AddValue(const cTkSeed *);
    virtual void AddValue(const TkID<256> *);
    virtual void AddValue(const TkID<128> *);
    virtual void AddValue(const uint64_t);
    virtual void AddValue(const int64_t);
    virtual void AddValue(const bool);
    virtual void AddValue(const wchar_t *);
    virtual void AddValue(const char *);
    virtual void AddValue(const long double);
    virtual void AddValue(const cTkHalfVector4 *);
    virtual void AddValue(const cTkVector2 *);
    virtual void AddValue(const cTkVector3 *);
    virtual void AddValue(const cTkVector4 *);
    virtual void AddValue(const cTkPhysRelVec3 *);
    virtual void AddKey(const char *);
};

class cTkDocumentWriterJSON : ITkDocumentWriter
{
  public:
    cTkStringAssembler *mAssembler;
    int miTabLevel;
    bool mbKeyBeingBuilt;
    bool mbBraceType[20];
    bool mbPrettyOutput;
    bool mbAutoSanitizeFP;
    bool mbHashKeys;
};

SKYSCRAPER_END