#include <commands/dispatcher.h>

extern renms::CommandDispatcher gCommandDispatcher = renms::CommandDispatcher();

uint64_t cGcTextChatInput__ParseTextForCommands__TRAMPOLINE = NULL;

void cGcTextChatInput__ParseTextForCommands__DETOUR(uint64_t thiscall, const cTkFixedString<1023, char> *lMessageText)
{
    if (!renms::CommandDispatcher::StartsWithPrefix(lMessageText))
        return PLH::FnCast(
            cGcTextChatInput__ParseTextForCommands__TRAMPOLINE,
            cGcTextChatInput__ParseTextForCommands__DETOUR)(thiscall, lMessageText);

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

    return PLH::FnCast(
        cGcTextChatInput__ParseTextForCommands__TRAMPOLINE,
        cGcTextChatInput__ParseTextForCommands__DETOUR)(thiscall, lMessageText);
}

PLH::x64Detour cGcTextChatInput__ParseTextForCommands__HOOK(
    reinterpret_cast<uint64_t>(renms::RelToAbsolute(0x804E70)),
    reinterpret_cast<uint64_t>(cGcTextChatInput__ParseTextForCommands__DETOUR),
    &cGcTextChatInput__ParseTextForCommands__TRAMPOLINE);

RENMS_BEGIN

void CreateTextChatHooks()
{
    cGcTextChatInput__ParseTextForCommands__HOOK.hook();
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
    spdlog::info("Found command: {}", lMessageText->macBuffer);

    return true;
}

bool CommandDispatcher::IsStockCommand(const cTkFixedString<1023, char> *lMessageText)
{
    if (strstr(lMessageText->macBuffer, "/g")) return true;
    if (strstr(lMessageText->macBuffer, "/group")) return true;
    if (strstr(lMessageText->macBuffer, "/l")) return true;
    if (strstr(lMessageText->macBuffer, "/local")) return true;
    if (strstr(lMessageText->macBuffer, "/whisper")) return true;
    if (strstr(lMessageText->macBuffer, "/join")) return true;
    if (strstr(lMessageText->macBuffer, "/leave")) return true;
    if (strstr(lMessageText->macBuffer, "/invite")) return true;
    if (strstr(lMessageText->macBuffer, "/kick")) return true;

    return false;
}

RENMS_END