#include <iostream>
#include "Application.h"

int main()
{
    Application app;
    app.run(std::cin, std::cout, "users.csv");

    return 0;
}
