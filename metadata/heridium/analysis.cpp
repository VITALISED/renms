#include "analysis.h"

void Heridium_Analysis_DoLookupIter()
{
    cTkVector<cTkMetaDataXMLFunctionLookup>* xmlWriteLookup = NULL;

    for(cTkMetaDataXMLFunctionLookup item : *xmlWriteLookup)
    {
        //handle crap
    }
}

uintptr_t Heridium_Analysis_UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
{
    //
    uintptr_t cast_addr = (uintptr_t)ClassPointerWriteFunction + 0xBAD;

    //somehow resolve and jump to cast

    // return address of what's in the mov call in Cast()
    return cast_addr + 0xC;
}