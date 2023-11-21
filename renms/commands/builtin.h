#pragma once

#include <renms.h>

#include <commands/commands.h>
#include <commands/dispatcher.h>
#include <plugins/api.h>
#include <toolkit/utilities/TkString.h>

#include <numeric>

RENMS_BEGIN

void EchoCommandDispatch(std::vector<std::string> *laArgs);
void TestCommandDispatch(std::vector<std::string> *laArgs);
void AddBuiltinCommands();

RENMS_END