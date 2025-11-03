#pragma once
#include<iostream>
using namespace std;

class Item
 {
protected:
    char* name;
    int rate;
    int quantity;
public:
    Item();
    virtual ~Item();
    void setName(const char* str);
    void setRate(int r);
    void setQuantity(int q);
    char* getName();
    int getRate();
    int getQuantity();
    void printItem();
    int calculateValue();
    bool isAvailable();
};

Item::Item()
{
    name = nullptr;
    rate = 0;
    quantity = 0;
}

Item::~Item() 
{
    if (name != nullptr)
        delete[] name;
}

void Item::setName(const char* str) 
{
    if (name != nullptr) delete[] name;
    int len = 0;
    while (str[len] != '\0') len++;
    name = new char[len + 1];
    for (int i = 0; i <= len; i++) name[i] = str[i];
}

void Item::setRate(int r)
{ 
    rate = r;
}
void Item::setQuantity(int q)
{ 
    quantity = q; 
}

char* Item::getName() 
{
    return name;
}
int Item::getRate()
{ 
    return rate;
}
int Item::getQuantity()
{ 
    return quantity;
}

void Item::printItem() 
{
    cout << "Name: " << name << ", Rate: " << rate << ", Quantity: " << quantity << endl;
}

int Item::calculateValue() 
{
    return rate * quantity;
}

bool Item::isAvailable()
{
    return quantity > 0;
}
