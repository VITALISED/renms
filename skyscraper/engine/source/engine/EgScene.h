#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkHandle.h>

SKYSCRAPER_BEGIN

struct EgRenderQueueHandle
{
    int miQueueId;
    int miFrameId;
};

class cEgNodeAttachment
{
    TkHandle mNode;
    
    virtual ~cEgNodeAttachment();
    virtual void OnUpdate();
};

SKYSCRAPER_END