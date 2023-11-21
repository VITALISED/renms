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