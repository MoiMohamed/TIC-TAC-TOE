#include<stdio.h>
#include<windows.h>

COORD cord = {0,0};

void drawbox(int x,int y)
{
    ///first line
    printf("%c",219);
    for(int i = 1;i <= x-2;i++)printf("%c",219);
    printf("%c\n",219);

    ///rows
    for(int i = 1;i <= y-2;i++)
    {
        for(int j = 1;j <= x;j++)
        {
            if(j == 1 || j == x)
             printf("%c",219);
             else printf(" ");
        }
       printf("\n");
    }

    ///last line
    printf("%c",219);
    for(int i = 1;i <= x-2;i++)printf("%c",219);
    printf("%c",219);
}

void gotoxy(int x,int y)
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(hand,cord);
}

void showCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    cursor.bVisible = 1;
    cursor.dwSize = sizeof(cursor);

    SetConsoleCursorInfo(hand,&cursor);
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    cursor.bVisible = 0;
    cursor.dwSize = sizeof(cursor);

    SetConsoleCursorInfo(hand,&cursor);
}
