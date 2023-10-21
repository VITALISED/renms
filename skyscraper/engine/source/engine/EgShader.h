#pragma once

#include <skyscraper.h>
#include <cstring>
#include <algorithm>
#include <iostream>

SKYSCRAPER_BEGIN

class cEgShaderResource
{
public:
    bool ParseFXSection(const char* lpcData);

    struct CombinationCompilationTask
    {
        cEgShaderResource *mpResource;
        int miContextIndex;
        unsigned __int64 mxComboMask;
    };
};

SKYSCRAPER_END