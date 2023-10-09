#pragma once

#include "framework.h"
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaDataXML.h>

using namespace NMS;

void Heridium_Analysis_DoLookupIter();
//HACK: since I lack the braincells to figure out how hashes are generated we will instead retrieve them from the generated functions.
uintptr_t Heridium_Analysis_UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction);