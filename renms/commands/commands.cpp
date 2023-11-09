#include <commands/commands.h>

RENMS_BEGIN

Command::Command(const cTkFixedString<1023, char> *lMessageText, CommandDispatchCallback_t lpDispatchFn)
    : mpDispatchFn(lpDispatchFn)
{
    bool lbIsFirst = true;
    std::stringstream lssCommand(lMessageText->macBuffer);
    std::string lsBuff;
    this->mpacArguments = new std::vector<std::string>();

    while (std::getline(lssCommand, lsBuff, ' '))
    {
        if (lbIsFirst)
        {
            std::string lsTrimmed = lsBuff.erase(0, 1);
            this->mpacName        = lsTrimmed;

            lbIsFirst = false;
            continue;
        }

        this->mpacArguments->push_back(lsBuff);
    }
}

RENMS_END