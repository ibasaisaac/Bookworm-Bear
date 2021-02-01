#ifndef WORDGAME_H_INCLUDED
#define WORDGAME_H_INCLUDED

#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include"color.h"
#include"move.h"
#include"timer.h"

extern int plays,wins;
//void movement();
bool load(string file_name, vector<string> &list)
{
    fstream fp(file_name, ios::in);
    char buffer[70];

    if(fp.is_open())
    {
        list.clear();
        while(!fp.eof())
        {
            fp.getline(buffer, 70);
            list.push_back(buffer);
        }
        fp.close();
        return 1;
    }
    else
        return 0;
}

void hangman()
{
    x_countTime=clock();
    pause_time=(x_countTime-x_startTime)/CLOCKS_PER_SEC;
    system("CLS");

    //loading letters
    vector<char> alphabet;
    for (int i = 65; i <=90; i++)
        alphabet.push_back(i); //all alphabets and cross out the ones used

    //loading words
    vector<string> wordlist;
    if (!load("words.txt", wordlist))
    {
        printf("words.txt is missing\n");
        exit(1);
    }

    //loading hints
    vector<string> hintlist;
    if (!load("hints.txt", hintlist))
    {
        printf("hints.txt missing\n");
        exit(1);
    }


    //choosing random word
    srand(time(0));
    string word;
    word = wordlist.at(rand() % wordlist.size());

    int serial;

    //erasing word from vector to prevent repetition
    vector<string>::iterator itr = std::find(wordlist.begin(), wordlist.end(), word);
    if (itr != wordlist.end())
    {
        wordlist.erase(itr);
        serial = (itr - wordlist.begin())+1;
    }

    string hint = hintlist[serial-1];


    int total_letters, filled_blanks = 0, lives = 6, flag = 0, h = 1;;
    char current_blanks[10], temp='n', temp1, temp2;
    total_letters = word.size();
    for (int i = 0; i < total_letters; i++)
        current_blanks[i] = '_';



    while (lives > 0)
    {
        flag = 0;
        temp1='0';
        SetColor(PINK);
        printf("\n\n\t\t\t WORD PLAY \t\t\tlives: %d/6", lives);

        SetColor(WHITE);
        if(lives<3 && h==1)
        {
            printf("\n\n\t Need a hint?(Y/N) ");
            scanf("%c", &temp);
            getchar();
        }

        if(temp=='Y' || temp=='y')
        {
            cout<<"\n\n\t"<<hint<<"\n";
            h=0;
        }


        printf("\n\n\t ");
        for (int i = 0; i < total_letters; i++)
        {
            SetColor(DARKBLUE);
            printf("%c ", current_blanks[i]);
        }

        SetColor(TEAL);
        printf("\n\n\n\t ");
        for (auto j = alphabet.begin(); j != alphabet.end(); j++)   cout << ' ' << *j;

        while(isalpha(temp1)==0)
        {
            printf("\n\n\t Guess a letter: ");

            scanf("%c", &temp1);
            getchar();
        }
        temp2=toupper(temp1);
        std::replace (alphabet.begin(), alphabet.end(), temp2, (char)177);



        for (int i = 0; i < total_letters; i++)
        {
            if ((temp1 == word[i]) || (temp1 - 32 == word[i]) || (temp1 + 32 == word[i]))
            {
                flag = 1;
                current_blanks[i] = word[i];
                filled_blanks++;
            }
        }



        if (flag == 1)
        {
            SetColor(YELLOW);
            printf("\n\n\t\tYou got it!");
            PlaySound(TEXT("lilwin.wav"), NULL, SND_SYNC);
        }

        else
        {
            lives--;
            SetColor(DARKPINK);
            printf("\n\n\t\t%c is not here!", temp1);
            printf("\n\n\t\t%d guesses remaining", lives);
            PlaySound(TEXT("lillose.wav"), NULL, SND_SYNC);
        }

        system("CLS");
        if (filled_blanks == total_letters)
            break;
    }


    if (filled_blanks == total_letters)
    {
        SetColor(GREEN);
        cout << "\n\n\t\t" << "The word is " << word << "\n\n";
        PlaySound(TEXT("bigwin.wav"), NULL, SND_SYNC);
        wins++; //new
    }

    else
    {
        SetColor(BLUE);
        cout << "\n\n\t\t" << "The word was " << word << "\n\n";
        PlaySound(TEXT("biglose.wav"), NULL, SND_SYNC);
    }
    plays++;
    SetColor(WHITE);
    x_startTime=clock();
    count_down_time_in_secs-=pause_time;

    system("CLS");
}
void WorL()
{
    if(wins==plays)
    {
        printf("\n\n\t\tWooHoo!! You won! :)");
        PlaySound(TEXT("won.wav"), NULL, SND_SYNC);
    }
    else if(plays>=4)
    {
        printf("\n\n\t\tOh no!! You lose! :(\n");
        PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
    }
    else if(time_left==0)
    {
        printf( "\n\n\t\tTime's out!\n");
    }
}
#endif // WORDGAME_H_INCLUDED
