#ifndef FORMATTING_H_INCLUDED
#define FORMATTING_H_INCLUDED

HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

//console size
void SetWindow(int width, int height)
{
    COORD coord;
    coord.X = width;
    coord.Y = height;

    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = height-1;
    Rect.Right = width-1;

    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

//color
enum Color {black, darkblue, darkgreen, darkaqua, darkred, darkpurple, darkyellow, lightgray,
        darkgray, lightblue, lightgreen, lightaqua, lightred, lightpurple, lightyellow, white};
void SetColor(Color c)
{
    SetConsoleTextAttribute(Handle, c);
}

//cursor position
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(Handle, coord);
}

#endif // FORMATTING_H_INCLUDED
