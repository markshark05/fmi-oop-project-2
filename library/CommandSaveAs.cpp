#include "CommandSaveAs.h"

CommandSaveAs::CommandSaveAs() :
    Command("saveas", 1, "saves the currently open file in <file>")
{
}

bool CommandSaveAs::authorize()
{
    return true;
}

void CommandSaveAs::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    out << "saveas executed" << std::endl;
}
