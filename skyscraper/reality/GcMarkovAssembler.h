#pragma once

#include <skyscraper.h>
#include <metadata/reality/gcnamegeneratortypes.meta.h>

SKYSCRAPER_BEGIN

class cGcMarkovAssembler
{
    struct Request
    {
        eMarkovSelector meSelector;
        int miMinLength;
        int miMaxLength;
    };
};

SKYSCRAPER_END