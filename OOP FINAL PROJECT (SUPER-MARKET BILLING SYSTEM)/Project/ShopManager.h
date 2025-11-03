#pragma once
#include <iostream>
#include "FileHandler.h"
#include "InputHandler.h"
#include "Product.h"
using namespace std;
class ShopManager
{
private:
    FileHandler* handler;
    InputHandler input;
public:
    ShopManager(FileHandler* h);
    void addItem();
    void deleteItem();
    void showItems();
    void editItem();
    void backupItems();
};

ShopManager::ShopManager(FileHandler* h) : handler(h) {}

void ShopManager::addItem()
{
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') 
    {
        Product p;
        char name[100];
        cout << "\tEnter Item Name: ";
        cin.ignore();
        cin.getline(name, 100);
        p.setName(name);

        cout << "\tEnter Rate: ";
        p.setRate(input.inputInt());

        cout << "\tEnter Quantity: ";
        p.setQuantity(input.inputInt());

        handler->saveItem(p);

        cout << "\tAdd more items? (y/n): ";
        cin >> ch;
    }
}

void ShopManager::deleteItem() 
{
    char name[100];
    cout << "\tEnter item name to delete: ";
    cin.ignore();
    cin.getline(name, 100);
    handler->overwriteFile(name);
}

void ShopManager::showItems() 
{
    handler->loadItems();
}

void ShopManager::editItem() 
{
    char name[100];
    cout << "\tEnter item name to edit: ";
    cin.ignore();
    cin.getline(name, 100);
    handler->overwriteFile(name);

    Product p;
    char newName[100];
    cout << "\tEnter New Name: ";
    cin.getline(newName, 100);
    p.setName(newName);

    cout << "\tEnter New Rate: ";
    p.setRate(input.inputInt());

    cout << "\tEnter New Quantity: ";
    p.setQuantity(input.inputInt());

    handler->saveItem(p);
    cout << "\tItem updated successfully.\n";
}

void ShopManager::backupItems()
{
    handler->backupFile();
}