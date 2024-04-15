#include<iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

// Variables and arrays declaration
bool gameOver;
bool invalidCoord;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

int welcomepage()
{
    system("cls");
    int x = 0;
    SetConsoleTextAttribute(hStdOut, 3);
    cout << "\t\t\t   WELCOME to SANKE GAME" << endl;
    cout << "\n\n Press 0 key to exit game " << endl;
    cout << " Press 1 key to start game " << endl;
    cout << " Press 2 key to see controls game " << endl;
    cin >> x;
    
    if (x == 2)
    {
        system("cls");
        cout << " Press w key to move up  " << endl;
        cout << " Press s key to move down " << endl;
        cout << " Press d key to move right " << endl;
        cout << " Press a key to move left " << endl;
        cout << " Press k key to exit game " << endl;
        cout << "\n\n\t\t\t Press 0 key to exit game " << endl;
        cout << " \t\t\t Press 1 key to start game " << endl;
        cin >> x;
    }

    return x;
}

void Setup()
{  
    gameOver = false;
    dir = STOP;
    srand(time(0));
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}
void display()
{
    system("cls");
    SetConsoleTextAttribute(hStdOut, 3);
    cout << "\t\t\t    Snake GAME";
    cout << endl << endl << endl << endl;
    SetConsoleTextAttribute(hStdOut, 4);
    cout << "\t\t";
    for (int i = 0; i <= width + 1; i++) 
    {
        cout << char(178);
    }
    cout << "\t\t";
    cout << endl;
    for (int i = 0; i <= height; i++) 
    {
        cout << "\t\t";
        cout << char(178);
        for (int k = 0; k < width; k++) 
        {
            if (i == y && k == x)
            {
                SetConsoleTextAttribute(hStdOut, 7);
                cout << '@';
                SetConsoleTextAttribute(hStdOut, 4);
            }
            else if (i == fruitY && k == fruitX)
            {
                SetConsoleTextAttribute(hStdOut, 2);
                cout << "*";
                SetConsoleTextAttribute(hStdOut, 4);
            }
            else
            {
                bool printTail = false;
                for (int j = 0; j < tailLength; j++)
                {
                    if (tailX[j] == k && tailY[j] == i)
                    {
                        SetConsoleTextAttribute(hStdOut, 7);
                        cout << 'o';
                        SetConsoleTextAttribute(hStdOut, 4);
                        printTail = true;
                    }
                }
                
                if (!printTail)
                {
                    cout << " ";
                }

                //cout << " ";
            }
           

        }
        cout << char(178);
        cout << endl;
    }cout << "\t\t";
    for (int i = 0; i <= width + 1; i++) 
    {
        cout << char(178);
    }
    SetConsoleTextAttribute(hStdOut, 3);
    cout << endl<<endl<< "\t\t\t SCORE = " << score << endl;
}

void Input()
{
    
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'k':
            gameOver = true;
            break;
        }

    }
}

void Logic()
{ 
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prevX2, prevY2;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLength; i++)
    {
        prevX2 = tailX[i];
        prevY2 = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevX2;
        prevY = prevY2;
    }
 
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

 
    for (int i = 0; i < tailLength; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

   
    if (x == fruitX && y == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        
        for (int i = 0; i < tailLength; )
        {
            invalidCoord = false;
            if (tailX[i] == fruitX && tailY[i] == fruitY) {
                invalidCoord = true;
                fruitX = rand() % width;
                fruitY = rand() % height;
                break;
            }
            if (!invalidCoord)
                i++;
        }
        tailLength++;
    }

  
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;
}

int main()
{
  
    int x = 0;
    x = welcomepage();
    if (x != 0)
    {
        system("cls");
        Setup();
        while (!gameOver) 
        {
            display();
            if (dir == UP || dir==DOWN)
                   Sleep(25); 
            Sleep(40);
            Input();
            Logic();

        }
    }
    else
    {
        system("cls");
        SetConsoleTextAttribute(hStdOut, 3);
        cout << "you exit game" << endl;
    }

    return 0;
}
