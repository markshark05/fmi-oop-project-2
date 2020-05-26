#pragma once
#include <vector>
#include "AuthorizeContext.h"
#include "BookStore.h"
#include "UserStore.h"
#include "Command.h"
#include "IStoppable.h"
#include "ICommands.h"

class LibraryCommandLoop :
    public IStoppable,
    public ICommands
{
public:
    LibraryCommandLoop(std::istream& in, std::ostream& out, AuthorizeContext& authCtx, BookStore& bookStore, UserStore& userStore);
    void Start();
    void Stop();
    const std::vector<Command*>& getCommands() const;
private:
    std::istream& in;
    std::ostream& out;

    bool running;
    std::vector<Command*> commands;
    void loop();
    std::vector<std::string> parseArgs(std::istringstream& linestream, unsigned int max);
};
