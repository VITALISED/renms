/**
 * @file textchatsink.h
 * @author VITALISED & Contributors
 * @since 2024-01-02
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

/**
 * @file textchatsink.h
 * @author VITALISED & Contributors
 * @since 2023-12-15
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

#include <application/GcApplication.h>
#include <spdlog/sinks/base_sink.h>

template <typename Mutex>
class textchatsink : public spdlog::sinks::base_sink<Mutex>
{
  protected:
    void sink_it_(const spdlog::details::log_msg &msg) override
    {
        spdlog::memory_buf_t formatted;
        spdlog::sinks::base_sink<Mutex>::formatter_->format(msg, formatted);
        nms::cGcApplication *gApplication = nms::cGcApplication::GetInstance();

        if (!gApplication->mpData) return;

        if (!gApplication->mpData->mSimulation.mbSimulationInLoadPhase &&
            gApplication->mpData->mSimulation.mbSimulationPrepared)
        {
            std::string buff = fmt::to_string(formatted);
            if (!buff.empty() && buff[buff.length() - 1] == '\n') { buff.erase(buff.length() - 1); }
            nms::cTkFixedString<1121, char> lMessage   = nms::cTkFixedString<1121, char>(buff.c_str());
            nms::cTkFixedString<128, char> lPlayerName = nms::cTkFixedString<128, char>("Explorer");
            nms::cTkColour lColour                     = nms::cTkColour();
            gApplication->mpData->mNetworkManager.mTextChatManager.PostLocalMessage(
                &lMessage, &lPlayerName, &lColour, 0, 5.0f);
        }
    }

    void flush_() override { ; }
};

using textchatsink_mt = textchatsink<std::mutex>;