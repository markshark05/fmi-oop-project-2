#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "UserStore.h"

class CommandUsersAdd :
    public Command
{
private:
    const AuthorizeContext* auth;
    UserStore* userStore;
public:
    CommandUsersAdd(AuthorizeContext const& auth, UserStore& userStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
