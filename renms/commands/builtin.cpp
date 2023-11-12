#include <commands/builtin.h>

RENMS_BEGIN

void TestCommandDispatch(std::vector<std::string> *laArgs)
{
    spdlog::info("Woah, it's a test.");

    for (std::string lsArg : *laArgs) { spdlog::info(lsArg); }

    free(laArgs);
}

void EchoCommandDispatch(std::vector<std::string> *laArgs)
{
    std::string lsAccumulated;

    lsAccumulated = std::accumulate(
        laArgs->begin(), laArgs->end(), lsAccumulated,
        [](const std::string &s1, const std::string &s2) -> std::string { return s1.empty() ? s2 : s1 + " " + s2; });

    nms::cTkFixedString<1023, char> *lpacMessageBody = new nms::cTkFixedString<1023, char>();

    strcpy_s(lpacMessageBody->macBuffer, 1023, lsAccumulated.c_str());

    // BroadcastMessage(const_cast<const nms::cTkFixedString<1023, char> *>(lpacMessageBody), false);

    spdlog::info(lsAccumulated);

    free(laArgs);
}

void AddBuiltinCommands()
{
    Command *lTestCommand = new Command("test", &TestCommandDispatch);
    Command *lEchoCommand = new Command("echo", &EchoCommandDispatch);

    gCommandDispatcher.RegisterCommand(lTestCommand);
    gCommandDispatcher.RegisterCommand(lEchoCommand);
}

RENMS_END