#pragma once

#include <memory/memory.h>
#include <renms.h>
#include <toolkit/utilities/TkString.h>

RENMS_BEGIN

bool IsStockCommand(const cTkFixedString<1023, char> *lMessageText);

RENMS_END