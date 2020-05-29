#include <sstream>
#include "LibraryCommandLoop.h"

LibraryCommandLoop::LibraryCommandLoop(std::istream& in, std::ostream& out, std::vector<Command*>& commands) :
    in(in),
    out(out),
    running(false),
    commands(commands)
{
}

void LibraryCommandLoop::Start()
{
    if (!running)
    {
        running = true;
        loop();
    }
}

void LibraryCommandLoop::Stop()
{
    running = false;
}

const std::vector<Command*>& LibraryCommandLoop::getCommands() const
{
    return commands;
}

void LibraryCommandLoop::loop()
{
    while (running)
    {
        out << "> ";
        std::string line;
        std::getline(in, line);

        std::istringstream linestream{ line };
        std::string commandStr;
        if (linestream >> commandStr)
        {
            Command* command = nullptr;
            for (Command* const& c : commands)
            {
                if (c->getName() == commandStr)
                {
                    command = c;
                }
            }

            if (command)
            {
                std::vector<std::string> args = parseArgs(linestream);
                if (args.size() < command->getMinArgsCount())
                {
                    out << "Expected " << command->getMinArgsCount() << " argument(s) but got " << args.size() << "." << std::endl;
                }
                else if (!command->authorize())
                {
                    out << "You are not authorized to run this command." << std::endl;
                }
                else
                {
                    command->execute(in, out, args);
                }
            }
            else
            {
                out << "Unknown command \"" << commandStr << "\"." << std::endl;
            }
        }
    }
}

std::vector<std::string> LibraryCommandLoop::parseArgs(std::istringstream& linestream)
{
    std::vector<std::string> args;
    std::string token;
    while(linestream >> token)
    {
        args.push_back(token);
    }

    return args;
}
