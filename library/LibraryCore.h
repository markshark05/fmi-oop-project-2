#pragma once
#include <ostream>
#include <string>
#include "User.h"
#include "UserStore.h"
#include "BookStore.h"

class LibraryCore
{
public:
    LibraryCore(std::ostream& out, UserStore& userStore, BookStore& bookStore);

    void login(std::string username, std::string password);
    void logout();
    
    void books_all();
    void books_info(unsigned int id);
    void books_find(const std::string& option, const std::string& option_string);
    void books_sort(const std::string& option, const std::string& asc_desc);
    
    void users_add(std::string username, std::string password);
    void users_remove(std::string username);
private:
    std::ostream& out;

    User* activeUser;
    UserStore& userStore;
    BookStore& bookStore;
};
