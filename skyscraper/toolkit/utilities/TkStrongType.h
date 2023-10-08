#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

namespace TkStrongTypeIDs
{
    struct TkResHandleID;
}

template <typename T, class StrongTypeID>
class TkStrongType
{
public:
    T mValue;
};

SKYSCRAPER_END