#pragma once
#include <iostream>
#include <fstream>
#include "InputHandler.h"
#include "FileHandler.h"
#include "Bill.h"
using namespace std;

class BillingSystem 
{
protected:
    FileHandler* handler;
    InputHandler input;
public:
    BillingSystem(FileHandler* h);
    virtual void generateBill();
    void resetBill();
    void showBillSummary();
    void printReceiptHeader();
    void printReceiptFooter();
};


BillingSystem::BillingSystem(FileHandler* h) : handler(h) {}

void BillingSystem::generateBill() 
{
    Bill bill;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') 
    {
        char item[100];
        int quant;
        cout << "\tEnter item name: ";
        cin.ignore();
        cin.getline(item, 100);
        cout << "\tEnter quantity: ";
        quant = input.inputInt();

        ifstream in("Bill.txt");
        ofstream temp("Temp.txt");
        char line[200];
        bool found = false;

        while (in.getline(line, 200))
        {
            bool valid = true;
            char name[100];
            int rate = 0, quantity = 0;
            int i = 0, j = 0;

            
            while (line[i] != ':' && line[i] != '\0')
            {
                name[j++] = line[i++];
            }
            name[j] = '\0';
            if (line[i] == '\0') valid = false;
            else
            {
                i++;
            }

            

            while (line[i] >= '0' && line[i] <= '9')
            {
                rate = rate * 10 + (line[i++] - '0');
            }
            if (line[i] == '\0') valid = false;
            else
            {
                i++;
            }

          
            while (line[i] >= '0' && line[i] <= '9')
            {
                quantity = quantity * 10 + (line[i++] - '0');
            }

            if (valid) 
            {
                
                int k = 0;
                while (item[k] != '\0' && name[k] != '\0' && item[k] == name[k])
                {
                    k++;
                }

                if (item[k] == '\0' && name[k] == '\0')
                {
                    found = true;
                    if (quant <= quantity) 
                    {
                        int amt = quant * rate;
                        bill.addToTotal(amt);
                        cout << "\tItem: " << name << " | Rate: " << rate << " | Quantity: " << quant << " | Amount: " << amt << endl;
                        quantity -= quant;
                        temp << name << ":" << rate << ":" << quantity << endl;
                    }
                    else 
                    {
                        cout << "\tInsufficient stock!" << endl;
                        temp << name << ":" << rate << ":" << quantity << endl;
                    }
                }
                else 
                {
                    temp << name << ":" << rate << ":" << quantity << endl;
                }
            }
        }

        in.close();
        temp.close();

        ofstream out("Bill.txt", ios::trunc);
        ifstream tempIn("Temp.txt");
        char c;
        while (tempIn.get(c)) out.put(c);
        tempIn.close();
        out.close();
        remove("Temp.txt");

        if (!found) 
        {
            cout << "\tItem not found!" << endl;
        }

        cout << "\tAdd another item to bill? (y/n): ";
        cin >> ch;
    }
    bill.printSummary();
}

void BillingSystem::resetBill() {}
void BillingSystem::showBillSummary() {}
void BillingSystem::printReceiptHeader() {}
void BillingSystem::printReceiptFooter() {}