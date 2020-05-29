#pragma once
#include <string>

class FileContext
{
public:
    FileContext();
    const std::string* getActiveFile() const;
    void setActiveFile(const std::string& filename);
    void clearActiveFile();
private:
    std::string value;
    bool isSet;
};
