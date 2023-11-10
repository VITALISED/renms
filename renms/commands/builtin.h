#pragma once

#include <commands/commands.h>
#include <commands/dispatcher.h>
#include <numeric>
#include <plugins/api.h>
#include <renms.h>

RENMS_BEGIN

void EchoCommandDispatch(std::vector<std::string> *laArgs); 
void TestCommandDispatch(std::vector<std::string> *laArgs);
void AddBuiltinCommands();

RENMS_END