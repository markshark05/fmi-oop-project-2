#include "CommandBooksRemove.h"

CommandBooksRemove::CommandBooksRemove(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore) :
    Command("books_remove", 1, "books remove <id> - removes an existing book"),
    auth(&auth),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandBooksRemove::authorize()
{
    return auth->getActiveUser() && auth->getActiveUser()->getIsAdmin();
}

bool CommandBooksRemove::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandBooksRemove::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    unsigned id = std::stoi(args[0]);

    if (bookStore->RemoveById(id))
    {
        out << "Book successfully removed" << std::endl;
        return;
    }

    out << "Failed to remove book" << std::endl; 
}
