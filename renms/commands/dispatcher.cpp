#include <commands/dispatcher.h>

uint64_t cGcTextChatInput__ParseTextForCommands__TRAMPOLINE = NULL;

void cGcTextChatInput__ParseTextForCommands__DETOUR(uint64_t thiscall, const cTkFixedString<1023, char> *lMessageText)
{
    return PLH::FnCast(
        cGcTextChatInput__ParseTextForCommands__TRAMPOLINE,
        cGcTextChatInput__ParseTextForCommands__DETOUR)(thiscall, lMessageText);
}

PLH::x64Detour cGcTextChatInput__ParseTextForCommands__HOOK(
    reinterpret_cast<uint64_t>(renms::RelToAbsolute(0x804E70)),
    reinterpret_cast<uint64_t>(cGcTextChatInput__ParseTextForCommands__DETOUR),
    &cGcTextChatInput__ParseTextForCommands__TRAMPOLINE);

RENMS_BEGIN

// TODO: implement this garbage
bool IsStockCommand(const cTkFixedString<1023, char> *lMessageText)
{
    if (strstr(lMessageText->macBuffer, "/g")) return true;

    return false;
}

RENMS_END