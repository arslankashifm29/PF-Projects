#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int len = 20;
const int wid = 40;
int shipx, shipy, enemyx[100], enemyy[100], shotx[1000], shoty[1000], z, score = 0, live = 3, stage = 1, play, f, r;
char  l, u, d, s;
enum eDirection { STOP = 0, LEFT, RIGHT, UP };
eDirection dir;
bool flag = true, hit = false, st = false;
void start();
void instruction();
void speed();
void level();
void check();
void control();
void display();
void movement();
void enemy();
void game_check();
void game_lose();
void game_stop();
void win();
void file();
int main()
{
	live = 3, stage = 1, score = 0;
	start();  // initilize the position of ship and enemy
	instruction(); // display the instruction
	while (play)
	{
		check(); // check level

		while (flag == true)
		{
			level(); // increase more enemy if level upgrade
			speed(); // maintain speed according to level
			display(); // display game
			control(); // control settings
			movement(); // move ship and fir
			enemy(); // move enemy for attack
			game_check(); // check game is over or win
		}

	}
	system("pause");
}
void start()
{
	dir = STOP; // game is stop
	shipx = len - 1; // position of ship
	shipy = wid / 2; // position of ship
	int r = 10;
	for (int i = 0; i < 100; i++) // initilize negative values so it not display until we need
	{
		enemyx[i] = -5;
		enemyy[i] = -5;
	}
	r = 16;
	for (int i = 0; i <= 2; i++) // this are high scoring enemy initilization
	{
		enemyx[i] = 0;
		enemyy[i] = r;
		r = r + 2;
	}
	r = 10;
	for (int i = 3; i <= 12; i++) // not high scoring enemy 
	{
		enemyx[i] = 1;
		enemyy[i] = r;
		r = r + 2;
	}

	for (int i = 0; i < 1000; i++) // initilize negative values so it not display until we need
	{
		shotx[i] = -1;
		shoty[i] = -1;
	}
}
void instruction()
{
	cout << "\t\t\t\t\t   INSTRUCTION" << endl;
	cout << "PRESS A = MOVE LEFT " << endl;
	cout << "PRESS D = MOVE RIGHT " << endl;
	cout << "PRESS SPACE = FIRE BULLETS " << endl;
	cout << "press any number 1 to 9 :";
	cin >> f;
	system("cls");
	SetConsoleTextAttribute(hStdOut, 7);
	cout << "\t\t\t\t  WELCOME TO SPACE SHOOTER GAME" << endl;
	cout << "press 1 for start game ";
	cin >> play;
}
void check()
{
	SetConsoleTextAttribute(hStdOut, 7);
	if (stage == 1)
	{
		score = 0;
		cout << "\t\t\t\t\t\tLEVEL 1   " << endl;
		cout << "press 1 for start play level 1 :";
		cin >> flag;
	}
	if (stage == 2)
	{
		score = 0;
		system("cls");
		cout << "\t\t\t\t\t\tLEVEL 2   " << endl;
		cout << "press 1 for start play level 2 :";
		cin >> flag;

	}
	if (stage == 3)
	{
		score = 0;
		system("cls");
		cout << "\t\t\t\t\t\tLEVEL 3   " << endl;
		cout << "press 1 for start play level 3 :";
		cin >> flag;

	}
	if (stage == 4)
	{
		score = 0;
		system("cls");
		cout << "\t\t\t\t\t\tLEVEL 4   " << endl;
		cout << "press 1 for start play level 4 :";
		cin >> flag;
	}
	if (stage == 5)
	{
		score = 0;
		system("cls");
		cout << "\t\t\t\t\t\tLEVEL 5   " << endl;
		cout << "press 1 for start play level 5 :";
		cin >> flag;
	}
}
void level()
{
	//this function upgrade level and initilize more enemy so difficulty increase
	if (score >= 80 && stage == 1)
	{
		r = 16; // r is used to locate enemy position at the center
		for (int i = 0; i <= 2; i++)
		{
			enemyx[i] = 0;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 3; i <= 12; i++)
		{
			enemyx[i] = 1;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 13; i <= 23; i++)
		{
			enemyx[i] = 2;
			enemyy[i] = r;
			r = r + 2;
		}
		stage = 2;
		flag = false;
	}
	if (score >= 140 && stage == 2)
	{
		r = 16;
		for (int i = 0; i <= 2; i++)
		{
			enemyx[i] = 0;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 3; i <= 12; i++)
		{
			enemyx[i] = 1;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 13; i <= 23; i++)
		{
			enemyx[i] = 2;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 24; i <= 34; i++)
		{
			enemyx[i] = 3;
			enemyy[i] = r;
			r = r + 2;
		}
		stage = 3;
		flag = false;
	}
	if (score >= 200 && stage == 3)
	{
		r = 16;
		for (int i = 0; i <= 2; i++)
		{
			enemyx[i] = 0;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 3; i <= 12; i++)
		{
			enemyx[i] = 1;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 13; i <= 23; i++)
		{
			enemyx[i] = 2;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 24; i <= 34; i++)
		{
			enemyx[i] = 3;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 35; i <= 45; i++)
		{
			enemyx[i] = 4;
			enemyy[i] = r;
			r = r + 2;
		}
		stage = 4;
		flag = false;
	}
	if (score >= 280 && stage == 4)
	{
		r = 16;
		for (int i = 0; i <= 2; i++)
		{
			enemyx[i] = 0;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 3; i <= 12; i++)
		{
			enemyx[i] = 1;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 13; i <= 23; i++)
		{
			enemyx[i] = 2;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 24; i <= 34; i++)
		{
			enemyx[i] = 3;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 46; i <= 56; i++)
		{
			enemyx[i] = 5;
			enemyy[i] = r;
			r = r + 2;
		}
		r = 10;
		for (int i = 35; i <= 45; i++)
		{
			enemyx[i] = 4;
			enemyy[i] = r;
			r = r + 2;
		}
		stage = 5;
		flag = false;
	}
	if (score == 400) // if score is 400 player will win the game 
	{
		win();
	}
}
void speed()
{
	if (stage == 1)
	{
		Sleep(200);
	}
	if (stage == 2)
	{
		Sleep(150);
	}
	if (stage == 3)
	{
		Sleep(100);
	}
	if (stage == 4)
	{
		Sleep(50);
	}
	if (stage == 5)
	{
		Sleep(0);
	}
}
void control()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a': dir = LEFT; break;
		case 'd': dir = RIGHT; break;
		case ' ': dir = UP; break;
		case 's': dir = STOP; break;

		default:
			break;
		}
	}

}

void movement()
{

	switch (dir)
	{

	case LEFT:shipy--; break;
	case RIGHT:shipy++; break;
	case STOP: break;
	case UP:shotx[z]--; break;

	default:
		break;
	}
	if (dir == UP)
	{

		if (dir == UP && hit == false)
		{
			for (int j = 0; j <= z; j++)
			{
				shotx[j] = shipx - 1;
				shoty[j] = shipy;
			}
			hit = true;
			dir = STOP;
			z++;
		}
		else if (dir == UP && hit == true)
		{

			for (int j = z; j <= z; j++)
			{
				shotx[j] = shipx - 1;
				shoty[j] = shipy;
			}
			hit = true;
			dir = STOP;
			z++;  //controling new fire
		}
	}
	if (shipy < 0)
	{
		shipy = 39;
	}
	if (shipy > wid)
	{
		shipy = 1;
	}

}
void enemy()
{

	if (score >= 30)
	{
		for (int l = 3; l <= 3; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 80)
	{
		for (int l = 4; l <= 4; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 110)
	{
		for (int l = 10; l <= 10; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 150)
	{
		for (int l = 12; l <= 12; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 170)
	{
		for (int l = 14; l <= 14; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 220)
	{
		for (int l = 30; l <= 30; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 250)
	{
		for (int l = 31; l <= 31; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 270)
	{
		for (int l = 32; l <= 34; l++)
		{
			enemyx[l]++;
		}
	}
	if (score >= 270)
	{
		for (int l = 39; l <= 42; l++)
		{
			enemyx[l]++;
		}
	}
}

void display()
{
	system("cls");
	SetConsoleTextAttribute(hStdOut, 3);
	cout << "\t\t\t    SPACE SHOTTER GAME";
	cout << endl << endl << endl << endl;
	SetConsoleTextAttribute(hStdOut, 4);
	cout << "\t\t";
	for (int i = 0; i <= wid + 1; i++) //display uper line of box
	{
		cout << char(178);
	}
	cout << "\t\t";
	cout << endl;
	for (int i = 0; i <= len; i++) // display vertical line of box
	{
		cout << "\t\t";
		cout << char(178);
		for (int j = 0; j < wid; j++) // dispaly spaces
		{
			cout << " ";
			if (i == shipx && j == shipy)    //ship control
			{
				SetConsoleTextAttribute(hStdOut, 3);
				cout << char(206);
				j++;
				SetConsoleTextAttribute(hStdOut, 4);
			}
			for (int l = 0; l <= 2; l++)
			{
				if (i == enemyx[l] && j == enemyy[l]) // high scoring enemy control
				{
					SetConsoleTextAttribute(hStdOut, 3);
					cout << char(254) << " ";
					j = j + 2;
					SetConsoleTextAttribute(hStdOut, 4);
				}
			}

			for (int k = 3; k <= 56; k++)
			{
				if (i == enemyx[k] && j == enemyy[k]) // enemy control
				{
					SetConsoleTextAttribute(hStdOut, 3);
					cout << char(237) << " ";
					j = j + 2;
					SetConsoleTextAttribute(hStdOut, 4);
				}
			}


			for (int k = 0; k <= z; k++)
			{                                                   // fire control
				if (i == shotx[k] && j == shoty[k])
				{
					SetConsoleTextAttribute(hStdOut, 2);
					cout << char(248);
					SetConsoleTextAttribute(hStdOut, 4);
					shotx[k]--;
					j++;
				}
			}
			for (int l = 0; l <= z; l++)
			{
				for (int n = 0; n <= 2; n++)
				{
					if (shotx[l] == enemyx[n] && shoty[l] == enemyy[n])    // hit  high scoring enemy
					{
						enemyx[n] = -3;
						enemyy[n] = -3;
						shotx[l] = -1;
						shoty[l] = -1;
						score = score + 20;
					}
				}
			}
			for (int l = 0; l <= z; l++)
			{
				for (int n = 3; n <= 56; n++)
				{
					if (shotx[l] == enemyx[n] && shoty[l] == enemyy[n])    // hit the enemy
					{
						enemyx[n] = -3;
						enemyy[n] = -3;
						shotx[l] = -1;
						shoty[l] = -1;
						score = score + 10;
					}
				}
			}
		}
		cout << char(178);
		cout << endl;
	}cout << "\t\t";
	for (int i = 0; i <= wid + 1; i++) // display last line of border
	{
		cout << char(178);
	}
	SetConsoleTextAttribute(hStdOut, 3);
	cout << endl << "live=" << live << endl << "SCORE = " << score << endl << "STAGE=" << stage;
}
void game_check()
{
	// check enemy attack and game is over or not
	for (int i = 0; i <= 56; i++)
	{
		for (int j = 10; j <= 30; j++)
		{
			if (shipx == enemyx[i] && shipy == enemyy[i]) // if enemy hit the space ship one live is decrease
			{
				live--;
			}
			if (enemyx[i] == 20 && enemyy[i] == j) // if enemy reach the planet one live decrease
			{
				live--;
			}
			if (live == 0) // if live finsih gmae will over
			{
				flag = false;
				cout << endl << "\t\t   GAME OVER" << endl;
				game_lose();
			}
		}
	}
}
void game_lose()
{
	// game over lose all lives
	int c;
	system("cls");
	SetConsoleTextAttribute(hStdOut, 7);
	cout << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t YOU LOSE THE GAME " << endl << endl;
	file();
	cout << "IF YOU WANT TO TRY AGIAN PRESS 1 :";
	cin >> c;
	if (c == 1)
	{
		system("cls");
		SetConsoleTextAttribute(hStdOut, 7);
		main();
	}
	game_stop();
}
void win()
{
	// game will end
	int c;
	system("cls");
	SetConsoleTextAttribute(hStdOut, 7);
	cout << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t YOU WON GAME CONGRATULATIONS  " << endl << endl;
	file();
	cout << "IF YOU WANT TO PLAY AGIAN PRESS 1 :";
	cin >> c;
	if (c == 1)
	{
		system("cls");
		SetConsoleTextAttribute(hStdOut, 7);
		main();
	}
	game_stop();
}
void game_stop()
{
	// game end
	system("cls");
	SetConsoleTextAttribute(hStdOut, 7);
	cout << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t THANKS FOR PLAYING THIS GAME " << endl << endl;
	system("pause");
}
void file()
{
	// save high score
	int scor = 0;
	ifstream inFile("C:/Users/Arslan/OneDrive - FAST National University/Desktop/game.txt");
	ofstream outFile("C:/Users/Arslan/OneDrive - FAST National University/Desktop/game.txt");
	if (!inFile || !outFile)
	{
		cout << "Can't open the file" << endl;
	}
	while (!inFile.eof())
	{
		inFile >> scor;
		if (!inFile.eof())
		{

			inFile >> scor;
		}
	}
	if (score > scor)
	{
		outFile << score;
		cout << "you achived highest score = " << score << endl << endl << endl;
	}
	inFile.close();
	outFile.close();
}