#pragma once

#include <renms.h>

#include <commands/commands.h>
#include <memory/hook.h>
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

    static bool StartsWithPrefix(const cTkFixedString<1023, char> *lMessageText);
};

RENMS_END

extern renms::CommandDispatcher gCommandDispatcher;