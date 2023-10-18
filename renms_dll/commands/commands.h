#pragma once

#include "../renms.h"

RENMS_BEGIN

class Command
{
    const char *mpacName;
    const char *mpacDescription;
    std::vector<const char*> *mpacArguments;
};

RENMS_END