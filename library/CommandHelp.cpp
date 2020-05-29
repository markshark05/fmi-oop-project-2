#include "CommandHelp.h"

CommandHelp::CommandHelp(const ICommandsLoop& loop) :
    Command("help", 0, "prints this information"),
    _loop(loop)
{
}

bool CommandHelp::authorize()
{
    return true;
}

void CommandHelp::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::vector<Command*>& commands = _loop.getCommands();
    for (Command* const& c : commands)
    {
        out << c->getName() << '\t';
        out << c->getHelpMessage() << std::endl;
    }
}
