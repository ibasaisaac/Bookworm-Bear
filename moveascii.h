#ifndef MOVEASCII_H_INCLUDED
#define MOVEASCII_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#define SLEEP "ping -n 1 localhost > nul"
#else //In any other OS
#define CLEAR "clear"
#define SLEEP "ping -c 1 localhost > nul"
#endif
using namespace std;

void printline(char *, int);
void bear(int);

void printline(char *line, int no)
{
    for(int i=0;i<no;i++)
        printf(" ");
printf("%s\n", line);
}

void draw(int space)
{
    char *line1="             ";
char *line2="   .-^^-.            ( )-----( )          .^^^-- ";
char *line3="  / O O  |          / `~   ~` |          / O O  ] ";
char *line4="  |O .-.  |        /   0 _ 0   |        /  .-. O|";
char *line5="  | (   )  '.    _|     (_)     |     .'  (   ) /";
char *line6="   '.`-'     '-./ |    _____     |`..-'     '-' ";
char *line7="     |         |  |   ( vvv )    |   /        /";
char *line8="      |       |   '.          .'   /        /";
char *line9="       |       '.   `'-----'`'   .'        /";
char *line10="       |   .'    '-._        .-'.   '.   /";
char *line11="       |/`          `'''''')    )    `]| ";
char *line12="       /                  (    (      ,] ";
char *line13="      ;                    \    '-..-'/ |";
char *line14="      |                     '.       /  |";
char *line15="      |                       `'---'`   |";
char *line16="      ;                                 ;";
char *line17="       |                               /";
char *line18="        `.                           .'";
char *line19="          '-._                   _.-'";
char *line20="           __/`''''''  - - -  '''''|__";
char *line21="            /            /^\         | ";
char *line22="          |(          .'   '.        )/";
char *line23="          '.(__(__.-'       '.__)__).'";
printline(line1,space);
printline(line2,space);
printline(line3,space);
printline(line4,space);
printline(line5,space);
printline(line6,space);
printline(line7,space);
printline(line8,space);
printline(line9,space);
printline(line10,space);
printline(line11,space);
printline(line12,space);
printline(line13,space);
printline(line14,space);
printline(line15,space);
printline(line16,space);
printline(line17,space);
printline(line19,space);
printline(line20,space);
printline(line21,space);
printline(line22,space);
printline(line23,space);
}
void movebear()
{
    for (int i = 0; i <45 ; i++)
    {
       system(SLEEP);
       system(CLEAR);
       draw(i);
    }
}

#endif // MOVEASCII_H_INCLUDED
