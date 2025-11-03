#pragma once
#include <iostream>
using namespace std;


class InputHandler 
{
public:
    void inputString(char* arr);
    int inputInt();
    bool confirmAgain();
    void flushInput();
    void pause();
};

void InputHandler::inputString(char* arr) 
{
    cin.ignore();
    cin.getline(arr, 100);
}

int InputHandler::inputInt() 
{
    int x;
    cin >> x;
    return x;
}

bool InputHandler::confirmAgain()
{
    char ch;
    cout << "\tAdd another? (y/n): ";
    cin >> ch;
    return (ch == 'y' || ch == 'Y');
}

void InputHandler::flushInput() 
{
    cin.ignore();
}

void InputHandler::pause() 
{
    cout << "\tPress Enter to continue...";
    cin.ignore();
}