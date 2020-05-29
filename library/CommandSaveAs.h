#pragma once
#include "Command.h"
#include "FileContext.h"
#include "BookStore.h"

class CommandSaveAs :
    public Command
{
private:
    FileContext* fileCtx;
    BookStore* bookStore;
public:
    CommandSaveAs(FileContext& fileCtx, BookStore& bookStore);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
