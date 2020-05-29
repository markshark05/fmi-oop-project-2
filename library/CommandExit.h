#pragma once
#include "Command.h"
#include "IStoppableLoop.h"

class CommandExit :
    public Command
{
public:
    CommandExit(IStoppableLoop& loop);
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
private:
    IStoppableLoop& _loop;
};
