/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <graphics/hud/GcPunctuationDelay.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <reality/gcalienmood.meta.h>
#include <simulation/ecosystem/npcs/gcnpcproptype.meta.h>
#include <toolkit/ngui/tknguitextstyle.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiStyledString
{
  public:
    struct SpecialStyle
    {
        bool mbPlaying;
        float mfPos;
        float mfLastPos;
        float mfTime;
        cTkNGuiTextStyle mStyle;
    };

    struct LayoutInstruction
    {
        enum eLayoutInstruction
        {
            ELayoutInstruction_NoOp,
            ELayoutInstruction_DoText,
            ELayoutInstruction_DoImage,
            ELayoutInstruction_DoSpacing,
            ELayoutInstruction_PushStyle,
            ELayoutInstruction_PopStyle,
            ELayoutInstruction_MoveCursor,
            ELayoutInstruction_AudioEvent,
            ELayoutInstruction_Delay,
            ELayoutInstruction_Mood,
            ELayoutInstruction_Prop,
        };

        struct StringSegment
        {
            int miStart;
            int miEnd;
        };

        union LayoutCustomData {
            unsigned int mAudioID;
            eMood meMood;
            eNPCProp meProp;
        };

        struct CursorLocation
        {
            float mfX;
            float mfY;
        };

        union LayoutInstructionArgs {
            cGcNGuiStyledString::LayoutInstruction::StringSegment mStringSegment;
            cGcNGuiStyledString::LayoutInstruction::CursorLocation mCursorLocation;
        };

        struct LayoutInstructionArgument
        {
            TkID<128> mStyleName;
            cGcNGuiStyledString::LayoutInstruction::LayoutInstructionArgs mArgs;
            cGcNGuiStyledString::LayoutInstruction::LayoutCustomData mCustomData;
            bool mbNotified;
        };

        float mfRowHeightAdjust;
        float mfElementHeight;
        cGcNGuiStyledString::LayoutInstruction::eLayoutInstruction meInstruction;
        cGcNGuiStyledString::LayoutInstruction::LayoutInstructionArgument mArgument;
        float mfDisplayLength;
    };

    struct StyledStringLayout
    {
        cTkNGuiTextStyle mBaseTextStyle;
        cTkUnorderedMap<
            TkID<128>, cGcNGuiStyledString::SpecialStyle, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128>>>
            mTextStyles;
        cTkVector<cGcNGuiStyledString::LayoutInstruction> maStyleInstructions;
        cTkVector<TkID<128>> mStyleStack;
        float mfScrollOffset;
        float mfCurrentOffset;
        float mfStartTime;
        float mfForcedOffset;
        float mfTotalDisplayLength;
        cTkVector2 mvContainerStartSize;
        cTkVector2 mvContainerFinalSize;
        float mfRowWidth;
        float mfHeight;
        float mfCurrentRowHeight;
        float mfMaxWidth;
        int miLastCursorInstructionIndex;
        int miStyleCount;
        int miTotalTextLength;
        int miLastTextInstruction;
        eHorizontal meHorizontalAlignment;
        eVertical meVerticalAlignment;
        ePunctuationDelays mePunctuationDelay;
        eNGuiInputType meLastInput;
        bool mbIsParagraph;
        bool mbForcedAllowScroll;
        bool mbDebugTrace;
    };
};

SKYSCRAPER_END