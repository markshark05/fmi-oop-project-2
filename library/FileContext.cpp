#include "FileContext.h"

FileContext::FileContext() :
    isSet(false)
{
}

std::string* FileContext::getActiveFile()
{
    if (isSet) return &value;
    return nullptr;
}

void FileContext::setActiveFile(const std::string& filename)
{
    value = filename;
    isSet = true;
}
