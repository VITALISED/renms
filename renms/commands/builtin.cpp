#include <commands/builtin.h>

RENMS_BEGIN

void TestCommandDispatch(std::vector<std::string> *laArgs)
{
    spdlog::info("Hit!");

    for (std::string lsArg : *laArgs) { spdlog::info(lsArg); }

    free(laArgs);
}

void AddBuiltinCommands()
{
    Command *lTestCommand = new Command("test", &TestCommandDispatch);

    gCommandDispatcher.RegisterCommand(lTestCommand);
}

RENMS_END