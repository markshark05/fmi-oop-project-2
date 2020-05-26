#include "CommandBooksInfo.h"

CommandBooksInfo::CommandBooksInfo(AuthorizeContext const& auth, BookStore& bookStore) :
    Command("books_info", 1, "show details for a book"),
    auth(auth),
    bookStore(bookStore)
{
}

bool CommandBooksInfo::authorize()
{
    return auth.getActiveUser();
}

void CommandBooksInfo::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    unsigned int id = std::stoi(args[0]);

    Book* b = bookStore.GetById(id);
    if (!b)
    {
        out << "No results found";
        return;
    }

    b->print_detailed(out);
}
