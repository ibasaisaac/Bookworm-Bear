#ifndef WINLOSE_H_INCLUDED
#define WINLOSE_H_INCLUDED
#include"wordgame.h"
#include"grid.h"
#include"move.h"
#include"input.h"
#include"timer.h"
#include"color.h"
extern int plays,wins,points;
char ch;
void WorL()
{
    if(wins==plays)
    {
        printf("\n\n\t\tWooHoo!! You won! :)");
        cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
        PlaySound(TEXT("won.wav"), NULL, SND_SYNC);
//        cout<<"\n\n\n"<<"Do you want to continue? (Y/N)"<<endl;
//        cout<<"Enter choice: ";
//        cin>>ch;
//        if(toupper(ch)=='Y')
//        {
//            wins=0;
//            plays=0;
//        }
//        else
//        {
//            printf("\n\n\t\tOh no!! You lose! :(\n");
//            cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
//            PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
//        }
    }
    else if(plays>=4 && wins<4)
    {
        //printf("\n\n\t\tOh no!! You lose! :(\n");
        cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
        cout<<"Restart the level? (Y/N)"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        if(toupper(ch)=='Y')
        {
            wins=0;
            plays=0;
            points=0;
            movement();
        }
        else
        {
            printf("\n\n\t\tOh no!! You lose! :(\n");
            cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
            PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
        }
        PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
    }
    else if(time_left==0)
    {
        printf( "\n\n\t\tTime's out!\n");
        cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
        printf("\n\n\t\tOh no!! You lose! :(\n");
        PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
    }
}
#endif // WINLOSE_H_INCLUDED