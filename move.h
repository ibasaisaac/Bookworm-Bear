#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include"input.h"
#include"grid.h"
#include"wordgame.h"
#include"moveascii.h"
#include"timer.h"
#include"winlose.h"

using namespace std;
extern int plays,wins,level,points;
extern int grid_flag[50][25]; //to use in all source files

bool comp(pair<string, int> a, pair<string, int> b) //arranges the players in descen ding order
{
    return (a.second>b.second);
}

position check(position);

void movement()
{
    FILE *score_fp;
    if((score_fp=fopen("scores.txt", "a+"))==NULL)
        cout<<"scores.txt is missing\n";
    int men_ch=6, bg=1, score=5;
    string name;

    cout<<"\n\nWhat's your name?\n";
    cin>>name;
    system("CLS");
    cout<<"\nHi "<<name<<"!\n";

    while(men_ch!=5)
    {
        cout<<"\n\n\n1. Start game\n2. Leaderboard\n3. BG Music\n4. How to play\n5. Exit game\n\nEnter your choice: ";
        cin>>men_ch;
        getchar();

        if(men_ch==1)
        {
            system("CLS");
            grid jungle {50, 25};

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
//            if(level==2)
//            {
//                pos.wx5=rand()%48+1;
//                pos.wy5=rand()%23+1;
//                grid_flag[pos.wx5][pos.wy5]=1;
//                pos.wx6=rand()%48+1;
//                pos.wy6=rand()%23+1;
//                grid_flag[pos.wx6][pos.wy6]=1;
//            }

            playerinput p;

            char input = '0';
            count_down_time_in_secs= 60;
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
                        //wins++;
                        break;
                    }
                    else
                        continue; //prints grid again

                    pos=check(pos);
                }
                delta_time_update_timer();
            }
            system("CLS");

            if(wins==plays)
            {
                printf("\n\n\t\tWooHoo!! You won! :)");
                PlaySound(TEXT("won.wav"), NULL, SND_SYNC);
            }
            //level failed: couldn't guess all words
            else if(plays==4)
            {
                printf("\n\n\t\tOh no!! You lose! :(\n");
                PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
            }
            else if(time_left==0)
            {
                printf( "\n\n\t\tTime's out!\n");
            }

            string tstr="\n"+name+"\t"+to_string(points);
            fputs(tstr.c_str(), score_fp); //putting the score and name in score.txt
        }

        else if(men_ch==2)
        {
            system("CLS");
            vector<pair<string, int>> entry;

            cout<<"\n\n\t\t\t Leaderboard\n\nName\t\tScore\n\n";
            char buffer1[50]; //name
            int buffer2; //score
            fseek(score_fp, 0, SEEK_SET);
            while (!feof(score_fp))
            {
                fscanf(score_fp,"%s %d",buffer1, &buffer2);
                entry.push_back(make_pair(buffer1, buffer2));
            }

            sort(entry.begin(), entry.end(), comp); //sort in descending order
            for(int i=0; i<entry.size(); i++)
                cout<<entry[i].first<<"\t\t"<<entry[i].second<<"\n";
            cout<<"\n";

            cout<<"Press enter to return to main menu\n";
            getchar();
            system("CLS");
        }
        else if(men_ch==3) //stops the Bg music
        {
            if(bg==1)
            {
                mciSendString("pause BG.mp3", NULL, 0, NULL);
                bg=0;
            }
            else
            {
                mciSendString("play BG.mp3", NULL, 0, NULL);
                bg=1;
            }
            system("CLS");
        }
        else if (men_ch==4)
        {
            system("CLS");
            cout<<"\n\n\t\t\t How to play\n\n";

            fstream rules_fp("rules.txt", ios::in);
            string buffer;

            if(rules_fp.is_open())
            {
                while(!rules_fp.eof())
                {
                    getline(rules_fp, buffer);
                    cout<<buffer<<"\n";
                }
                rules_fp.close();
            }
            else
                cout<<"rules.txt is missing\n";

            cout<<"Press enter to return to main menu\n";
            getchar();
            system("CLS");
        }
        else
        {
            exit(0);
        }
    }
    fclose(score_fp);
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
        printf("\n\n\t\tOh no!! You lose! :(\n");
        PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
        exit(0);
    }

    return newpos;
}

#endif // MOVE_H_INCLUDED
