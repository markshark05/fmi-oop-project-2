#include "CommandBooksAll.h"

CommandBooksAll::CommandBooksAll(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore) :
    Command("books all", 0, "books all - lists all books"),
    auth(&auth),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandBooksAll::authorize()
{
    return auth->getActiveUser();
}

bool CommandBooksAll::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandBooksAll::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::vector<Book*> books = bookStore->getAll();
    if (books.empty())
    {
        out << "No results found" << std::endl;
        return;
    }

    for (Book* const& b : books)
    {
        b->print_summary(out);
    }
}
