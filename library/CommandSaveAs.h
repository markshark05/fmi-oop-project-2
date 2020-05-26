#pragma once
#include "Command.h"

class CommandSaveAs :
    public Command
{
public:
    CommandSaveAs();
    bool authorize() override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
