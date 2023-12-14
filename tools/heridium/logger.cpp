/**
 * @file logger.cpp
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

#include "logger.h"

HERIDIUM_BEGIN

void CreateLogger()
{
    // fix ANSI colors
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);

        dwMode |= 0x0004;
        SetConsoleMode(hOut, dwMode);
    }

    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink =
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    console_sink->set_pattern(" [%n] %v");

    spdlog::set_default_logger(std::make_shared<spdlog::logger>(
        "\033[38;2;158;237;255mHeridium\033[0m", spdlog::sinks_init_list({console_sink})));
}

HERIDIUM_END