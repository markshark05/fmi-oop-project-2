#pragma once
#include "Command.h"

class CommandOpen :
    public Command
{
public:
    CommandOpen();
    bool authorize() override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
