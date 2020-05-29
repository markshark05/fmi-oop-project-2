#include <iostream>

#include "BookStore.h"
#include "UserStore.h"

#include "AuthorizeContext.h"
#include "FileContext.h"

#include "CLILoop.h"

#include "CommandBooksAdd.h"
#include "CommandBooksAll.h"
#include "CommandBooksFind.h"
#include "CommandBooksInfo.h"
#include "CommandBooksRemove.h"
#include "CommandBooksSort.h"
#include "CommandClose.h"
#include "CommandExit.h"
#include "CommandHelp.h"
#include "CommandLogin.h"
#include "CommandLogout.h"
#include "CommandOpen.h"
#include "CommandSave.h"
#include "CommandSaveAs.h"
#include "CommandUsersAdd.h"
#include "CommandUsersRemove.h"

int main()
{
    CSVReader csvReader;
    CSVWriter csvWriter;

    BookCSVReader bookReader{ csvReader };
    BookCSVWriter bookWriter{ csvWriter };
    BookStore bookStore{ bookReader, bookWriter };

    UserStore userStore;

    FileContext bookFileCtx;
    FileContext userFileCtx;
    AuthorizeContext authCtx;

    std::vector<Command*> commands
    {
        new CommandOpen{ bookFileCtx, bookStore },
        new CommandClose{ bookFileCtx },
        new CommandSave{ bookFileCtx, bookStore },
        new CommandSaveAs{ bookFileCtx, bookStore },

        new CommandLogin{ authCtx, userStore },
        new CommandLogout{ authCtx },

        new CommandBooksAdd{ authCtx, bookFileCtx, bookStore },
        new CommandBooksAll{ authCtx, bookFileCtx, bookStore },
        new CommandBooksFind{ authCtx, bookFileCtx, bookStore },
        new CommandBooksInfo{ authCtx, bookFileCtx, bookStore },
        new CommandBooksRemove{ authCtx, bookFileCtx, bookStore },
        new CommandBooksSort{ authCtx, bookFileCtx, bookStore },

        new CommandUsersAdd{ authCtx, userStore},
        new CommandUsersRemove{ authCtx, userStore},
    };

    CLILoop cmdloop{ std::cin, std::cout, commands };

    commands.push_back(new CommandHelp{ cmdloop });
    commands.push_back(new CommandExit{ cmdloop });

    cmdloop.start();

    return 0;
}
