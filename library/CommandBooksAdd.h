#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "FileContext.h"
#include "BookStore.h"

/**
 * @brief books add - interactively adds a book
 * 
 */
class CommandBooksAdd :
    public Command
{
private:
    const AuthorizeContext* auth;
    const FileContext* fileCtx;
    BookStore* bookStore;
public:
    /**
     * @brief Construct a new CommandBooksAdd
     * 
     * @param auth the AuthorizeContext used to authorize the user
     * @param fileCtx the file Context used to issue commands to the BookStore
     * @param bookStore the BookStore for CRUD operation
     */
    CommandBooksAdd(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore);
    bool authorize() override;
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
