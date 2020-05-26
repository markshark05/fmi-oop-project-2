#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "BookStore.h"

class CommandBooksSort :
    public Command
{
public:
    CommandBooksSort(AuthorizeContext const& auth, BookStore& bookStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
private:
    AuthorizeContext const& auth;
    BookStore& bookStore;
};
