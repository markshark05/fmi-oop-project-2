#include <map>
#include "CommandBooksFind.h"

CommandBooksFind::CommandBooksFind(const AuthorizeContext& auth, const FileContext& fileCtx, BookStore& bookStore) :
    Command("books_find", 2, "books find <option> <option_string> - lists books matching criteria"),
    auth(&auth),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandBooksFind::authorize()
{
    return auth->getActiveUser();
}

void CommandBooksFind::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    if (!fileCtx->getActiveFile())
    {
        out << "Command requires an open file." << std::endl;
        return;
    }

    const std::string& option = args[0];
    const std::string& option_string = args[1];

    std::map<std::string, BookStore::filterFunc> filter_f
    {
        { "title", [option_string](const Book& b)
            {
                return b.getTitle() == option_string;
            }
        },
        { "author", [option_string](const Book& b)
            {
                return b.getAuthor() == option_string;
            }
        },
        { "tag", [option_string](const Book& b)
            {
                std::vector<std::string> tags = b.getTags();
                return std::find(tags.begin(), tags.end(), option_string) != tags.end();
            }
        }
    };

    if (!filter_f.count(option))
    {
        out << "Invalid filter property." << std::endl;
        return;
    }

    std::vector<Book*> books = bookStore->GetFiltered(filter_f[option]);
    if (books.empty())
    {
        out << "No results found." << std::endl;
    }

    for (Book* const& b : books)
    {
        b->print_summary(out);
    }
}
