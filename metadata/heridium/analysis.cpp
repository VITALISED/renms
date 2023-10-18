#include "analysis.h"
#include <memory/memory.h>

HERIDIUM_BEGIN

void DoLookupIter()
{
    typedef cTkMetaDataFunctionLookup*(*__cTkMetaData__GetLookup__)(const unsigned __int64 luiNameHash);

    cTkVector<cTkMetaDataXMLFunctionLookup>* xmlWriteLookup = (cTkVector<cTkMetaDataXMLFunctionLookup>*)OFFSET(0x32618A8);

    for(cTkMetaDataXMLFunctionLookup item : *xmlWriteLookup)
    {
        unsigned __int64 luClassHash = *(unsigned __int64*)UnpackClassPointerWriteFunc(item.mWriteFunction);
        
        // work from here
        __cTkMetaData__GetLookup__ getLookupPtr = (__cTkMetaData__GetLookup__)OFFSET(0x2487860);

        cTkMetaDataFunctionLookup* classMetadata = getLookupPtr(luClassHash);
    }
}

uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
{
    //Get the call to Cast() from the Write function
    uintptr_t castCallInstruction = (uintptr_t)ClassPointerWriteFunction + 0x11;
    LPVOID castPtr = renms::RelToAbsolute(castCallInstruction);

    // return address of what's in the mov call in Cast()
    uintptr_t hashAddr = (uintptr_t)castPtr + 0xC;

    return hashAddr;
}

HERIDIUM_END