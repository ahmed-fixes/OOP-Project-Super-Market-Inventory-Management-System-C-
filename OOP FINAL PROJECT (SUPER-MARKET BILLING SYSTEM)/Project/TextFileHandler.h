#pragma once
#include<iostream>
#include <fstream>
#include "FileHandler.h"
using namespace std;

class TextFileHandler : public FileHandler 
{
public:
    void saveItem(Item& item);
    void loadItems();
    void overwriteFile(const char* skipItem);
    void backupFile();
    void clearFile();
};

void TextFileHandler::saveItem(Item& item)
{
    ofstream out("Bill.txt", ios::app);
    if (out) 
    {
        out << item.getName() << ":" << item.getRate() << ":" << item.getQuantity() << endl;
    }
    out.close();
}

void TextFileHandler::loadItems() 
{
    ifstream in("Bill.txt");
    char line[200];

    cout << "\tItem | Rate | Quantity" << endl;
    cout << "\t------------------------" << endl;

    while (in.getline(line, 200))
    {
        bool valid = true;

        if (line[0] == '\0') 
        {
            valid = false;
        }

        char name[100];
        int rate = 0, quantity = 0;
        int i = 0, j = 0;

        if (valid) {
            while (line[i] != ':' && line[i] != '\0') 
            {
                name[j++] = line[i++];
            }
            name[j] = '\0';

            if (line[i] == '\0')
            {
                valid = false;
            }
            else {
                i++;
            }
        }

        if (valid) {
            while (line[i] >= '0' && line[i] <= '9') 
            {
                rate = rate * 10 + (line[i++] - '0');
            }

            if (line[i] == '\0') 
            {
                valid = false;
            }
            else 
            {
                i++;
            }
        }

        if (valid) {
            while (line[i] >= '0' && line[i] <= '9')
            {
                quantity = quantity * 10 + (line[i++] - '0');
            }
        }

        if (valid) 
        {
            cout << "\t" << name << " | " << rate << " | " << quantity << endl;
        }
    }

    in.close();
}

void TextFileHandler::overwriteFile(const char* skipItem)
{
    ifstream in("Bill.txt");
    ofstream temp("Temp.txt");
    char line[200];

    while (in.getline(line, 200))
    {
        char itemName[100];
        int i = 0, j = 0;
        while (line[i] != ':' && line[i] != '\0') 
        { 
            itemName[j++] = line[i++]; 
        }
        itemName[j] = '\0';

        int k = 0;
        while (itemName[k] != '\0' && skipItem[k] != '\0' && itemName[k] == skipItem[k]) 
        {
            k++;
        }

        if (!(itemName[k] == '\0' && skipItem[k] == '\0')) 
        {
            temp << line << endl;
        }
    }

    in.close();
    temp.close();

    ofstream finalOut("Bill.txt");
    ifstream tempIn("Temp.txt");
    char c;
    while (tempIn.get(c)) 
    {
        finalOut.put(c);
    }
    tempIn.close();
    finalOut.close();
    remove("Temp.txt");
}

void TextFileHandler::backupFile()
{
    ifstream in("Bill.txt");
    ofstream out("Backup.txt");
    char c;
    while (in.get(c)) out.put(c);
    in.close();
    out.close();
}

void TextFileHandler::clearFile()
{
    ofstream out("Bill.txt", ios::trunc);
    out.close();
}