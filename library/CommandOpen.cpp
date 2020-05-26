#include "CommandOpen.h"

CommandOpen::CommandOpen() :
    Command("open", 1, "opens <file>")
{
}

bool CommandOpen::authorize()
{
    return true;
}

void CommandOpen::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    out << "open executed" << std::endl;
}
