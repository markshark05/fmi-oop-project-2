#pragma once
#include "Command.h"
class CommandLogout :
    public Command
{
public:
    CommandLogout();
    bool authorize(bool userIsLoggedIn, bool userIsAdmin) override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
