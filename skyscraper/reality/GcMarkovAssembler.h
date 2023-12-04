#pragma once

#include <skyscraper.h>

#include <reality/gcnamegeneratortypes.meta.h>

SKYSCRAPER_BEGIN

class cGcMarkovAssembler
{
  public:
    struct Request
    {
        eMarkovSelector meSelector;
        int miMinLength;
        int miMaxLength;
    };
};

SKYSCRAPER_END