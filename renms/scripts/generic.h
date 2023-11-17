#pragma once

#include <renms.h>

RENMS_BEGIN

class ScriptGeneric
{
  public:
    size_t miSize;
    std::string msTypeId;
    void *mpVal;

    ScriptGeneric(size_t liSize, std::string lsTypeId, void *lpVal) : miSize(liSize), msTypeId(lsTypeId), mpVal(lpVal)
    {
    }
};

template <typename T>
T script_cast(ScriptGeneric castee)
{
    if (castee.miSize == sizeof(T) && typeid(T) == castee.msTypeId) { return *reinterpret_cast<T>(castee.mpVal); }

#if defined(_DEBUG)
    spdlog::error("Can't cast to {} (from {})", typeid(T), castee.msTypeId);
#endif

    return NULL;
}

RENMS_END