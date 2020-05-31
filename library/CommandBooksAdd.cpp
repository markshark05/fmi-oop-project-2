#include <sstream>
#include "CommandBooksAdd.h"

CommandBooksAdd::CommandBooksAdd(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore) :
    Command("books_add", 0, "books add - interactively adds a book"),
    auth(&auth),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandBooksAdd::authorize()
{
    return auth->getActiveUser() && auth->getActiveUser()->getIsAdmin();
}

bool CommandBooksAdd::fileRequirement()
{
    return fileCtx->getActiveFile();
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
    if (yearstr >> year)
    {
        book.setYear(year);
    }

    std::istringstream tagsstr{ promptLine(in, out, "Tags") };
    std::string tag;
    std::vector<std::string> tags;
    while (tagsstr >> tag)
    {
        tags.push_back(tag);
    }
    book.setTags(tags);

    std::string rating_range = std::to_string(int(Book::RATING_MIN)) + "-" + std::to_string(int(Book::RATING_MAX));
    std::istringstream ratingstr{ promptLine(in, out, "Rating(" + rating_range + ")") };
    float rating;
    if (ratingstr >> rating)
    {
        book.setRating(rating);
    }

    bookStore->add(book);
}
