#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include"input.h"
#include"grid.h"
#include"wordgame.h"

using namespace std;
extern int plays,wins; //to use in all source files

position check(position);
int movement()
{
    grid jungle {50, 25};   //jungle.width=10;jungle.height=10;
    //system("chcp 65001  > nul");
    position pos;
    pos.px = 0;
    pos.py = 0;
    pos.wx1=rand()%49+1; //range 1 to 49
    pos.wy1=rand()%24+1;
    pos.wx2=rand()%49+1;
    pos.wy2=rand()%24+1;
    pos.wx3=rand()%49+1;
    pos.wy3=rand()%24+1;
    pos.wx4=rand()%49+1;
    pos.wy4=rand()%24+1;

    playerinput p;

    char input = '0';
    while (plays<4)
    {
        printf("\n");
        jungle.Render(pos);
        input=p.getinput();
        cin.clear(); // clear error flags

        if (input == 'w') //up
        {
            pos.py--;
            if(pos.py<0)
                pos.py=24;
        }
        else if (input == 's') //down
        {
            pos.py++;
            if(pos.py>24)
                pos.py=0;
        }
        else if (input == 'd') //right
        {
            pos.px++;
            if(pos.px>49)
                pos.px=0;
        }
        else if (input == 'a') //left
        {
            pos.px--;
            if(pos.px<0)
                pos.px=49;
        }
        else if(input == 'q')
        {
            wins++;
            return;
        }
        else
            continue; //prints grid again


        system("CLS"); //clears the screen
        pos=check(pos);
    }
}
//checks for all of the pos values
position check(position pos)
{
    struct position newpos=pos;
    if(pos.px==pos.wx1 && pos.py==pos.wy1)
    {
        newpos.wx1=-333;
        hangman();
    }
    else if(pos.px==pos.wx2 && pos.py==pos.wy2)
    {
        newpos.wx2=-333;
        hangman();
    }
    else if(pos.px==pos.wx3 && pos.py==pos.wy3)
    {
        newpos.wx3=-333;
        hangman();
    }
    else if(pos.px==pos.wx4 && pos.py==pos.wy4)
    {
        newpos.wx4=-333;
        hangman();
    }

    return newpos;
}

#endif // MOVE_H_INCLUDED
