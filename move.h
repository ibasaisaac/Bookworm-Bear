#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include"grid.h"
#include"wordgame.h"
#include"timer.h"
#include"moveascii.h"

using namespace std;

int wins, plays;
FILE* score_fp;

bool comp(pair<string, int> a, pair<string, int> b)
{
    return (a.second>b.second);
}

void movement()
{
    int menu_ch=0, bg=1, score=0;

    string name;
    cin>>name;
    system("CLS");
    cout<<"\nHi "<<name<<"!";


    //break when want to exit menu, proceed to close .exe
    while(1)
    {
        cout<<"\n\n\n1. Start game\n2. Leaderboard\n3. BG Music\n4. How to play\n5. Exit game\n\n";
        SetColor(lightaqua);
        cout<<"Enter your choice: ";
        SetColor(white);
        cin>>menu_ch;
        getchar();


        //start game
        if(menu_ch==1)
        {
            system("CLS");
            int words=3, level=1;//words3 need2 trap working

            score=0;
            grid jungle {30, 15};
            position ppos;

            //break when want to exit game result, proceed to main menu
            while(menu_ch==1)
            {
                Level newLevel=Level(words);
                int tem_score=0;
                wins=0;
                plays=0;
                ppos.x = 1;
                ppos.y = 1;

                char input;
                count_down_time_in_secs= 60;
                x_startTime=clock();
                delta_time_update_timer();

                //break when want to exit grid, proceed to game result
                while (time_left>0 && wins<words-1 && plays<words)
                {
                    gotoxy(0, 0);
                    SetColor(lightblue);
                    cout<<"\n\t\t\t\t Level "<<level<<"\n";
                    SetColor(lightyellow);
                    delta_time_update_timer();
                    cout<<"\t\t Score: "<<tem_score<<"\t\tCollected "<<wins<<" of "<<words-1<<" words";
                    SetColor(white);
                    gotoxy(0, 5);
                    jungle.Render(ppos, newLevel.wpos, newLevel.tpos);

                    cout<<"\n\n'd' to go right\n'a' to go left\n'w' to go up\n's' to go down\n'p' to pause\n'q' to quit to main menu\n";
                    SetColor(lightaqua);
                    cout<<"\nType in which direction you want to move: ";
                    SetColor(white);

                    if (kbhit())    //how would timer know it have to reprint again if i don't press key.
                                   //so it will keep reprinting without waiting for key press, if i press key, then this happens
                    {
                        input=getch();
                        cin.clear(); // clear error flags

                        if(input == 'q')
                        {
                            break;
                        }

                        else if (input == 'p')
                        {
                            x_countTime=clock();
                            pause_time=(x_countTime-x_startTime)/CLOCKS_PER_SEC;
                            system("CLS");
                            SetColor(lightaqua);
                            cout<<"Press enter to resume\n";
                            SetColor(white);
                            getchar();
                            system("CLS");
                            x_startTime=clock();
                            count_down_time_in_secs-= pause_time;
                        }

                        else if (input == 'w')
                        {
                            ppos.y--;
                            if(ppos.y<1)
                                ppos.y=13;
                        }

                        else if (input == 's')
                        {
                            ppos.y++;
                            if(ppos.y>13)
                                ppos.y=1;
                        }

                        else if (input == 'd')
                        {
                            ppos.x++;
                            if(ppos.x>28)
                                ppos.x=1;
                        }

                        else if (input == 'a')
                        {
                            ppos.x--;
                            if(ppos.x<1)
                                ppos.x=28;
                        }

                        else
                            continue;

                        for (unsigned int i=0; i<newLevel.wpos.size(); i++)
                        {
                            if(ppos.x==newLevel.wpos[i].x && ppos.y==newLevel.wpos[i].y)
                            {
                                PlaySound(TEXT("stepword.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                newLevel.wpos[i].x=-333;
                                plays++;
                                tem_score+=hangman();
                            }
                            else if(ppos.x==newLevel.tpos[i].x && ppos.y==newLevel.tpos[i].y)
                            {
                                PlaySound(TEXT("steptrap.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                if(tem_score>0)
                                    tem_score--;
                            }
                        }
                    }
                }

                system("CLS");

                //triggered quit, return to main menu
                if(input=='q')
                {
                    PlaySound(TEXT("ohnolose.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    movebear();
                    printf("\n\n\t\t\tGame over\n");
                    SetColor(lightaqua);
                    cout<<"\n\n\t\t\tPress enter to go to main menu\n";
                    SetColor(white);
                    getchar();
                    break;
                }

                //level cleared: guessed required words; go to next level
                else if(wins==words-1)
                {
                    score=tem_score;
                    if(level==2)    //2 levels
                    {
                        PlaySound(TEXT("treasure.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        score+=10;
                        draw_treasure();
                        printf("\n\n\t\tCongrats!! You have completed the game! *.*\n");
                        cout<<"\t\tYou get 10 bonus points and a treasure which is empty :v\n";
                        cout<<"\t\tYour total score is "<<score<<"! Go check out the Hall of Fame!";
                        SetColor(lightaqua);
                        cout<<"\n\n\t\tPress enter to go to main menu\n";
                        SetColor(white);
                        getchar();
                        break;
                    }
                    else
                    {
                        PlaySound(TEXT("woohoowon.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        draw_thumbsup_bear(65);
                        printf("\n\n\t\t\t\t  Great work!\n\t\t\t  You completed the level!:)\n\n");
                        SetColor(lightaqua);
                        cout<<"\n\n\t\t\tPress enter to go to next level\n";
                        SetColor(white);
                        getchar();
                        PlaySound(TEXT("levelup.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        level++;
                        words++;
                        system("CLS");
                        continue;
                    }
                }

                //level failed: time left but couldn't guess required words; restart this level or quit=game over
                else if(plays==words && time_left>0)
                {
                    PlaySound(TEXT("levellose.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    printf("\n\n\t\t\tOh no!! You lose! :(\n");
                    SetColor(lightaqua);
                    cout<<"\n\t\t1. Want to restart this level\n\t\t2. Quit\n";
                    SetColor(white);
                    int tem_ch;
                    cin>>tem_ch;
                    getchar();
                    if(tem_ch==2)
                    {
                        PlaySound(TEXT("ohnolose.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        movebear();
                        printf("\n\n\t\t\tGame over\n");
                        SetColor(lightaqua);
                        cout<<"\n\n\t\t\tPress enter to go to main menu\n";
                        SetColor(white);
                        getchar();
                        break;
                    }
                    else
                    {
                        system("CLS");
                        continue;
                    }

                    system("CLS");
                }

                //level failed: time out and couldn't guess required words; game over
                else if(time_left==0)
                {
                    PlaySound(TEXT("ohnolose.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    movebear();
                    printf("\n\n\t\t\t  Time's out! Game over\n");
                    SetColor(lightaqua);
                    cout<<"\n\n\t\t\tPress enter to go to main menu\n";
                    SetColor(white);
                    getchar();
                    break;
                }
            }

            fseek(score_fp, 0, SEEK_END);
            fprintf(score_fp, "\n%s    %d", name.c_str(), score);
            system("CLS");
        }


        //leaderboard
        else if(menu_ch==2)
        {
            system("CLS");
            SetColor(lightred);
            cout<<"\n\t\t\t Leaderboard\n\nName\t\tScore\n\n";

            vector<pair<string, int>> entry;
            char buffer1[50];
            int buffer2;


            fseek(score_fp, 0, SEEK_SET);
            while (!feof(score_fp))
            {
                fscanf(score_fp, "%s        %d", buffer1, &buffer2);
                entry.push_back(make_pair(buffer1, buffer2));
            }

            sort(entry.begin(), entry.end(), comp);
            SetColor(lightgray);
            for(unsigned int i=0; i<entry.size(); i++)
                cout<<entry[i].first<<"\t\t"<<entry[i].second<<"\n";
            cout<<"\n";

            SetColor(lightaqua);
            cout<<"Press enter to return to main menu\n";
            SetColor(white);
            getchar();
            system("CLS");
        }


        //bg music on off
        else if(menu_ch==3)
        {
            if(bg==1)
            {
                mciSendString("pause bg2.mp3", NULL, 0, NULL);
                bg=0;
            }
            else
            {
                mciSendString("play bg2.mp3 repeat", NULL, 0, NULL);
                bg=1;
            }
            system("CLS");
        }


        //how to play
        else if (menu_ch==4)
        {
            system("CLS");
            SetColor(lightred);
            cout<<"\t\t\t\t How to play\n\n";
            SetColor(lightgray);
            ifstream rules_fp("rules.txt", ios::in);
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
            {
                cout<<"rules.txt is missing\n";
                exit(1);
            }

            SetColor(lightaqua);
            cout<<"Press enter to return to main menu\n";
            SetColor(white);
            getchar();
            system("CLS");
        }


        //exit
        else if(menu_ch==5)
            break;

        else
            continue;
    }
}


#endif // MOVE_H_INCLUDED
