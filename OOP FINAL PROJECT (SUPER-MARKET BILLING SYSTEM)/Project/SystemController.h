#pragma once
#include <iostream>
#include "SystemController.h"
#include "Menu.h"
#include "ShopManager.h"
#include "BillingSystem.h"
using namespace std;

class SystemController : public BillingSystem 
{
private:
    ShopManager manager;
public:
    SystemController(FileHandler* h);
    void run();
    void logAction(const char* act);
    void backupBeforeExit();
    void showWelcome();
    void clearScreen();
};

SystemController::SystemController(FileHandler* h) : BillingSystem(h), manager(h) {}

void SystemController::run() 
{
    bool exit = false;
    while (!exit)
    {
        Menu::showMainMenu();
        int choice;
        cin >> choice;

        if (choice == 1) manager.addItem();
        else if (choice == 2) manager.showItems();
        else if (choice == 3) manager.deleteItem();
        else if (choice == 4) generateBill();
        else if (choice == 5) manager.editItem();
        else if (choice == 6) {
            cout << "\tExiting..." << endl;
            exit = true;
        }
    }
}

void SystemController::logAction(const char* act) {}
void SystemController::backupBeforeExit() {}
void SystemController::showWelcome() {}
void SystemController::clearScreen() {}