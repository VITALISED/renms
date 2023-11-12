#pragma once

#include <skyscraper.h>

#include <toolkit/system/memory/pools/TkMemoryPool.h>

SKYSCRAPER_BEGIN

namespace GcDiscoverySearchConstraints
{

class ConstraintBase : AutoPooled<19>
{
    VFT<2> *__vftable;
};

} // namespace GcDiscoverySearchConstraints

SKYSCRAPER_END