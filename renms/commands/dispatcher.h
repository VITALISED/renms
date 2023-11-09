#pragma once

#include <commands/commands.h>
#include <memory/memory.h>
#include <renms.h>
#include <toolkit/utilities/TkString.h>

RENMS_BEGIN

bool IsStockCommand(const cTkFixedString<1023, char> *lMessageText);
bool StartsWithPrefix(const cTkFixedString<1023, char> *lMessageText);

RENMS_END