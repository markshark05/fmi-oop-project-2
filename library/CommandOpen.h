#pragma once
#include "Command.h"
#include "FileContext.h"
#include "BookStore.h"

/**
 * @brief open \<file\> - loads \<file\> creating new one if does not exist
 * 
 */
class CommandOpen :
    public Command
{
private:
    FileContext* fileCtx;
    BookStore* bookStore;
public:
    /**
     * @brief Construct a new CommandOpen object
     * 
     * @param fileCtx the FileContext of the books file
     * @param bookStore the BookStore to reload
     */
    CommandOpen(FileContext& fileCtx, BookStore& bookStore);
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
