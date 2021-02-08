#ifndef MOVEASCII_H_INCLUDED
#define MOVEASCII_H_INCLUDED
#include"formatting.h"
using namespace std;

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
    SetColor(darkyellow);
    for (int i = 0; i <16 ; i++)
    {
       system("CLS");
       draw(i);
    }
    SetColor(white);
}

void draw_intro_bear()
{
    SetColor(darkyellow);
    cout<<"\t\t\t"<< "    .--.              .--.        " <<"\n";
    cout<<"\t\t\t"<< "   : (\\ '. _......_ .' /) :      " <<"\n";
    cout<<"\t\t\t"<< "    '.    `        `    .'        " <<"\n";
    cout<<"\t\t\t"<< "     /'   _        _    `\\       " <<"\n";
    cout<<"\t\t\t"<< "    /     0}      {0      \\      " <<"\n";
    cout<<"\t\t\t"<< "   |       /      \\       |      " <<"\n";
    cout<<"\t\t\t"<< "   |     /'        '\\     |      " <<"\n";
    cout<<"\t\t\t"<< "    \\   | .  .==.  . |   /       " <<"\n";
    cout<<"\t\t\t"<< "     '._ \\.' \\__/ './ _.'       " <<"\n";
    cout<<"\t\t\t"<< "     /  ``'._-''-_.'``  \\        " <<"\n";
    SetColor(white);
}

void draw_thumbsup_bear(int n)
{
    SetColor(darkyellow);
    for(int i=40; i<=n; i=i+2)
    {
        system("CLS");
        cout<<setw(i)<< "    .--.              .--.               " <<"\n";
        cout<<setw(i)<< "   : (\\ '. _......_ .' /) :              " <<"\n";
        cout<<setw(i)<< "    '.    `        `    .'               " <<"\n";
        cout<<setw(i)<< "     /'   _        _    `\\                " <<"\n";
        cout<<setw(i)<< "    /     0}      {0      \\               " <<"\n";
        cout<<setw(i)<< "   |       /      \\       |              " <<"\n";
        cout<<setw(i)<< "   |     /'        '\\     |              " <<"\n";
        cout<<setw(i)<< "    \\   | .  .==.  . |   /      .        " <<"\n";
        cout<<setw(i)<< "     '._ \\.' \\__/ './ _.'      / )       " <<"\n";
        cout<<setw(i)<< "     /  ``'._-''-_.'``  \\   --' (___     " <<"\n";
        cout<<setw(i)<< "                            .  ((___)    " <<"\n";
        cout<<setw(i)<< "                            .  ((___)    " <<"\n";
        cout<<setw(i)<< "                            -._((__)     " <<"\n";
        Sleep(30);
    }
    SetColor(white);
}

void draw_treasure(void)
{
    SetColor(lightyellow);
    cout<< "         |                   |                  |                     |        " <<"\n";
    cout<< "_________|________________.=''_;=.______________|_____________________|________" <<"\n";
    cout<< "|                   |  ,-'_,=''     `'=.|                  |                   " <<"\n";
    cout<< "|___________________|__'=._o`'-._        `'=.______________|___________________" <<"\n";
    cout<< "          |                `'=._o`'=._      _`'=._                     |       " <<"\n";
    cout<< " _________|_____________________:=._o '=._.'_.-='''=.__________________|_______" <<"\n";
    cout<< "|                   |    __.--' , ; `'=._o.' ,-'''-._ '.   |                   " <<"\n";
    cout<< "|___________________|_._'  ,. .` ` `` ,  `'-._'-._   '. '__|___________________" <<"\n";
    cout<< "          |           |o`'=._` , '` `; .'. ,  '-._'-._; ;              |       " <<"\n";
    cout<< " _________|___________| ;`-.o`'=._; .' ` '`.' ` . '-._ /_______________|_______" <<"\n";
    cout<< "|                   | |o;    `'-.o`'=._``  '` ' ,__.--o;   |                   " <<"\n";
    cout<< "|___________________|_| ;     (#) `-.o `'=.`_.--'_o.-; ;___|___________________" <<"\n";
    cout<< "____/______/______/___|o;._    '      `'.o|o_.--'    ;o;____/______/______/____" <<"\n";
    cout<< "/______/______/______/_'=._o--._        ; | ;        ; ;/______/______/______/_" <<"\n";
    cout<< "____/______/______/______/__'=._o--._   ;o|o;     _._;o;____/______/______/____" <<"\n";
    cout<< "/______/______/______/______/____'=._o._; | ;_.--'o.--'_/______/______/______/_" <<"\n";
    cout<< "____/______/______/______/______/_____'=.o|o_.--''___/______/______/______/____" <<"\n";
    cout<< "/______/______/______/______/______/______/______/______/______/______/________" <<"\n";
    SetColor(white);
}


#endif // MOVEASCII_H_INCLUDED
