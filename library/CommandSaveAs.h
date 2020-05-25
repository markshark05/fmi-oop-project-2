#pragma once
#include "Command.h"

class CommandSaveAs :
    public Command
{
public:
    CommandSaveAs();
    bool authorize(bool userIsLoggedIn, bool userIsAdmin) override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
