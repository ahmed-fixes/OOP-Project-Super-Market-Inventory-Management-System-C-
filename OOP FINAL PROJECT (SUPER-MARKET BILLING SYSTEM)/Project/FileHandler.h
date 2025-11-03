#pragma once
#include "Item.h"

class FileHandler 
{
public:
    virtual void saveItem(Item& item) = 0;
    virtual void loadItems() = 0;
    virtual void overwriteFile(const char* name) = 0;
    virtual void backupFile() = 0;
    virtual void clearFile() = 0;
};