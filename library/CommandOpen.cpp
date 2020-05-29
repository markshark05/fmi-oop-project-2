#include "CommandOpen.h"

CommandOpen::CommandOpen(FileContext& fileCtx, BookStore& bookStore) :
    Command("open", 1, "open <file> - loads <file> creating new one if does not exist"),
    fileCtx(&fileCtx),
    bookStore(&bookStore)
{
}

void CommandOpen::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& filename = args[0];

    if (fileCtx->getActiveFile())
    {
        out << "File already open, please close it first." << std::endl;
        return;
    }

    if (bookStore->load(filename))
    {
        fileCtx->setActiveFile(filename);
        out << "File loaded succesfully." << std::endl;
        return;
    }

    out << "Failed to load file" << std::endl;
}
