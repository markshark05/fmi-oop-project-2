#include <iostream>
#include "LibraryCommandLoop.h"
#include "AuthorizeContext.h"
#include "BookStore.h"
#include "UserStore.h"

int main()
{
    BookStore bookStore;
    UserStore userStore;

    AuthorizeContext authctx;
    LibraryCommandLoop cmdloop{ std::cin, std::cout, authctx, bookStore, userStore };
    
    cmdloop.Start();
}
