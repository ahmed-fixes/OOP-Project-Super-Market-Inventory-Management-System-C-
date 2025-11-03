#pragma once
#include<iostream>
using namespace std;


class Bill 
{
private:
    int total;
    int itemCount;
public:
    Bill();
    void addToTotal(int amount);
    int getTotal();
    int getItemCount();
    bool isEmpty();
    void reset();
    void printSummary();
};

Bill::Bill() : total(0), itemCount(0) {}

void Bill::addToTotal(int amount) 
{ total += amount; 
  itemCount++; 
}
int Bill::getTotal() 
{
    return total; 
}
int Bill::getItemCount() 
{ 
    return itemCount;
}
bool Bill::isEmpty() 
{ 
    return itemCount == 0;
}
void Bill::reset()
{ 
    total = 0; itemCount = 0;
}

void Bill::printSummary() 
{
    cout << "\tItems Billed: " << itemCount << ", Total: " << total << endl;
}

