/**
 * @file log.h
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

#pragma once

#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#define MAX_LOG_FILESIZE (1024 * 1024 * 10) // 10mb

inline std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> ConsoleSink()
{
    return std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
};
inline std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> FileSink()
{
    return std::make_shared<spdlog::sinks::rotating_file_sink_mt>("RENMS/Logs/renms.log", MAX_LOG_FILESIZE, 3);
};

#ifdef _DEBUG
inline void SetConsoleSinkParams(std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink)
{
    console_sink->set_level(spdlog::level::debug);
};
#else  //!_DEBUG
inline void SetConsoleSinkParams(std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink)
{
    console_sink->set_level(spdlog::level::info);
};
#endif //_DEBUG

constexpr const char *GetScriptLoggerName()
{
    return "\033[33mSCRIPT\033[0m";
}

inline void CreateLogger(const char *lpacLoggerName)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);

        dwMode |= 0x0004;
        SetConsoleMode(hOut, dwMode);
    }

    std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> file_sink   = FileSink();
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink = ConsoleSink();

    console_sink->set_pattern(" [%n] [%L] %v");

    SetConsoleSinkParams(console_sink);
    file_sink->set_level(spdlog::level::trace);
    spdlog::set_default_logger(
        std::make_shared<spdlog::logger>(lpacLoggerName, spdlog::sinks_init_list({console_sink, file_sink})));

    auto lScriptLogger =
        std::make_shared<spdlog::logger>(GetScriptLoggerName(), spdlog::sinks_init_list({console_sink, file_sink}));
    spdlog::register_logger(lScriptLogger);
};