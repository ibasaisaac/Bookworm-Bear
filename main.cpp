#include<bits/stdc++.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include"grid.h"
#include"color.h"
#include"input.h"
#include"move.h"
#include"wordgame.h"

using namespace std;

int plays=0,wins=0;
int main()
{

    mciSendString("seek BG.mp3 to start", NULL, 100, NULL);
    mciSendString("play BG.mp3", NULL, 0, NULL);
    //PlaySound(TEXT("welcome.wav"), NULL, SND_SYNC);

    srand(time(NULL));
    movement();
    WorL();
    return 0;
}
