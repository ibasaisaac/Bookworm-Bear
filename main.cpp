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
using namespace std;

int plays=0,wins=0,points=0;
int grid_flag[50][25];

int main()
{
    int c=120;
    srand(time(NULL));
    mciSendString("seek BG.mp3 to start", NULL, 100, NULL);
    mciSendString("play BG.mp3", NULL, 0, NULL);
    movement();
    WorL();
    mciSendString("close BG.mp3", NULL, 0, NULL);
    return 0;
}
