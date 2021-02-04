#ifndef WORDGAME_H_INCLUDED
#define WORDGAME_H_INCLUDED

#include<cstdlib>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include"color.h"
#include"move.h"
#include"timer.h"

extern int plays,wins,points;

vector<string> wordlist;
vector<string> hintlist;


//to load words and hints from file to vector
bool load(string file_name, vector<string> &list) //list passing the address of wordlist and hintslist
{
    ifstream fp(file_name, ios::in);
    string buffer;

    if(fp.is_open())
    {
        list.clear();
        while(!fp.eof())
        {
            getline(fp, buffer);
            list.push_back(buffer);
        }
        fp.close();
        return 1;
    }
    else
        return 0;
}

int hangman(void)
{
    x_countTime=clock();
    pause_time=(x_countTime-x_startTime)/CLOCKS_PER_SEC;
    system("CLS");

    //loading fresh letters for reference
    vector<char> alphabet;
    for (int i = 65; i <=90; i++)
        alphabet.push_back(i); //all alphabets and cross out the ones used

    //choosing random word
    srand(time(0));
    string word;
    word = wordlist.at(rand() % wordlist.size());

//    //loading words
//    vector<string> wordlist;
//    if (!load("words.txt", wordlist))
//    {
//        printf("words.txt is missing\n");
//        exit(1);
//    }
//
//    //loading hints
//    vector<string> hintlist;
//    if (!load("hints.txt", hintlist))
//    {
//        printf("hints.txt missing\n");
//        exit(1);
//    }


    int serial;

    //erasing word from vector to prevent repetition and getting the correspondent hint
    vector<string>::iterator itr = std::find(wordlist.begin(), wordlist.end(), word);
    if (itr != wordlist.end())
    {
        serial = (itr - wordlist.begin())+1;
        wordlist.erase(itr);
    }

    string hint = hintlist[serial-1];

    //erasing the serial hint from hinlist
    itr = find(hintlist.begin(), hintlist.end(), hint);
    if (itr != hintlist.end())
    {
        hintlist.erase(itr);
    }

    int total_letters, filled_blanks = 0, lives = 6, flag = 0, h = 1, points=6;
    char current_blanks[25], hint_ch='n', letter1, letter2;
    total_letters = word.size();
    for (int i = 0; i < total_letters; i++)
        current_blanks[i] = '_';



    while (lives > 0)
    {
        flag = 0;
        letter1='0';
        SetColor(PINK);
        printf("\n\n\t\t\t WORD PLAY \t\t\tlives: %d/6", lives);

        //hint
        SetColor(WHITE);
        if(lives<3 && h==1)
        {
            printf("\n\n\t Need a hint?(Y/N) ");
            scanf("%c", &hint_ch);
            getchar();
        }

        if(hint_ch=='Y' || hint_ch=='y')
        {
            cout<<"\n\n\t"<<hint<<"\n";
            h=0;
        }

        //printing blanks
        printf("\n\n\t ");
        for (int i = 0; i < total_letters; i++)
        {
            SetColor(DARKBLUE);
            printf("%c ", current_blanks[i]);
        }

        //printing reference alphabet
        SetColor(TEAL);
        printf("\n\n\n\t ");
        for (auto j = alphabet.begin(); j != alphabet.end(); j++)
            cout << ' ' << *j;

        while(isalpha(letter1)==0) //until letters entered
        {
            printf("\n\n\t Guess a letter: ");

            scanf("%c", &letter1);
            getchar();
        }
        letter2=toupper(letter1);
        std::replace (alphabet.begin(), alphabet.end(), letter2, (char)177); //crossing out the guessed letters


        //checking input letter with word and updating blanks
        for (int i = 0; i < total_letters; i++)
        {
            if (tolower(letter1) == word[i])
            {
                flag = 1;
                current_blanks[i] = word[i];
                filled_blanks++;
            }
        }


        //correctly guessed
        if (flag == 1)
        {
            SetColor(YELLOW);
            printf("\n\n\t\tYou got it!");
            PlaySound(TEXT("lilwin.wav"), NULL, SND_SYNC);
        }
        //could not guess correctly
        else
        {
            lives--;
            points--;
            SetColor(DARKPINK);
            printf("\n\n\t\t%c is not here!", letter1);
            printf("\n\n\t\t%d guesses remaining", lives);
            PlaySound(TEXT("lillose.wav"), NULL, SND_SYNC);
        }

        system("CLS");
        if (filled_blanks == total_letters)
            break;
    }

    //guessed the word
    if (filled_blanks == total_letters)
    {
        SetColor(GREEN);
        cout<<"\n\n\t\t"<<"Good job"<<endl<<endl;
        cout << "\n\n\t\t" << "The word is " << word << endl;
        //cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
        PlaySound(TEXT("bigwin.wav"), NULL, SND_SYNC);
        wins++; //new
    }
    //could not guess the word
    else
    {
        SetColor(BLUE);
        cout << "\n\n\t\t" << "The word was " << word << "\n\n";
        //cout<<"\n\t\t"<<"You have "<<points<<" points"<<"\n\n";
        PlaySound(TEXT("biglose.wav"), NULL, SND_SYNC);
    }
    SetColor(WHITE);
    x_startTime=clock();
    count_down_time_in_secs-=pause_time;

    system("CLS");

    return points;
}

#endif // WORDGAME_H_INCLUDED
