#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include"grid.h"
#include"wordgame.h"
#include"moveascii.h"
#include"timer.h"

using namespace std;
extern int plays,wins,level,points;
//to use in all source files

bool comp(pair<string, int> a, pair<string, int> b) //arranges the players in descen ding order
{
    return (a.second>b.second);
}

position check(position);

void movement()
{
    FILE *score_fp;
    if((score_fp=fopen("scores.txt", "a+"))==NULL)
    {
        cout<<"scores.txt is missing\n";
        exit(1);
    }
    int men_ch=0, bg=1, score=0, bear=0;
    string name;

    cout<<"\n\t\t\t!!!Welcome to Bookworm Bear!!!\n\nWhat's your name?\n";
    cin>>name;
    system("CLS");
    cout<<"\nHi "<<name<<"!\n";

    //break when want to exit menu
    while(1)
    {
        cout<<"\n\n\n1. Start game\n2. Leaderboard\n3. BG Music\n4. How to play\n5. Exit game\n\nEnter your choice: ";
        cin>>men_ch;
        getchar();

        //start game
        if(men_ch==1)
        {
            system("CLS");
            int words=4;
            score=0;
            grid jungle {50, 25};
            position ppos;
            while(men_ch==1)
            {
                Level newLevel=Level(words);//new struct for new level
                wins=0;
                plays=0;
                ppos.x = 1;
                ppos.y = 1;
//            pos.wx1=rand()%48+1; //range 1 to 48
//            pos.wy1=rand()%23+1;
//            grid_flag[pos.wx1][pos.wy1]=1;
//            pos.wx2=rand()%48+1;
//            pos.wy2=rand()%23+1;
//            grid_flag[pos.wx2][pos.wy2]=1;
//            pos.wx3=rand()%48+1;
//            pos.wy3=rand()%23+1;
//            grid_flag[pos.wx3][pos.wy3]=1;
//            pos.wx4=rand()%48+1;
//            pos.wy4=rand()%23+1;
//            grid_flag[pos.wx4][pos.wy4]=1;
//            pos.tx1=rand()%48+1;
//            pos.ty1=rand()%23+1;
//            pos.tx2=rand()%48+1;
//            pos.ty2=rand()%23+1;
//            pos.tx3=rand()%48+1;
//            pos.ty3=rand()%23+1;
//            pos.tx4=rand()%48+1;
//            pos.ty4=rand()%23+1;
//            if(level==2)
//            {
//                pos.wx5=rand()%48+1;
//                pos.wy5=rand()%23+1;
//                grid_flag[pos.wx5][pos.wy5]=1;
//                pos.wx6=rand()%48+1;
//                pos.wy6=rand()%23+1;
//                grid_flag[pos.wx6][pos.wy6]=1;
//            }


                char input;
                count_down_time_in_secs= 60;
                x_startTime=clock();
                delta_time_update_timer();
                gotoxy(1, 5);

                //break when want to exit grid then proceed to game result
                while (time_left>0 && plays<words /*&& wins<=words*/)
                {
                    cout<<endl;
                    jungle.Render(ppos, newLevel.wpos, newLevel.tpos);
                    cout<<"\n\n'd' for going right\n'a' for going left\n'w' for going up\n's' for going down\n'p' for pausing the game\n'q' for quit\n";
                    cout<<"Type in which direction you want to move: ";

                    if(kbhit())
                    {
                        input=getch();
                        cin.clear(); // clear error flags

                        if(input=='q') //quit
                        {
                            break;
                        }
                        else if(input=='p') //pause time
                        {
                            x_countTime=clock();
                            pause_time=(x_countTime-x_startTime)/CLOCKS_PER_SEC;
                            system("CLS");
                            cout<<"Press enter to resume\n";
                            getchar();
                            system("CLS");
                            x_startTime=clock();
                            count_down_time_in_secs-= pause_time;
                        }
                        else if (input == 'w') //up
                        {
                            ppos.y--;
                            if(ppos.y<1)
                                ppos.y=23;
                        }
                        else if (input == 's') //down
                        {
                            ppos.y++;
                            if(ppos.y>23)
                                ppos.y=1;
                        }
                        else if (input == 'd') //right
                        {
                            ppos.x++;
                            if(ppos.x>48)
                                ppos.x=1;
                        }
                        else if (input == 'a') //left
                        {
                            ppos.x--;
                            if(ppos.x<1)
                                ppos.x=48;
                        }
                        else
                            continue; //prints grid again

                        // pos=check(pos);

                        //hangman start condition
                        for (int i=0; i<newLevel.wpos.size(); i++)
                        {
                            //P reaches a W, hangman starts
                            if(ppos.x==newLevel.wpos[i].x && ppos.y==newLevel.wpos[i].y)
                            {
                                newLevel.wpos[i].x=-333;
                                plays++;
                                score+=hangman();
                            }
                            else if(ppos.x==newLevel.tpos[i].x && ppos.y==newLevel.tpos[i].y)
                            {
                                movebear();
                                bear=1;
                                break;
                            }
                        }
                        if(bear==1)
                            break;
                    }
                    delta_time_update_timer();
                }
                system("CLS");

                //triggered quit, return to main menu
                if(input=='q' || bear==1)
                {
                    printf("\n\n\t\tGame over\n");
                    PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
                    cout<<"Score: "<<score<<endl<<endl;
                    //cout<<"Plays: "<<plays<<endl;
                    bear=0;
                    cout<<"Press enter to go to main menu\n";
                    getchar();
                    break;
                }
                //all levels cleared
                else if(wins>=15)
                {
                    printf("\n\n\t\tCongrats!! You have completed the game! *.* \n\n");
                    cout<<"Score: "<<score<<endl<<endl;
                    break;
                }
                //level cleared: guessed required words; go to next level
                else if(wins>=words-1)
                {
//                    if(wins>=15)
//                    {
//                        printf("\n\n\t\tCongrats!! You have completed the game! *.* \n\n");
//                        cout<<"Score: "<<score<<endl<<endl;
//                        break;
//                    }
//                    else
//                    {
                        printf("\n\n\t\tWooHoo!! You won! :)\n\n");
                        PlaySound(TEXT("won.wav"), NULL, SND_SYNC);
                        cout<<"Score: "<<score<<endl<<endl;
                        cout<<"Press enter to go to next level\n";
                        getchar();
                        words+=2;
                    //}
                    system("CLS");
                }

//            if(wins==plays && wins!=0)
//            {
//                printf("\n\n\t\tWooHoo!! You won! :)");
//                PlaySound(TEXT("won.wav"), NULL, SND_SYNC);
//                wins=0;
//                plays=0;
//                continue;
//            }
                //level failed: time left but words unsolved
                else if(plays==words && time_left>0 && wins<words-1)
                {
                    printf("\n\n\t\tOh no!! You lose! :(\n");
                    PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
                    cout<<"Score: "<<score<<endl<<endl;
                    cout<<"1. Want to restart this level\n2. Quit\n";
                    int tem_ch;
                    cin>>tem_ch;
                    if(tem_ch==2)
                    {
                        printf("\n\n\t\tGame over\n");
                        PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
                        cout<<"Press enter to go to main menu\n";
                        getchar();
                        break;
                    }
                    else //tem_ch==1
                        continue;

                    system("CLS");
                }
                //level failed: time out and words unsolved
                else if(time_left==0)
                {
                    printf("\n\n\t\tTime's out! Game over\n");
                    PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
                    cout<<"Score: "<<score<<endl<<endl;
                    cout<<"Press enter to go to main menu\n";
                    getchar();
                    break;
                }
            }
            string tstr="\n"+name+"\t"+to_string(points);
            fputs(tstr.c_str(), score_fp); //putting the score and name in score.txt
            system("CLS");
        }

        //leaderboard
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

        //the Bg music on/off
        else if(men_ch==3)
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

        //game rules
        else if (men_ch==4)
        {
            system("CLS");
            cout<<"\n\n\t\t\t How to play\n\n";

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
                cout<<"rules.txt is missing\n";

            cout<<"Press enter to return to main menu\n";
            getchar();
            system("CLS");
        }
        else if(men_ch==5)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    mciSendString("close BG.mp3", NULL, 0, NULL);
    fclose(score_fp);
}

//checks for all of the pos values
//position check(position pos)
//{
//    struct position newpos=pos;
//    if(pos.px==pos.wx1 && pos.py==pos.wy1)
//    {
//        newpos.wx1=-333;
//        hangman();
//    }
//    else if(pos.px==pos.wx2 && pos.py==pos.wy2)
//    {
//        newpos.wx2=-333;
//        hangman();
//    }
//    else if(pos.px==pos.wx3 && pos.py==pos.wy3)
//    {
//        newpos.wx3=-333;
//        hangman();
//    }
//    else if(pos.px==pos.wx4 && pos.py==pos.wy4)
//    {
//        newpos.wx4=-333;
//        hangman();
//    }
//    else if(pos.px==pos.tx1 && pos.py==pos.ty1 || pos.px==pos.tx2 && pos.py==pos.ty2 || pos.px==pos.tx3 && pos.py==pos.ty3 || pos.px==pos.tx4 && pos.py==pos.ty4)
//    {
//        newpos.tx1=-333;
//        plays+=4;
//        movebear();
//        printf("\n\n\t\tOh no!! You lose! :(\n");
//        PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
//    }
//
//    return newpos;
//}

#endif // MOVE_H_INCLUDED
