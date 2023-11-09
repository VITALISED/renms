#pragma once

#include <commands/commands.h>
#include <commands/dispatcher.h>
#include <renms.h>

RENMS_BEGIN

void TestCommandDispatch(std::vector<std::string> *laArgs);
void AddBuiltinCommands();

RENMS_END