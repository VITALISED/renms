#include <skyscraper.h>
#include <toolkit/system/memory/TkMemoryManager.h>

SKYSCRAPER_BEGIN

void *cTkMemoryManager::Malloc(int liSize, const char* lpacFile, int liLine, const char* lpacFunction, int liAlign, int liPool) 
{
    if(liAlign && !(liAlign & (liAlign - 1)))
    {
        //handle non power of two alignment
    }

    //FIXME: liPool is obviously an enum but we dont know what it is
    if((liPool == -2) && cTkMemoryManager::mgbConstructed)
    {
        //i hate this with a fucking passion
        return _aligned_malloc(liSize, liAlign);
    }

    int liBackingPoolIndex;
    cTkMemoryPool* lpBackingPool;

    return nullptr; //todo: finish
}

SKYSCRAPER_END
