#pragma once
#include "Command.h"
#include "ICommandsLoop.h"

class CommandHelp :
    public Command
{
public:
    CommandHelp(const ICommandsLoop& commandLoop);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
private:
    const ICommandsLoop& _loop;
};
