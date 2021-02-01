#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include"input.h"
#include"grid.h"
#include"wordgame.h"
#include"moveascii.h"
#include"timer.h"

using namespace std;
extern int plays,wins;
extern int grid_flag[50][25]; //to use in all source files

position check(position);
void movement()
{
    grid jungle {50, 25};   //jungle.width=10;jungle.height=10;
    //system("chcp 65001  > nul");
    position pos;
    pos.px = 1;
    pos.py = 1;
    pos.wx1=rand()%48+1; //range 1 to 48
    pos.wy1=rand()%23+1;
    grid_flag[pos.wx1][pos.wy1]=1;
    pos.wx2=rand()%48+1;
    pos.wy2=rand()%23+1;
    grid_flag[pos.wx2][pos.wy2]=1;
    pos.wx3=rand()%48+1;
    pos.wy3=rand()%23+1;
    grid_flag[pos.wx3][pos.wy3]=1;
    pos.wx4=rand()%48+1;
    pos.wy4=rand()%23+1;
    grid_flag[pos.wx4][pos.wy4]=1;
    pos.tx1=rand()%48+1;
    pos.ty1=rand()%23+1;
    pos.tx2=rand()%48+1;
    pos.ty2=rand()%23+1;
    pos.tx3=rand()%48+1;
    pos.ty3=rand()%23+1;
    pos.tx4=rand()%48+1;
    pos.ty4=rand()%23+1;

    playerinput p;

    char input = '0';
    count_down_time_in_secs= 300;
    x_startTime=clock();
    delta_time_update_timer();
    gotoxy(1, 5);

    while (time_left>0 && plays<4)
    {
        printf("\n");
        jungle.Render(pos);
        cout<<"\n\n'd' for going right\n'a' for going left\n'w' for going up\n's' for going down\n'q' for quit\n";
        cout<<"Type in which direction you want to move: ";
        if(kbhit())
        {
            input=p.getinput();
            cin.clear(); // clear error flags

            if (input == 'w') //up
            {
                pos.py--;
                if(pos.py<=0)
                    pos.py=23;
            }
            else if (input == 's') //down
            {
                pos.py++;
                if(pos.py>=24)
                    pos.py=1;
            }
            else if (input == 'd') //right
            {
                pos.px++;
                if(pos.px>=49)
                    pos.px=1;
            }
            else if (input == 'a') //left
            {
                pos.px--;
                if(pos.px<=0)
                    pos.px=48;
            }
            else if(input == 'q')
            {
                wins++;
                return;
            }
            else
                continue; //prints grid again

            pos=check(pos);
        }
        delta_time_update_timer();
    }
    system("CLS");


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
    else if(pos.px==pos.tx1 && pos.py==pos.ty1 || pos.px==pos.tx2 && pos.py==pos.ty2 || pos.px==pos.tx3 && pos.py==pos.ty3 || pos.px==pos.tx4 && pos.py==pos.ty4)
    {
        newpos.tx1=-333;
        plays+=4;
        movebear();
    }

    return newpos;
}

#endif // MOVE_H_INCLUDED
