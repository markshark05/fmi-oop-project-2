#pragma once
#include "Command.h"
#include "FileContext.h"
#include "BookStore.h"

class CommandSave :
    public Command
{
private:
    FileContext* fileCtx;
    BookStore* bookStore;
public:
    CommandSave(FileContext& fileCtx, BookStore& bookStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
