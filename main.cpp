#include<bits/stdc++.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>

#include"formatting.h"
#include"move.h"
#include"wordgame.h"
#include"moveascii.h"
#include"grid.h"

using namespace std;

int main()
{
    //loading scores
    if((score_fp=fopen("scores.txt", "r+"))==NULL)
    {
        printf("words.txt is missing\n");
        exit(1);
    }

    //loading words and hints
    if (!load("words.txt", "hints.txt", wordlist))
    {
        cout<<"files missing\n";
        exit(1);
    }

    SetWindow(85, 40);
    draw_intro_bear();
    SetColor(lightgray);
    cout<<"\n\t\t\t!!!Welcome to Bookworm Bear!!!\n\n";
    PlaySound(TEXT("welcome.wav"), NULL, SND_FILENAME | SND_SYNC);
    SetColor(lightaqua);
    cout<<"What's your name?\n";
    SetColor(white);
    mciSendString("seek bg2.mp3 to start", 0, 100, 0); //command, ReturnString, cchReturn, hwndCallback
    mciSendString("play bg2.mp3 repeat", 0, 0, 0);
    movement();

    mciSendString("close bg2.mp3", 0, 0, 0);
    return 0;
}
