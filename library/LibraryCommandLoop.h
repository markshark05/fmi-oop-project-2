#pragma once
#include <vector>
#include "AuthorizeContext.h"
#include "BookStore.h"
#include "UserStore.h"
#include "Command.h"
#include "IStoppable.h"
#include "ICommands.h"

class LibraryCommandLoop :
    public IStoppable,
    public ICommands
{
public:
    LibraryCommandLoop(std::istream& in, std::ostream& out, std::vector<Command*>& commands);
    void Start();
    void Stop();
    const std::vector<Command*>& getCommands() const;
private:
    std::istream& in;
    std::ostream& out;
    std::vector<Command*>& commands;

    bool running;
    void loop();
    std::vector<std::string> parseArgs(std::istringstream& linestream);
};
