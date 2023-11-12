#include <commands/commands.h>

RENMS_BEGIN

Command::Command(std::string lpacName, CommandDispatchCallback_t lpDispatchFn)
    : mpacName(lpacName), mpDispatchFn(lpDispatchFn)
{
}

void Command::Dispatch(std::vector<std::string> *laArgs)
{
    this->mpDispatchFn(laArgs);
}

RENMS_END