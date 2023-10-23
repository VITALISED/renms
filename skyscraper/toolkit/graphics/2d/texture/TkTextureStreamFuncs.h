#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkStrongType.h>
#include <toolkit/graphics/2d/texture/TkGnmxContext.h>
#include <toolkit/graphics/2d/texture/TkMipReportBuffer.h>

SKYSCRAPER_BEGIN

class cTkTexture;

struct cTkTextureStreamFuncs
{
    bool (*mStreamFunc)(TkStrongType<int,TkStrongTypeIDs::TkResHandleID>, void *, int, int, int, int);
    bool (*mStreamDeleteFunc)(void *);
    void (*mAbortBakeFunc)(void *);
    void (*mEvictFunc)(cTkTexture *, void *, int);
    bool (*mBeginProbeFunc)(TkStrongType<int,TkStrongTypeIDs::TkResHandleID>, void *, int, int);
    void (*mCompleteProbeFunc)(cTkGnmxContext *, cTkTexture *, void *, int, int);
    __int64 (*mGatherProbeFunc)(TkStrongType<int,TkStrongTypeIDs::TkResHandleID>, void *, TkMipReportBuffer *, int *, int, int, bool *, bool *, bool *);
    bool mbIsVirtualTexture;
};

SKYSCRAPER_END