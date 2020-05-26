#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "UserStore.h"

class CommandUsersRemove :
    public Command
{
public:
    CommandUsersRemove(AuthorizeContext const& auth, UserStore& userStore);
    bool authorize() override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
private:
    AuthorizeContext const& auth;
    UserStore& userStore;
};
