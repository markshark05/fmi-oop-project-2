#pragma once
#include <vector>
#include "AuthorizeContext.h"
#include "BookStore.h"
#include "UserStore.h"
#include "Command.h"
#include "IStoppableLoop.h"
#include "ICommandsLoop.h"

class CommandLoop :
    public IStoppableLoop,
    public ICommandsLoop
{
private:
    std::istream* in;
    std::ostream* out;
    std::vector<Command*>* commands;
    bool running;
public:
    CommandLoop(std::istream& in, std::ostream& out, std::vector<Command*>& commands);
    void start();
    void stop();
    const std::vector<Command*>& getCommands() const;
private:
    void loop();
    std::vector<std::string> parseArgs(std::istringstream& linestream);
};
