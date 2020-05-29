#include "CommandSave.h"

CommandSave::CommandSave(FileContext& fileCtx, BookStore& bookStore) :
    Command("save", 0, "save - saves the currently open file"),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

bool CommandSave::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandSave::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    if (bookStore->save(*fileCtx->getActiveFile()))
    {
        out << "File saved successfully" << std::endl;
        return;
    }

    out << "Failed to save file" << std::endl;
}
