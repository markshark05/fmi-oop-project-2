#include "CommandBooksAll.h"

CommandBooksAll::CommandBooksAll(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore) :
    Command("books_all", 0, "lists all books"),
    auth(&auth),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandBooksAll::authorize()
{
    return auth->getActiveUser();
}

void CommandBooksAll::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    if (!fileCtx->getActiveFile())
    {
        out << "Command requires an open file." << std::endl;
        return;
    }
    
    const std::vector<Book*> books = bookStore->GetAll();
    if (books.empty())
    {
        out << "No results found";
        return;
    }

    for (Book* const& b : books)
    {
        b->print_summary(out);
    }
}
