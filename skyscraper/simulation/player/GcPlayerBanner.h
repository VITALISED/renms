#pragma once

#include <skyscraper.h>
#include <toolkit/data/TkMetaData.h>
#include <metadata/reality/gcinventoryclass.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerBanner
{
    unsigned __int8 miIconIndex;
    unsigned __int8 miMainColourIndex;
    unsigned __int8 miBackgroundColourIndex;
    eInventoryClass meShipClass;
    TkID<128> mTitleId;
};

SKYSCRAPER_END