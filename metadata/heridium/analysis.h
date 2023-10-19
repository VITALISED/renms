#pragma once

#include "heridium.h"
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/data/TkMetaDataXML.h>

using namespace nms;

HERIDIUM_BEGIN

void DoLookupIter();
//HACK: since I lack the braincells to figure out how hashes are generated we will instead retrieve them from the generated functions.
uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction);

HERIDIUM_END