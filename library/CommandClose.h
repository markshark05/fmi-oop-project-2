#pragma once
#include "Command.h"
#include "AuthorizeContext.h"

class CommandClose :
    public Command
{
public:
    CommandClose();
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
