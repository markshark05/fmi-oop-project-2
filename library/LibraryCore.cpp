#include <map>
#include "LibraryCore.h"

LibraryCore::LibraryCore(std::ostream& out, UserStore& userStore, BookStore& bookStore) :
    out(out),
    activeUser(nullptr),
    userStore(userStore),
    bookStore(bookStore)
{
}

void LibraryCore::login(std::string username, std::string password)
{
    if (activeUser)
    {
        out << "You are already logged in." << std::endl;
        return;
    }

    User* user = userStore.getByUsername(username);
    if (user && user->getPassword() == password)
    {
        activeUser = user;
        out << "Welcome, " << username << "!" << std::endl;
        return;
    }

    out << "Invalid login details" << std::endl;
}

void LibraryCore::logout()
{
    if (!activeUser)
    {
        out << "You are not logged int" << std::endl;
    }

    activeUser = nullptr;
    out << "Succesfully logged out" << std::endl;
}

void LibraryCore::books_all()
{
    std::vector<Book*> books = bookStore.Query(nullptr, nullptr);

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

void LibraryCore::books_info(unsigned int id)
{
    Book* b = bookStore.GetById(id);
    if (!b)
    {
        out << "No results found";
        return;
    }

    b->print_detailed(out);
}

void LibraryCore::books_find(const std::string& option, const std::string& option_string)
{
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

    std::vector<Book*> books = bookStore.Query(filter_f[option], nullptr);
    if (books.empty())
    {
        out << "No results found." << std::endl;
    }

    for (Book* const& b : books)
    {
        b->print_summary(out);
    }
}

void LibraryCore::books_sort(const std::string& option, const std::string& asc_desc)
{
    std::map<std::string, BookStore::sortFunc> sort_f
    {
        { "title", [asc_desc](const Book& a, const Book& b)
            {
                return asc_desc == "desc"
                    ? b.getTitle().compare(a.getTitle())
                    : a.getTitle().compare(b.getTitle());
            }
        },
        { "author",[asc_desc](const Book& a, const Book& b)
            {
               return asc_desc == "desc"
                    ? b.getAuthor().compare(a.getAuthor())
                    : a.getAuthor().compare(b.getAuthor());
            }
        },
        { "year", [asc_desc](const Book& a, const Book& b)
            {
                return asc_desc == "desc"
                    ? b.getYear() - a.getYear()
                    : a.getYear() - b.getYear();
            }
        },
        { "rating",[asc_desc](const Book& a, const Book& b)
            {
                return asc_desc == "desc"
                    ? b.getRating() - a.getRating()
                    : a.getRating() - b.getRating();
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

    std::vector<Book*> books = bookStore.Query(nullptr, sort_f[option]);
    if (books.empty())
    {
        out << "No results found." << std::endl;
    }

    for (Book* const& b : books)
    {
        b->print_summary(out);
    }
}
