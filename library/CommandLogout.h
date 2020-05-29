#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
class CommandLogout :
    public Command
{
private:
    AuthorizeContext* auth;
public:
    CommandLogout(AuthorizeContext& auth);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
