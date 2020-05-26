#include "CommandBooksAdd.h"

CommandBooksAdd::CommandBooksAdd(AuthorizeContext const& auth, BookStore& bookStore) :
    Command("books_add", 0, "books_add <interactive>"),
    auth(auth),
    bookStore(bookStore)
{
}

bool CommandBooksAdd::authorize()
{
    return auth.getActiveUser() && auth.getActiveUser()->getIsAdmin();
}

void CommandBooksAdd::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    std::string str;
    Book book;
    
    out << "Title: ";
    std::getline(in, str);
    book.setTitle(str);

    out << "Author: ";
    std::getline(in, str);
    book.setAuthor(str);

    out << "Genre: ";
    std::getline(in, str);
    book.setGenre(str);

    out << "Description: ";
    std::getline(in, str);
    book.setGenre(str);

    out << "Year: ";
    std::getline(in, str);
    book.setGenre(str);

    bookStore.Add(book);
}
