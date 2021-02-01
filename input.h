#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include<iostream>
using namespace std;
struct playerinput
{
    char getinput()
    {
        char input=getch();
        cin.clear(); // clear error flags
        return input;
    }
};

#endif // INPUT_H_INCLUDED
