#include <map>
#include "CommandBooksFind.h"
#include "StringHelpers.h"

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

bool CommandBooksFind::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandBooksFind::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& option = args[0];
    const std::string& option_string = StringHelpers::join(args, ' ', 1);

    std::map<std::string, BookStore::filterFunc> filter_f
    {
        { "title", [option_string](Book* const& b)
            {
                return StringHelpers::icompare(b->getTitle(), option_string) == 0;
            }
        },
        { "author", [option_string](Book* const& b)
            {
                return StringHelpers::icompare(b->getAuthor(), option_string) == 0;
            }
        },
        { "tag", [option_string](Book* const& b)
            {
                for (const std::string& t : b->getTags())
                {
                    if (StringHelpers::icompare(t, option_string) == 0) 
                        return true;
                }
                return false;
            }
        }
    };

    if (!filter_f.count(option))
    {
        out << "Invalid filter property." << std::endl;
        return;
    }

    std::vector<Book*> books = bookStore->getFiltered(filter_f[option]);
    if (books.empty())
    {
        out << "No results found." << std::endl;
    }

    for (Book* const& b : books)
    {
        b->print_detailed(out) << std::endl;
    }
}
