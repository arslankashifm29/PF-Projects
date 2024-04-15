#include<iostream>
using namespace std;
char a[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int slot = 0, row = 0, column = 0, term = 0;
bool flag = true;
char symbol = 'x';
void display(char a[][3]);
void playerturn(char a[][3], char& symbol);
void place(int slot);
void check(char symbol);
int main()
{
	cout << "\t\t\tWELCOME TO TICK CROSS GAME"<<endl<<endl;
	cout << "please choose your symbol :";
	cin >> symbol;
	playerturn(a, symbol);
}
void playerturn(char a[][3], char& symbol)
{
	while (flag == true)
	{
		if (symbol == 'x')
		{
			cout << endl << endl;
			cout << "player one turn" << endl;
			cout << "please enter your slot :";
			cin >> slot;
			term++;
			place(slot);

		}
		else if (symbol == 'o')
		{
			cout << endl << endl;
			cout << "player two turn" << endl;
			cout << "please enter your slot :";
			cin >> slot;
			term++;
			place(slot);

		}
	}
	cout << "\t\tgame over"<<endl;
	system("pause");
}
void place(int slot)
{
	switch (slot)
	{
	case 1:row = 0, column = 0; break;
	case 2:row = 0, column = 1; break;
	case 3:row = 0, column = 2; break;
	case 4:row = 1, column = 0; break;
	case 5:row = 1, column = 1; break;
	case 6:row = 1, column = 2; break;
	case 7:row = 2, column = 0; break;
	case 8:row = 2, column = 1; break;
	case 9:row = 2, column = 2; break;
	default:
		cout << "invalid input"; break;
	}
	if (symbol == 'x' && a[row][column] != 'x' && a[row][column] != 'o')
	{
		a[row][column] = 'x';
		symbol = 'o';
		display(a);

	}
	else if (symbol == 'o' && a[row][column] != 'x' && a[row][column] != 'o')
	{
		a[row][column] = 'o';
		symbol = 'x';
		display(a);
	}
	else
	{
		term--;
		playerturn(a, symbol);
	}


}
void display(char a[][3])
{
	system("cls");
	cout << "\t\t\t TICK CROSS GAME";
	cout << endl << endl << endl;
	cout << "\t \t \t   | \t  | " << endl;
	cout << "\t \t \t " << a[0][0] << " | \t" << a[0][1] << " | " << a[0][2] << endl;
	cout << "   \t \t      __________________" << endl;
	cout << "\t \t \t   | \t  | " << endl;
	cout << "\t  \t \t" << a[1][0] << "  | \t" << a[1][1] << " | " << a[1][2] << endl;
	cout << "   \t \t      __________________" << endl;
	cout << "\t \t \t   | \t  | " << endl;
	cout << "\t \t \t " << a[2][0] << " | \t" << a[2][1] << " | " << a[2][2] << endl;

	check(symbol);
	playerturn(a, symbol);

}
void check(char symbol)
{
	if (term == 9)
	{
		cout << "\t\t\t\tgame tie" << endl;
		flag = false;
	}

	for (int i = 0; i < 3 && term != 9; i++)
	{
		if (a[i][0] == a[i][1] && a[i][0] == a[i][2])
		{
			cout << "\t\t\t\twin" << endl;
			flag = false;
		}
		else if (a[0][i] == a[1][i] && a[0][i] == a[2][i])
		{
			cout << "\t\t\t\twin" << endl;
			flag = false;
		}
	}
	if (a[0][0] == a[1][1] && a[0][0] == a[2][2])
	{
		cout << "\t\t\t\twin" << endl;
		flag = false;
	}
	else if (a[0][2] == a[1][1] && a[0][2] == a[2][0])
	{
		cout << "\t\t\t\twin" << endl;
		flag = false;
	}

}
