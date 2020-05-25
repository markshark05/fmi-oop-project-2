#pragma once
#include <vector>
#include "Command.h"
#include "IStoppable.h"
#include "ICommands.h"
#include "LibraryCore.h"

class LibraryCommandLoop :
    public IStoppable,
    public ICommands
{
public:
    LibraryCommandLoop(std::istream& in, std::ostream& out, LibraryCore& core);
    void Start();
    void Stop();
    const std::vector<Command*>& getCommands() const;
private:
    std::istream& in;
    std::ostream& out;
    LibraryCore& core;

    bool running;
    std::vector<Command*> commands;
    void loop();
    std::vector<std::string> parseArgs(std::istringstream& linestream, unsigned int max);
};
