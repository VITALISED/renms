#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

class cGcURL
{
  public:
    struct Scheme
    {
        typedef int Enum;
    };

    cGcURL::Scheme::Enum meScheme;
    cTkFixedString<32, char> mSchemeText;
    cTkFixedString<128, char> mHostname;
    int miPort;
    cTkStackVector<cTkFixedString<160, char>, 4> mPath;
    cTkStackVector<cTkFixedString<160, char>, 4> mQuery;
};

SKYSCRAPER_END