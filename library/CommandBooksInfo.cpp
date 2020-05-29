#include "CommandBooksInfo.h"

CommandBooksInfo::CommandBooksInfo(AuthorizeContext const& auth, const FileContext& fileCtx, BookStore& bookStore) :
    Command("books_info", 1, "boosk info <id> - shows info about a book"),
    auth(&auth),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandBooksInfo::authorize()
{
    return auth->getActiveUser();
}

bool CommandBooksInfo::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandBooksInfo::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    unsigned int id = std::stoi(args[0]);

    Book* b = bookStore->getById(id);
    if (!b)
    {
        out << "No results found" << std::endl;
        return;
    }

    b->print_detailed(out);
}
