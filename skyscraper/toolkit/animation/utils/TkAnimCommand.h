/**
 * @file TkAnimCommand.h
 * @author VITALISED & Contributors
 * @since 2024-01-19
 * 
 * Copyright (C) 2024  VITALISED & Contributors
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

SKYSCRAPER_BEGIN

class cTkAnimCommand
{
  public:
    enum eCommandType
    {
        ECommandType_Invalid,
        ECommandType_WriteNilPose,
        ECommandType_WriteBindPose,
        ECommandType_EvalFrame,
        ECommandType_MirrorPose,
        ECommandType_Blend,
        ECommandType_Subtract,
        ECommandType_Add,
        ECommandType_AddReversed,
        ECommandType_Multiply,
        ECommandType_NlerpMultiply,
        ECommandType_NlerpAdd,
        ECommandType_NlerpComplete,
        ECommandType_NumCommands,
    };

    cTkAnimCommand::eCommandType mCmd;
    float mfParam;
    uint16_t muAnim;
};

SKYSCRAPER_END