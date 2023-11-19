#include <commands/dispatcher.h>

extern renms::CommandDispatcher gCommandDispatcher = renms::CommandDispatcher();

RENMS_HOOK(
    cGcTextChatInput__ParseTextForCommands, renms::RelToAbsolute(0x804E70), void,
    (uint64_t thiscall, const cTkFixedString<1023, char> *lMessageText) {
        if (!renms::CommandDispatcher::StartsWithPrefix(lMessageText))
            return RENMS_CAST(cGcTextChatInput__ParseTextForCommands, thiscall, lMessageText);

        std::string lsNoPrefixCommand = lMessageText->macBuffer;
        lsNoPrefixCommand.erase(0, 1);

        size_t lFirstSpace               = lsNoPrefixCommand.find_first_of(' ');
        std::string lsCommandName        = lsNoPrefixCommand;
        std::vector<std::string> *laArgs = new std::vector<std::string>();

        if (lFirstSpace != std::string::npos)
        {
            lsCommandName = lsNoPrefixCommand.substr(0, lFirstSpace);
            std::stringstream lssCommandStream(lsNoPrefixCommand.substr(lFirstSpace, std::string::npos));
            std::string lsBuffer;

            while (std::getline(lssCommandStream, lsBuffer, ' '))
            {
                if (!lsBuffer.empty()) { laArgs->push_back(lsBuffer); }
            }
        }

        if (gCommandDispatcher.TryParseCommand(lsCommandName, laArgs)) return;

        return RENMS_CAST(cGcTextChatInput__ParseTextForCommands, thiscall, lMessageText);
    });

RENMS_BEGIN

void CreateTextChatHooks()
{
    RENMS_DISPATCH_HOOK(cGcTextChatInput__ParseTextForCommands);
}

CommandDispatcher::CommandDispatcher()
{
    this->maCommands = std::vector<Command *>();
}

void CommandDispatcher::RegisterCommand(Command *lCommand)
{
    this->maCommands.push_back(lCommand);
}

bool CommandDispatcher::TryParseCommand(std::string lsCommandName, std::vector<std::string> *laArgs)
{
    for (Command *lCommand : this->maCommands)
    {
        if (lCommand->mpacName == lsCommandName)
        {
            lCommand->Dispatch(laArgs);
            return true;
        }
    }

    return false;
}

bool CommandDispatcher::StartsWithPrefix(const cTkFixedString<1023, char> *lMessageText)
{
    if (std::string(lMessageText->macBuffer).rfind("/", 0)) { return false; }

    return true;
}

RENMS_END