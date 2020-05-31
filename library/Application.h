#pragma once
#include <string>

/**
 * @brief Contains the main application entry point
 * 
 */
class Application
{
public:
    /**
     * @brief The main entry point of the application.
     * Confiigures dependecies and runs the CLI loop
     * @param in the input stream to be used by the application
     * @param out the output stream to be used by the application
     * @param userFile the filename for the users file
     */
    void run(std::istream& in, std::ostream& out, const std::string& userFile);
};

