#pragma once

#include <skyscraper.h>

#include <toolkit/scene/geometry/tkvertexelement.meta.h>

SKYSCRAPER_BEGIN

class cTkVertexLayoutRT
{
    int32_t miElementCount;
    int32_t miStride;
    uint64_t miHash;
    cTkVertexElement maElementsBuffer[12];
};

SKYSCRAPER_END