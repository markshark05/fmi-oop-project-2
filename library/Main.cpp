#include <iostream>

#include "BookStore.h"
#include "UserStore.h"
#include "AuthorizeContext.h"
#include "LibraryCommandLoop.h"
#include "Command.h"
#include "CommandBooksAdd.h"
#include "CommandBooksAll.h"
#include "CommandBooksFind.h"
#include "CommandBooksInfo.h"
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
    BookStore bookStore;
    UserStore userStore;
    AuthorizeContext authCtx;

    std::vector<Command*> commands
    {
        new CommandOpen,
        new CommandClose,
        new CommandSave,
        new CommandSaveAs,

        new CommandLogin{ authCtx, userStore },
        new CommandLogout{ authCtx },

        new CommandBooksAdd{ authCtx, bookStore },
        new CommandBooksAll{ authCtx, bookStore },
        new CommandBooksFind{ authCtx, bookStore },
        new CommandBooksInfo{ authCtx, bookStore },
        new CommandBooksSort{ authCtx, bookStore },

        new CommandUsersAdd{ authCtx, userStore},
        new CommandUsersRemove{ authCtx, userStore},
    };
    
    LibraryCommandLoop cmdloop{ std::cin, std::cout, commands };

    commands.push_back(new CommandHelp{ cmdloop });
    commands.push_back(new CommandExit{ cmdloop });

    cmdloop.Start();
    
    return 0;
}
