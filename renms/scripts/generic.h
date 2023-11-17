#pragma once

#include <renms.h>

RENMS_BEGIN

class ScriptGeneric
{
  public:
    size_t miSize;
    std::string msTypeId;
    void *mpVal;

    ScriptGeneric(size_t liSize, std::string lsTypeId) : miSize(liSize), msTypeId(lsTypeId) {}
};

template <typename T>
T script_cast(ScriptGeneric castee)
{
    if (castee.miSize == sizeof(T) && typeid(T) == castee.msTypeId) { return *reinterpret_cast<T>(castee.mpVal); }
}

RENMS_END