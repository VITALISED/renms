#pragma once

#include <renms.h>

RENMS_BEGIN

template <typename T>
void **GetVTable(T *lpObj)
{
    return *reinterpret_cast<void ***>(lpObj);
}

RENMS_END