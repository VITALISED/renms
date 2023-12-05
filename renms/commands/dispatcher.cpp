/**
 * @file dispatcher.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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