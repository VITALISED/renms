#include "analysis.h"
#include <memory/memory.h>

HERIDIUM_ANALYSIS_BEGIN

void DoLookupIter()
{
    cTkVector<cTkMetaDataXMLFunctionLookup>* xmlWriteLookup = (cTkVector<cTkMetaDataXMLFunctionLookup>*)OFFSET(0x53AAA48);

    for(cTkMetaDataXMLFunctionLookup item : *xmlWriteLookup)
    {
        unsigned __int64 luClassHash = *(unsigned __int64*)UnpackClassPointerWriteFunc(item.mWriteFunction);
        
        // work from here
    }
}

uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
{
    //Get the call to Cast() from the Write function
    uintptr_t castCallInstruction = (uintptr_t)ClassPointerWriteFunction + 0x11;
    LPVOID castPtr = renms::RelToAbsolute(castCallInstruction);

    // return address of what's in the mov call in Cast()
    uintptr_t hashAddr =  (uintptr_t)castPtr + 0xC;

    return hashAddr;
}

HERIDIUM_ANALYSIS_END