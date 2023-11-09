#include <commands/dispatcher.h>

uint64_t cGcTextChatInput__ParseTextForCommands__TRAMPOLINE = NULL;

void cGcTextChatInput__ParseTextForCommands__DETOUR(uint64_t thiscall, const cTkFixedString<1023, char> *lMessageText)
{
    if (renms::IsStockCommand(lMessageText) || !renms::StartsWithPrefix(lMessageText))
        return PLH::FnCast(
            cGcTextChatInput__ParseTextForCommands__TRAMPOLINE,
            cGcTextChatInput__ParseTextForCommands__DETOUR)(thiscall, lMessageText);
}

PLH::x64Detour cGcTextChatInput__ParseTextForCommands__HOOK(
    reinterpret_cast<uint64_t>(renms::RelToAbsolute(0x804E70)),
    reinterpret_cast<uint64_t>(cGcTextChatInput__ParseTextForCommands__DETOUR),
    &cGcTextChatInput__ParseTextForCommands__TRAMPOLINE);

RENMS_BEGIN

bool StartsWithPrefix(const cTkFixedString<1023, char> *lMessageText)
{
    if (std::string(lMessageText->macBuffer).rfind("/", 0)) { return true; }

    return false;
}

bool IsStockCommand(const cTkFixedString<1023, char> *lMessageText)
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