#pragma once

#include <skyscraper.h>
#include <engine/source/engine/EgScene.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/attachments/tkattachmentdata.meta.h>

SKYSCRAPER_BEGIN

class cTkAttachmentPtr
{
    __int64 miUniqueID;
};

class cTkAttachment : public cEgNodeAttachment
{
    cTkAttachmentData *mpData;
    cTkComponent *mpComponents;
    const char *mpacName;
    cTkBitArray<unsigned __int64, 128> mHasComponentMask;
    __int64 miUniqueID;
};

SKYSCRAPER_END