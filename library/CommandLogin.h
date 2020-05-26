#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "UserStore.h"
class CommandLogin :
    public Command
{
public:
    CommandLogin(AuthorizeContext& auth, UserStore& userStore);
    bool authorize() override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
private:
    AuthorizeContext& auth;
    UserStore& userStore;
};
