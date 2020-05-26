#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "BookStore.h"

class CommandBooksAdd :
    public Command
{
public:
    CommandBooksAdd(AuthorizeContext const& auth, BookStore& bookStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
private:
    static std::string promptLine(std::istream& in, std::ostream& out, const std::string& prompt);
    AuthorizeContext const& auth;
    BookStore& bookStore;
};
