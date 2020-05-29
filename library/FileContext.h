#pragma once
#include <string>

class FileContext
{
private:
    std::string value;
    bool isSet;
public:
    FileContext();
    const std::string* getActiveFile() const;
    void setActiveFile(const std::string& filename);
    void clearActiveFile();
};
