#include <sstream>
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
    Book book;
    book.setTitle(promptLine(in, out, "Title"));
    book.setAuthor(promptLine(in, out, "Author"));
    book.setGenre(promptLine(in, out, "Genre"));
    book.setDescription(promptLine(in, out, "Description"));

    std::istringstream yearstr{ promptLine(in, out, "Year") };
    unsigned year;
    yearstr >> year;
    book.setYear(year);

    std::istringstream tagsstr{ promptLine(in, out, "Tags") };
    std::string tag;
    std::vector<std::string> tags;
    while (tagsstr >> tag)
    {
        tags.push_back(tag);
    }
    book.setTags(tags);

    std::istringstream ratingstr{ promptLine(in, out, "Rating") };
    float rating;
    ratingstr >> rating;
    book.setRating(rating);

    bookStore.Add(book);
}

std::string CommandBooksAdd::promptLine(std::istream& in, std::ostream& out, const std::string& prompt)
{
    std::string str;
    out << prompt << ": ";
    std::getline(in, str);
    return str;
}
