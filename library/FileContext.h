#pragma once
#include <string>

class FileContext
{
public:
    FileContext();
    std::string* getActiveFile();
    void setActiveFile(const std::string& filename);
private:
    std::string value;
    bool isSet;
};

