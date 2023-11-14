#pragma once

#include <skyscraper.h>

#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcInteractionComponent;

struct ActivationCost
{
    TkID<128> mSubstanceId;
    cTkVector<TkID<128>> maMultipleCostIds;
    int miCost;
    int miAmountPaid;
    bool mbRepeat;
    TkID<128> mRequiredTech;
};

class cGcInteraction
{
    VFT<11> *__vftable;
    cGcInteractionComponent *mpInteractionComponent;
};

SKYSCRAPER_END