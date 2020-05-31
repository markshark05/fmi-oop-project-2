#pragma once
#include "Command.h"
#include "FileContext.h"
#include "BookStore.h"

/**
 * @brief saveas \<file\> - saves the currently open file in \<file\> and switches to it
 * 
 */
class CommandSaveAs :
    public Command
{
private:
    FileContext* fileCtx;
    BookStore* bookStore;
public:
    /**
     * @brief Construct a new CommandSaveAs object
     * 
     * @param fileCtx the book file context
     * @param bookStore the bookSote to save to
     */
    CommandSaveAs(FileContext& fileCtx, BookStore& bookStore);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
