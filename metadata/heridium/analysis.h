#pragma once

#include "framework.h"
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaDataXML.h>

using namespace NMS;

void Heridium_Analysis_DoLookupIter();

//HACK: since I lack the braincells to figure out how hashes are generated we will instead retrieve them from the generated functions.
constexpr uintptr_t Heridium_Analysis_UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
{
    //
    uintptr_t cast_addr = (uintptr_t)ClassPointerWriteFunction + 0xBAD;

    //somehow resolve and jump to cast

    // return address of what's in the mov call in Cast()
    return cast_addr + 0xC;
}