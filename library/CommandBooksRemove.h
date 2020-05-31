#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "FileContext.h"
#include "BookStore.h"

/**
 * @brief books remove \<id\> - removes an existing book
 * 
 */
class CommandBooksRemove :
    public Command
{
private:
    const AuthorizeContext* auth;
    const FileContext* fileCtx;
    BookStore* bookStore;
public:
    /**
     * @brief Construct a new CommandBooksRemove
     * 
     * @param auth the AuthorizeContext used to authorize the user
     * @param fileCtx the file Context used to issue commands to the BookStore
     * @param bookStore the BookStore for CRUD operation
     */
    CommandBooksRemove(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore);
    bool authorize() override;
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
