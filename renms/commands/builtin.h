/**
 * @file builtin.h
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

#include <renms.h>

#include <commands/commands.h>
#include <commands/dispatcher.h>
#include <sdk/core.h>
#include <sdk/textchat.h>
#include <simulation/solarsystem/GcSolarSystemQuery.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/utilities/hash/TkSpookyV2.h>
#include <toolkit/utilities/string/TkString.h>

#include <cstdint>
#include <numeric>

#include <simulation/spaceship/ai/gcaispaceshippreloadcachedata.meta.h>

RENMS_BEGIN

void TeleportCommandDispatch(std::vector<std::string> *laArgs);
void EchoCommandDispatch(std::vector<std::string> *laArgs);
void TestCommandDispatch(std::vector<std::string> *laArgs);
void AddBuiltinCommands();

RENMS_END