#pragma once
#include "Command.h"
#include "AuthorizeContext.h";
#include "BookStore.h"

class CommandBooksAll :
    public Command
{
public:
    CommandBooksAll(AuthorizeContext const& auth, BookStore& bookStore);
    bool authorize() override;
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
private:
    AuthorizeContext const& auth;
    BookStore& bookStore;
};
