/**
 * @file GcTextChatManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/TkNGuiTextEdit.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/UnorderedMapHashes.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/messages/gcstatusmessagedefinitions.meta.h>

SKYSCRAPER_BEGIN

enum eTextChatCommands
{
    None,
    SwitchToGroupChannel,
    SwitchToLocalChannel,
    JoinPlayer,
    InvitePlayer,
    KickPlayer,
    LeaveFireteam,
    Whisper,
    NumCommands,
};

struct PendingMessage
{
    enum ePendingMessageState
    {
        EPendingMessageState_Free,
        EPendingMessageState_StartProfanityCheck,
        EPendingMessageState_WaitingForProfanityCheck,
        EPendingMessageState_ProfanityCheckComplete,
        EPendingMessageState_ProfanityCheckSkipped,
    };

    PendingMessage::ePendingMessageState mePendingMessageState;
    cTkFixedString<1023, char> msUncensoredMessageBody;
    cTkFixedString<1023, char> msMessageBody;
    cTkVector<cTkUserIdBase<cTkFixedString<64, char>>> maRecipients;
    cTkUserIdBase<cTkFixedString<64, char>> mSender;
    float mfDisplayDuration;
    bool mbShowNamePrefix;
    bool mbIncludeLocalPlayer;
    uint8_t meMessageType[1];
    cTkColour mBackgroundColour;
    int mMessageId;
};

struct DisplayMessage
{
    float mfDisplayStartTime;
    float mfDisplayDuration;
    cTkFixedString<1121, char> msMessage;
    cTkColour mBackgroundColour;
    int mMessageId;
};

struct TextChatMessageBuffer
{
    int miNextMessageInsertIndex;
    int miMessages;
    std::array<DisplayMessage, 10> maMessageBuffer;
};

class cGcTextChatInput
{
  public:
    struct SCommandLookup
    {
        const char *mpcCommandName;
        const char *mpcShortCommandName;
    };

    cTkNGuiTextEditState mEditText;
    cTkFixedString<1023, char> msText;
    cTkFixedString<1023, char> msInputTextDisplayString;
    bool mbTextInputActive;
    bool mbWaitingForNoKeyboardInput;
    bool mbButtonReleased;
    eTextChatCommands meCurrentCommand;
    eTextChatCommands mePendingCommand;
    const cGcTextChatInput::SCommandLookup *mpLookupTable;
};

class cGcTextChatManager
{
  public:
    std::array<PendingMessage, 10> maPendingMessages;
    TextChatMessageBuffer maMessageBuffer;
    uint8_t meLastMessageType[1];
    int mNextMessageId;
    cGcStatusMessageDefinitions *mpStatusMessageTable;
    robin_hood::detail::Table<
        false, 80, cTkFixedString<128, char>, int, UnorderedMapHashes::Hash<cTkFixedString<128, char>>,
        std::equal_to<cTkFixedString<128, char>>>
        mStringCountHash;
};

SKYSCRAPER_END