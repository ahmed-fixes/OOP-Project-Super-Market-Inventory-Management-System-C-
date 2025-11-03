#pragma once
#include <iostream>
using namespace std;


class Menu
{
public:
    static void showMainMenu();
    static void showEditMenu();
    static void printTitle();
    static void printLine();
    static void showThanks();
};

void Menu::showMainMenu()
{
    cout << "\n\t=== Supermarket Billing System ===" << endl;
    cout << "\t1. Add Item" << endl;
    cout << "\t2. Print All Items" << endl;
    cout << "\t3. Delete Item" << endl;
    cout << "\t4. Generate Bill" << endl;
    cout << "\t5. Edit Item" << endl;
    cout << "\t6. Exit" << endl;
    cout << "\tEnter choice: ";
}

void Menu::showEditMenu() 
{
    cout << "\tEdit Options:\n";
    cout << "\t1. Change Name\n";
    cout << "\t2. Change Rate\n";
    cout << "\t3. Change Quantity\n";
    cout << "\t4. Back\n";
}

void Menu::printTitle()
{
    cout << "\n\tItem | Rate | Quantity\n";
    cout << "\t------------------------\n";
}

void Menu::printLine() 
{
    cout << "\t------------------------\n";
}

void Menu::showThanks() 
{
    cout << "\tThank you for using our system!\n";
}
