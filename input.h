#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include<iostream>
using namespace std;
struct playerinput
{
    char getinput()
    {
        cout<<"\n'd' for going right\n'a' for going left\n'w' for going up\n's' for going down\n'q' for quit\n";
        cout<<"Type in which direction you want to move: ";

        char input=getch();
        cin.clear(); // clear error flags
        return input;
    }
};

#endif // INPUT_H_INCLUDED
