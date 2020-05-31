#pragma once
#include "Command.h"
#include "FileContext.h"
#include "BookStore.h"

/**
 * @brief save - saves the currently open file
 * 
 */
class CommandSave :
    public Command
{
private:
    FileContext* fileCtx;
    BookStore* bookStore;
public:
    /**
     * @brief Construct a new CommandSave object
     * 
     * @param fileCtx the book file context
     * @param bookStore the bookSote to save to
     */
    CommandSave(FileContext& fileCtx, BookStore& bookStore);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
