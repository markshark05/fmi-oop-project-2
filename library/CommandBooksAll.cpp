#include "CommandBooksAll.h"

CommandBooksAll::CommandBooksAll(const AuthorizeContext& auth, BookStore& bookStore) :
    Command("books_all", 0, "lists all books"),
    auth(auth),
    bookStore(bookStore)
{
}

bool CommandBooksAll::authorize()
{
    return auth.getActiveUser();
}

void CommandBooksAll::execute(std::ostream& out, const std::vector<std::string>& args)
{
    const std::vector<Book*> books = bookStore.GetAll();

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
