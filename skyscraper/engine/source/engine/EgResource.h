/**
 * @file EgResource.h
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

#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cEgResource : public cTkResource
{
  public:
    virtual ~cEgResource();
    virtual bool IsLoaded();
    virtual void SetDescriptor(const cTkResourceDescriptor *);
    virtual int GetDataSize();
    virtual bool OnResourceLoaded();
    virtual unsigned int GetDeletionFrameDelay();
    virtual cTkResource *Clone();
    virtual void CloneInternal(const cTkResource *);
    virtual void Release();
    virtual bool Equals(const char *, const cTkResourceDescriptor *, int);
    virtual void InitDefault();
    virtual bool Load(const char *, int);
    virtual int GetElementCount(int);
    virtual int GetElementParamInt(int, int, int);
    virtual void SetElementParamInt(int, int, int, int);
    virtual float GetElementParamFloat(int, int, int, int);
    virtual void SetElementParamFloat(int, int, int, int, float);
    virtual const char *GetElementParamStr(int, int, int);
    virtual void SetElementParamStr(int, int, int, const char *);
    virtual void *MapResStream(int, int, TkHandle, bool, bool, const char *);
    virtual void *MapResStream(int, int, int, bool, bool, const char *);
    virtual void UnmapStream(TkHandle, bool);
    virtual void UnmapStream(int);
    virtual bool IsSceneGraphRes();
    virtual void GatherMaterials(cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> *);
    virtual cTkAABB *GetBoundingBox(cTkAABB *result);
};

SKYSCRAPER_END