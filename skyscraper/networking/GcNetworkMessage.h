#pragma once

#include <skyscraper.h>
#include <networking/GcNetworkConstants.h>
#include <networking/GcNetworkSerializer.h>
#include <toolkit/graphics/2d/texture/TkTextureBase.h>

SKYSCRAPER_BEGIN

typedef cTkTextureBase::eTexFormat eGcNetworkMessageType;

class cGcNetworkMessage
{
    eGcNetworkMessageType meMessageType;
    cGcNetworkConstants::TransmissionChannels meChannel;
    cGcNetworkSerializer mSerializer;

    virtual ~cGcNetworkMessage();
    virtual bool SerializeOrDeserialize();
    virtual bool IsReadyToProcess();
    virtual bool CustomSerialization();
};


SKYSCRAPER_END