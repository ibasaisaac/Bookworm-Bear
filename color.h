#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

HANDLE hCon;
enum Color {DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE};
void SetColor(Color c)
{
    if(hCon == NULL)
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, c);
}

#endif // COLOR_H_INCLUDED
