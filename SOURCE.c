#include<stdio.h>
#include<windows.h>
#include<string.h>
#include "MyWindows.h"

void tempelate();
int game();
void x(int x,int y);
void o(int x,int y);
int _check(int [],int);
void howtouse();

int main(void)
{
    int winner;
    int count = 0;
    char get;
    char p1[11];
    char p2[11];
    int p_1 = 0;
    int p_2 = 0;

system("COLOR 1E");

while(1)
{
    strcpy(p1,"\0");
    strcpy(p2,"\0");

    p_1 = 0;
    p_2 = 0;
    count = 0;
    tempelate();
    howtouse();
    gotoxy(55,14);printf("ENTER NAMES");
    gotoxy(51,16);
    printf("PLAYER 1:");

     while(1)
    {
        if((get = getch())== 13 && count > 0)
        {
             p1[count] = '\0';
             break;
        }

        if(get == 27)
        {
            gotoxy(0,25);
            return 0;
        }

        if(get == 8 && count > 0)
        {
            putch(8);
            putch(' ');
            putch(8);
            count--;
            p1[count] = '\0';
        }
        else if(get != 8 && count < 10 && get != 13)
        {
            p1[count] = get;
            count++;
            putch(get);
        }
    }
    count = 0;
    gotoxy(51,17);
    printf("PLAYER 2:");

    while(1)
    {
        if((get = getch())== 13 && count > 0)
        {
                p2[count] = '\0';
                break;
        }

        if(get == 27)
        {
            gotoxy(0,25);
            return 0;
        }

        if(get == 8 && count > 0)
        {
            putch(8);
            putch(' ');
            putch(8);
            count--;
            p2[count] = '\0';
        }
        else if(get != 8 && count < 10 && get != 13)
        {
            p2[count] = get;
            count++;
            putch(get);
        }
    }
    while(1)
    {
        system("cls");
        tempelate();
        howtouse();
        gotoxy(55,6);printf("  Scores");
        gotoxy(50,8);
        printf("%s",p1);
        gotoxy(50,9);
        printf("%s",p2);

        gotoxy(61,8);printf(":");
        gotoxy(61,9);printf(":");


        gotoxy(64,8);printf("%d",p_1);
        gotoxy(64,9);printf("%d",p_2);

        winner = game();
        if(winner == 1)
        {
            p_1++;
            gotoxy(58,24);
            printf("P1 WON  ");
            gotoxy(48,25);
            printf("PRESS ANY KEY FOR NEXT ROUND");
            getch();
        }
        else if(winner == 2)
        {
            p_2++;
            gotoxy(58,24);
            printf("P2 WON  ");
            gotoxy(48,25);
            printf("PRESS ANY KEY FOR NEXT ROUND");
            getch();
        }
        else if(winner == 3)
            break;
        else if(winner == 4)
        {
            gotoxy(0,25);
            return 0;
        }
        else if(winner == 7)
        {
            gotoxy(58,24);
            printf("TIE");
            gotoxy(48,25);
            printf("PRESS ANY KEY FOR NEXT ROUND");
            getch();
        }
    }
    system("cls");
}



}

void tempelate()
{
gotoxy(53,0);
printf("%c",201);
for(int i = 0;i < 13;i++)printf("%c",205);
printf("%c",187);

for(int i = 1;i < 2;i++)
{
    gotoxy(53,i);
    for(int j = 0;j <= 14;j++)
    {
        if(j == 0 || j == 14)
            printf("%c",186);
        else
            printf(" ");
    }
}
gotoxy(55,1);
printf("TIC-TAC-TOE");

gotoxy(53,2);
printf("%c",200);
for(int i = 0;i < 13;i++)printf("%c",205);
printf("%c",188);

gotoxy(48,10);
printf("%c",201);
for(int i = 0;i < 23;i++)printf("%c",205);
printf("%c",187);

for(int i = 11;i < 22;i++)
{
    gotoxy(48,i);
    for(int j = 0;j <= 24;j++)
    {
        if(j == 0 || j == 24)
            printf("%c",186);
        else
            printf(" ");
    }
}

gotoxy(48,22);
printf("%c",200);
for(int i = 0;i < 23;i++)printf("%c",205);
printf("%c",188);
}

int game()
{
    int win = 0 , winner = -1;
    char get;
    int reset = 0;
    int turn = 1;
    int pos = 4;
    int square[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

    ///9 squares draw
    for(int j = 56; j <= 64;j += 8)
    {
        for(int i = 11;i <= 21;i++)
        {
            gotoxy(j,i);
            printf("%c",179);
        }
    }

    for(int i = 14;i <= 18;i += 4)
    {
        for(int j = 49 ; j < 72;j++)
        {
            if(j != 56 && j != 64)
            {
                gotoxy(j,i);
                printf("%c",196);
            }
        }
    }

    int i = 0;
    while(i < 9)
    {
        gotoxy(60,16);
        pos = 4;
        while(1)
        {
            get = getch();

            if(get == 13  && square[pos] == -1)
            {
                if(turn == 0)turn = 1;//changed
                else if(turn == 1)turn = 0;//changer

                break;
            }

            if (get == 'r' || get == 'R')
            {
                reset = 1;
                break;
            }

            if (get == 'n' || get == 'N')
            {
                reset = 2;
                break;
            }
            if (get == 27)
            {
                reset = 3;
                break;
            }

            if(get == 'H')
            {
                switch(pos)
                {

                    case 0:gotoxy(52,12);
                    pos = 0;
                        break;
                    case 1:gotoxy(60,12);
                    pos = 1;
                        break;
                    case 2:gotoxy(68,12);
                    pos = 2;
                        break;
                    case 3:gotoxy(52,12);
                    pos = 0;
                        break;
                    case 4:gotoxy(60,12);
                    pos = 1;
                        break;
                    case 5:gotoxy(68,12);
                    pos = 2;
                        break;
                    case 6:gotoxy(52,16);
                    pos = 3;
                        break;
                    case 7:gotoxy(60,16);
                    pos = 4;
                        break;
                    case 8:gotoxy(68,16);
                    pos = 5;
                        break;
                }
            }
            if(get == 'P')
            {
                switch(pos)
                {

                    case 0:gotoxy(52,16);
                    pos = 3;
                        break;
                    case 1:gotoxy(60,16);
                    pos = 4;
                        break;
                    case 2:gotoxy(68,16);
                    pos = 5;
                        break;
                    case 3:gotoxy(52,20);
                    pos = 6;
                        break;
                    case 4:gotoxy(60,20);
                    pos = 7;
                        break;
                    case 5:gotoxy(68,20);
                    pos = 8;
                        break;
                    case 6:gotoxy(52,20);
                    pos = 6;
                        break;
                    case 7:gotoxy(60,20);
                    pos = 7;
                        break;
                    case 8:gotoxy(68,20);
                    pos = 8;
                        break;
                }
            }
            if(get == 'K')
            {
                switch(pos)
                {

                    case 0:gotoxy(52,12);
                    pos = 0;
                        break;
                    case 1:gotoxy(52,12);
                    pos = 0;
                        break;
                    case 2:gotoxy(60,12);
                    pos = 1;
                        break;
                    case 3:gotoxy(52,16);
                    pos = 3;
                        break;
                    case 4:gotoxy(52,16);
                    pos = 3;
                        break;
                    case 5:gotoxy(60,16);
                    pos = 4;
                        break;
                    case 6:gotoxy(52,20);
                    pos = 6;
                        break;
                    case 7:gotoxy(52,20);
                    pos = 6;
                        break;
                    case 8:gotoxy(60,20);
                    pos = 7;
                        break;
                }
            }
            if(get == 'M')
            {
                switch(pos)
                {

                    case 0:gotoxy(60,12);
                    pos = 1;
                        break;
                    case 1:gotoxy(68,12);
                    pos = 2;
                        break;
                    case 2:gotoxy(68,12);
                    pos = 2;
                        break;
                    case 3:gotoxy(60,16);
                    pos = 4;
                        break;
                    case 4:gotoxy(68,16);
                    pos = 5;
                        break;
                    case 5:gotoxy(68,16);
                    pos = 5;
                        break;
                    case 6:gotoxy(60,20);
                    pos = 7;
                        break;
                    case 7:gotoxy(68,20);
                    pos = 8;
                        break;
                    case 8:gotoxy(68,20);
                    pos = 8;
                        break;
                }
            }
        }

        if(reset == 1)return 8;
        if(reset == 2)return 3;
        if(reset == 3)return 4;

        switch(pos)
        {
        case 0:
            if(turn == 0 && square[pos] == -1)
            {
                x(50,11);
                square[pos] = 1;
            }
            else if(turn == 1 && square[pos] == -1)
            {
                    o(50,11);
                    square[pos] = 2;
            }
            break;
        case 1:
            if(turn == 0 && square[pos] == -1)
                {
                    x(58,11);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(58,11);
                    square[pos] = 2;
                }
            break;
        case 2:
            if(turn == 0 && square[pos] == -1)
                {
                    x(66,11);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(66,11);
                    square[pos] = 2;
                }
            break;
        case 3:
            if(turn == 0 && square[pos] == -1)
                {
                    x(50,15);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(50,15);
                    square[pos] = 2;
                }
            break;
        case 4:
            if(turn == 0 && square[pos] == -1)
                {
                    x(58,15);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(58,15);
                    square[pos] = 2;
                }
            break;
        case 5:
            if(turn == 0 && square[pos] == -1)
                {
                    x(66,15);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(66,15);
                    square[pos] = 2;
                }
            break;
        case 6:
            if(turn == 0 && square[pos] == -1)
                {
                    x(50,19);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(50,19);
                    square[pos] = 2;
                }
            break;
        case 7:
            if(turn == 0 && square[pos] == -1)
                {
                    x(58,19);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(58,19);
                    square[pos] = 2;
                }
            break;
        case 8:
            if(turn == 0 && square[pos] == -1)
                {
                    x(66,19);
                    square[pos] = 1;
                }
            else if(turn == 1 && square[pos] == -1)
                {
                    o(66,19);
                    square[pos] = 2;
                }
            break;
        }

       win = _check(square,1);
       if(win > 0)
       {
            winner = 1;
            return winner;
            break;
       }

       win = _check(square,2);
       if(win > 0)
       {
            winner = 2;
            return winner;
            break;
       }

        i++;
    }

    if(winner == -1)
        return 7;

}

void x(int x,int y)
{
    gotoxy(x,y);
    printf(".   .");
    gotoxy(x,y+1);
    printf("  .  ");
    gotoxy(x,y+2);
    printf(".   .");
}

void o(int x,int y)
{
    gotoxy(x,y);
    printf(" ... ");
    gotoxy(x,y+1);
    printf(".   .");
    gotoxy(x,y+2);
    printf(" ... ");
}

int _check(int arr[],int xo)
{
    int check = 0;
    int count = 0;


    ///columns
    for(int i = 0; i < 2;i++)
    {
        if(arr[i] == arr [i+1] && arr[i] == xo && arr [i+1] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    for(int i = 3; i < 5;i++)
    {
        if(arr[i] == arr [i+1] && arr[i] == xo && arr [i+1] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    for(int i = 6; i < 8;i++)
    {
        if(arr[i] == arr [i+1] && arr[i] == xo && arr [i+1] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;
    ///end

    ///rows
    for(int i = 0; i < 6;i += 3)
    {
        if(arr[i] == arr [i+3] && arr[i] == xo && arr [i+3] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    for(int i = 1; i < 7;i += 3)
    {
        if(arr[i] == arr [i+3] && arr[i] == xo && arr [i+3] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    for(int i = 2; i < 8;i += 3)
    {
        if(arr[i] == arr [i+3] && arr[i] == xo && arr [i+3] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    ///end rows

    ///Diagonals
    for(int i = 0; i < 8;i += 4)
    {
        if(arr[i] == arr [i+4] && arr[i] == xo && arr [i+4] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    for(int i = 2; i < 6;i += 2)
    {
        if(arr[i] == arr [i+2] && arr[i] == xo && arr [i+2] == xo)
            count++;
    }

    if(count == 2)
        check++;

    count = 0;

    if(check > 0)
        return 1;
    else
        return 0;

    ///end diagonals
}

void howtouse()
{
    gotoxy(2,4);
    printf("HOW TO USE:");

    gotoxy(2,6);
    printf("1 - USE KEYBOARD ARROWS TO MOVE AND ENTER KEY");
    gotoxy(2,7);
    printf("2 - PRESS 'n' FOR NEW GAME");
    gotoxy(2,8);
    printf("3 - PRESS 'R' TO RESET");
    gotoxy(2,9);
    printf("4 - PRESS ESC TO EXIT");

}
