#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkMetaMessageSink.h>

SKYSCRAPER_BEGIN

class cGcOwnerConcept : cTkMetaMessageSink<cTkAttachmentPtr>
{ };

SKYSCRAPER_END