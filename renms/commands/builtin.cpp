/**
 * @file builtin.cpp
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

#include <commands/builtin.h>

RENMS_BEGIN

void TeleportCommandDispatch(std::vector<std::string> *laArgs)
{

    float lfX = std::stof(laArgs->at(0));
    float lfY = std::stof(laArgs->at(1));
    float lfZ = std::stof(laArgs->at(2));

    nms::cTkVector3 *lPos = new nms::cTkVector3(lfX, lfY, lfZ);
    nms::cTkVector3 lDir  = cGcApplication::GetInstance()->mpData->mSimulation.mPlayer.mFacingDir;
    nms::cTkVector3 lVel  = cGcApplication::GetInstance()->mpData->mSimulation.mPlayer.mLastVelocities.back();
    cTkVector3 lPosition  = cGcApplication::GetInstance()->mpData->mSimulation.mPlayer.mPosition;

    std::string lPositionStr = fmt::format("Teleporting to: {} {} {}", lPos->mfX, lPos->mfY, lPos->mfZ);
    spdlog::info(lPositionStr);

    cGcApplication::GetInstance()->mpData->mSimulation.mPlayer.SetToPosition(lPos, &lDir, &lVel);

    delete lPos;

    free(laArgs);
}

void GetPositionDispatch(std::vector<std::string> *laArgs)
{
    cTkVector3 lPosition     = cGcApplication::GetInstance()->mpData->mSimulation.mPlayer.mPosition;
    std::string lPositionStr = fmt::format("{} {} {}", lPosition.mfX, lPosition.mfY, lPosition.mfZ);

    spdlog::info(lPositionStr);

    free(laArgs);
}

void TestCommandDispatch(std::vector<std::string> *laArgs)
{
    spdlog::info("Woah, it's a test.");
    spdlog::info("{:X}", (uintptr_t)cGcApplication::GetInstance());
    spdlog::info("{:X}", (uintptr_t)GetModuleHandleA(NULL));

    for (std::string lsArg : *laArgs) {}

    free(laArgs);
}

void EchoCommandDispatch(std::vector<std::string> *laArgs)
{
    std::string lsAccumulated;

    lsAccumulated = std::accumulate(
        laArgs->begin(), laArgs->end(), lsAccumulated,
        [](const std::string &s1, const std::string &s2) -> std::string { return s1.empty() ? s2 : s1 + " " + s2; });

    nms::cTkFixedString<1121, char> lpacMessageBody = nms::cTkFixedString<1121, char>(lsAccumulated.c_str());

    spdlog::info(lsAccumulated);
    // renms_sdk::SendTextMessage(&lpacMessageBody);

    free(laArgs);
}

uint64_t fmix64_parametrised(
    uint64_t value, uint64_t shift1, uint64_t const1, uint64_t shift2, uint64_t const2, uint64_t shift3)
{
    if (shift1 < 64) value ^= (value >> shift1);
    value *= const1;
    value ^= (value >> shift2);
    value *= const2;
    value ^= (value >> shift3);

    return value;
}

auto fmix64_david_stafford_mix02(uint64_t value)
{
    return fmix64_parametrised(value, 33, 0x64DD81482CBD31D7, 31, 0xE36AA5C613612997, 31);
}

void GetUACommandDispatch(std::vector<std::string> *laArgs)
{
    cTkSeed UA                       = cTkSeed(0x16109FEEE26DC);
    nms::cGcSolarSystemQuery *lQuery = new nms::cGcSolarSystemQuery();
    lQuery->Run(UA.GetValue(), nms::cGcSolarSystemQuery::SystemAndPlanets, false);
    spdlog::info("UA: {:X}", UA.GetValue());
    spdlog::info("System seed: {:X}", lQuery->mSystemSeed.mu64SeedValue);
    spdlog::info("Planets:");
    for (PlanetGenerationQuery planetQuery : lQuery->maPlanetAttributes)
    {
        if (planetQuery.mName.macBuffer) { spdlog::info("Name: {}", planetQuery.mName.macBuffer); }
    }

    nms::cGcSolarSystemGenerator lGenerator = nms::cGcSolarSystemGenerator();
    lGenerator.Construct();
    // lGenerator.Generate();

    free(laArgs);
}

void AddBuiltinCommands()
{
    Command *lTestCommand   = new Command("test", &TestCommandDispatch);
    Command *lEchoCommand   = new Command("echo", &EchoCommandDispatch);
    Command *lTPCommand     = new Command("tp", &TeleportCommandDispatch);
    Command *lGetPosCommand = new Command("getpos", &GetPositionDispatch);
    Command *lGetUACommand  = new Command("uaquery", &GetUACommandDispatch);

    gCommandDispatcher.RegisterCommand(lTestCommand);
    gCommandDispatcher.RegisterCommand(lEchoCommand);
    gCommandDispatcher.RegisterCommand(lTPCommand);
    gCommandDispatcher.RegisterCommand(lGetPosCommand);
    gCommandDispatcher.RegisterCommand(lGetUACommand);
}

RENMS_END