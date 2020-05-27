#pragma once
#include "Command.h"
#include "ICommands.h"

class CommandHelp :
    public Command
{
public:
    CommandHelp(const ICommands& commandLoop);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
private:
    const ICommands& _loop;
};
