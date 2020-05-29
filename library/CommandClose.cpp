#include "CommandClose.h"

CommandClose::CommandClose(FileContext& fileCtx) :
    Command("close", 0, "closes currently opened file"),
    fileCtx(&fileCtx)
{
}

bool CommandClose::authorize()
{
    return true;
}

void CommandClose::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    if (!fileCtx->getActiveFile())
    {
        out << "No open file to close" << std::endl;
        return;
    }

    fileCtx->clearActiveFile();
    out << "File closed successfully" << std::endl;
}
