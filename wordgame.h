#ifndef WORDGAME_H_INCLUDED
#define WORDGAME_H_INCLUDED

#include"timer.h"

extern int wins;
vector<pair<string, string>> wordlist;
int serial[20]= {0}, s=0;


//hangman gameplay
int hangman(void)
{
    x_countTime=clock();
    pause_time=(x_countTime-x_startTime)/CLOCKS_PER_SEC;
    system("CLS");

    //loading fresh letters for reference
    vector<char> alphabet;
    vector<char>:: iterator j;
    j=alphabet.begin();
    for (int i = 65; i <=90; i++)
        alphabet.push_back(i);

    
    int total_letters= wordlist[serial[s]].first.size(), filled_blanks = 0, lives = 6, points = 6, flag = 0, h = 1;
    char current_blanks[20], hint_ch='n', letter1, letter2;

    for (int i = 0; i < total_letters; i++)
        current_blanks[i] = '_';



    while (lives > 0)
    {
        flag = 0;
        letter1='0';

        SetColor(lightred);
        printf("\n\n\t\t\t\t Word Game \t\t\tlives: %d/6", lives);


        //hint
        SetColor(lightaqua);
        cout<<"\n\n";
        if(lives<3 && h==1)
        {
            printf("\tNeed a hint?(Y/N) ");
            scanf("%c", &hint_ch);
            getchar();
        }

        if(hint_ch=='Y' || hint_ch=='y')
        {
            SetColor(white);
            cout<<"\n\n\t"<<wordlist[serial[s]].second;
            h=0;
        }


        //printing blanks
        printf("\n\n\n\n\t");
        for (int i = 0; i < total_letters; i++)
        {
            SetColor(lightyellow);
            printf("%c ", current_blanks[i]);
        }


        //printing reference alphabet
        SetColor(darkaqua);
        printf("\n\n\n\t ");
        for (j = alphabet.begin(); j != alphabet.end(); j++)
            cout << " " << *j;



        //taking input and replacing used letter with symbol for reference
        SetColor(lightaqua);
        while(isalpha(letter1)==0)
        {
            printf("\n\n\tGuess a letter: ");
            scanf("%c", &letter1);
            getchar();
        }
        letter2=toupper(letter1);
        replace (alphabet.begin(), alphabet.end(), letter2, (char)177);
        SetColor(white);


        //checking input with word and updating blanks
        for (int i = 0; i < total_letters; i++)
        {
            if (tolower(letter1)==wordlist[serial[s]].first[i])
            {
                flag = 1;
                current_blanks[i] = wordlist[serial[s]].first[i];
                filled_blanks++;
            }
        }



        //guessed a letter correctly
        if (flag == 1)
        {
            printf("\n\n\t\t\t\tYou got it!");
            PlaySound(TEXT("lettercorrect.wav"), NULL, SND_FILENAME | SND_SYNC);
        }
        //guessed a letter incorrectly
        else
        {
            lives--;
            points--;
            printf("\n\n\t\t\t\t%c is not here!", letter1);
            printf("\n\n\t\t\t      %d guesses remaining", lives);
            PlaySound(TEXT("letterwrong.wav"), NULL, SND_FILENAME | SND_SYNC);
        }

        system("CLS");
        if (filled_blanks == total_letters)
            break;
    }



    //guessed whole word
    if (filled_blanks == total_letters)
    {
        cout << "\n\n\n\t\t\t" << "   The word is " << wordlist[serial[s]].first << "\n\n";
        PlaySound(TEXT("wordcorrect.wav"), NULL, SND_FILENAME | SND_SYNC);
        wins++;
    }
    //couldn't guess word
    else
    {
        cout << "\n\n\n\t\t\t" << "   The word was " << wordlist[serial[s]].first << "\n\n";
        PlaySound(TEXT("wordwrong.wav"), NULL, SND_FILENAME | SND_SYNC);
    }

    s++;


    SetColor(white);

    x_startTime=clock();
    count_down_time_in_secs-= pause_time;

    system("CLS");
    return points;
}

//to load words and hints from file to vector
bool load(string word_file, string hint_file, vector<pair<string,string>> &list)
{
    list.clear();
    string buffer1, buffer2;
    int i=0;
    ifstream fp1(word_file, ios::in);
    ifstream fp2(hint_file, ios::in);

    if(fp1.is_open() && fp2.is_open())
    {
        while(!fp1.eof())
        {
            getline(fp1, buffer1);
            list.push_back(make_pair(buffer1, " "));
        }
        fp1.close();

        while(!fp2.eof())
        {
            getline(fp2, buffer2);
            list[i].second=buffer2;
            i++;
        }
        fp2.close();

        srand(time(0));
        int generated[list.size()]= {0};
        unsigned int count = 0, num;

        while (count<list.size())
        {
            num = rand()%list.size();

            if (generated[num] == 0)
            {
                generated[num] = 1;
                serial[count++] = num;
            }
        }
        return 1;
    }
    else
        return 0;
}

#endif // WORDGAME_H_INCLUDED
