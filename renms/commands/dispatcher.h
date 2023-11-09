#pragma once

#include <commands/commands.h>
#include <memory/memory.h>
#include <renms.h>
#include <toolkit/utilities/TkString.h>

using namespace nms;

RENMS_BEGIN

void CreateTextChatHooks();

class CommandDispatcher
{
  public:
    std::vector<Command *> maCommands;

    CommandDispatcher();
    void RegisterCommand(Command *lCommand);
    bool TryParseCommand(std::string lsCommandName, std::vector<std::string> *laArgs);

    static bool IsStockCommand(const cTkFixedString<1023, char> *lMessageText);
    static bool StartsWithPrefix(const cTkFixedString<1023, char> *lMessageText);
};

RENMS_END

extern renms::CommandDispatcher gCommandDispatcher;