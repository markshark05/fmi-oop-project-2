#pragma once
#include "Command.h"

class CommandClose :
    public Command
{
public:
    CommandClose();
    bool authorize(bool userIsLoggedIn, bool userIsAdmin) override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
