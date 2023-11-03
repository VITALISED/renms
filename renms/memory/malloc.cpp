#include "malloc.h"

RENMS_BEGIN

extern cTkMemoryManager *gMemoryManager = (cTkMemoryManager *)RelToAbsolute(0x45835D0);

void HandleNoMalloc()
{
    spdlog::critical("gMemoryManager isn't constructed, expect lots of problems");
}

RENMS_END

#if !defined(RENMS_NO_TKMEMORY)

extern "C" void *_malloc_base(size_t n)
{
    if (!cTkMemoryManager::mgbConstructed) renms::HandleNoMalloc();

    renms::gMemoryManager->Malloc();
}

extern "C" void _free_base(void *p)
{
    if (!cTkMemoryManager::mgbConstructed) renms::HandleNoMalloc();

    renms::gMemoryManager->Free();
}

#endif //! defined(RENMS_NO_TKMEMORY)
