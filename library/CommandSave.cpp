#include "CommandSave.h"

CommandSave::CommandSave()
    : Command("save", 0, "saves the currently open file")
{
}

bool CommandSave::authorize()
{
    return true;
}

void CommandSave::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    out << "save executed" << std::endl;
}
