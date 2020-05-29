#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "FileContext.h"
#include "BookStore.h"

class CommandBooksRemove :
    public Command
{
private:
    const AuthorizeContext* auth;
    const FileContext* fileCtx;
    BookStore* bookStore;
public:
    CommandBooksRemove(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore);
    bool authorize() override;
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
