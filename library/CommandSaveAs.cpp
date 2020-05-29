#include "CommandSaveAs.h"

CommandSaveAs::CommandSaveAs(FileContext& fileCtx, BookStore& bookStore) :
    Command("saveas", 1, "saves the currently open file in <file>"),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandSaveAs::authorize()
{
    return true;
}

void CommandSaveAs::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& filename = args[0];

    if (!fileCtx->getActiveFile())
    {
        out << "No open file to save" << std::endl;
        return;
    }

    if (bookStore->save(filename))
    {
        fileCtx->setActiveFile(filename);
        out << "File saved successfully. Open file switeched to" << filename << std::endl;
        return;
    }

    out << "Failed to save file" << std::endl;
}
