#pragma once
#include "Command.h"
class CommandLogin :
    public Command
{
public:
    CommandLogin();
    bool authorize(bool userIsLoggedIn, bool userIsAdmin) override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
