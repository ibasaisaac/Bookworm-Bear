#include<bits/stdc++.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include"grid.h"
#include"color.h"
#include"input.h"
#include"move.h"
#include"wordgame.h"
#include"moveascii.h"
#include"timer.h"
#include"winlose.h"
using namespace std;

int plays=0,wins=0,points=6,level=1;
int grid_flag[50][25];

int main()
{
    mciSendString("seek BG.mp3 to start", NULL, 100, NULL);
    mciSendString("play BG.mp3", NULL, 0, NULL);
    srand(time(NULL));
    movement();
    //WorL();
    mciSendString("close BG.mp3", NULL, 0, NULL);
    return 0;
}
