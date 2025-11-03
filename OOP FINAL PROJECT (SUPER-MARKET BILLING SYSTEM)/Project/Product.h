#pragma once


#include "Item.h"

class Product : public Item
{
public:
    void updateStock(int q);
    void reduceStock(int q);
    bool checkStock(int q);
    int stockValue();
    void restock(int q);
};

void Product::updateStock(int q)
{
    quantity += q;
}

void Product::reduceStock(int q) 
{
    if (q <= quantity)
        quantity -= q;
}

bool Product::checkStock(int q) 
{
    return q <= quantity;
}

int Product::stockValue() 
{
    return quantity * rate;
}

void Product::restock(int q)
{
    updateStock(q);
}