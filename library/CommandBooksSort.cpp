#include <map>
#include "CommandBooksSort.h"

CommandBooksSort::CommandBooksSort(AuthorizeContext const& auth, BookStore& bookStore) :
    Command("books_sort", 1, "books sort <option> [asc | desc]"),
    auth(auth),
    bookStore(bookStore)
{
}

bool CommandBooksSort::authorize()
{
    return auth.getActiveUser();
}

void CommandBooksSort::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& option = args[0];
    const std::string& asc_desc = args[1];

    std::map<std::string, BookStore::sortFunc> sort_f
    {
        { "title", [asc_desc](Book* const& a, Book* const& b)
            {
                return asc_desc == "desc"
                    ? b->getTitle().compare(a->getTitle())
                    : a->getTitle().compare(b->getTitle());
            }
        },
        { "author",[asc_desc](Book* const& a, Book* const& b)
            {
               return asc_desc == "desc"
                    ? b->getAuthor().compare(a->getAuthor())
                    : a->getAuthor().compare(b->getAuthor());
            }
        },
        { "year", [asc_desc](Book* const& a, Book* const& b)
            {
                return asc_desc == "desc"
                    ? b->getYear() - a->getYear()
                    : a->getYear() - b->getYear();
            }
        },
        { "rating",[asc_desc](Book* const& a, Book* const& b)
            {
                return asc_desc == "desc"
                    ? b->getRating() - a->getRating()
                    : a->getRating() - b->getRating();
            }
        }
    };


    if (!sort_f.count(option))
    {
        out << "Invalid sort property." << std::endl;
        return;
    }

    if (asc_desc != "asc" && asc_desc != "desc")
    {
        out << "Invalid sort modifier";
        return;
    }

    std::vector<Book*> books = bookStore.GetSorted(sort_f[option]);
    if (books.empty())
    {
        out << "No results found." << std::endl;
    }

    for (Book* const& b : books)
    {
        b->print_summary(out);
    }
}
