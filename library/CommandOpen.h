#pragma once
#include "Command.h"

class CommandOpen :
    public Command
{
public:
    CommandOpen();
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
