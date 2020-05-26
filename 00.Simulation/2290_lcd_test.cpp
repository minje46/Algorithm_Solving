#include<iostream>
#include<memory.h>
#include<string>

#define MAX_N 25
#define MAX_M 140

using namespace std;

char map[MAX_N][MAX_M];						// map = The memory of board to write LCD characters.

void Simulation(int s, string str)			// To figure out the LCD characters.
{
	int i, j;
	for (int k = 0; k < str.length(); k++)
	{
		int x = k * (s + 3);
		if (str[k] == '0')
		{
			for (i = 1; i < 2 * s + 2; i++)
			{
				if (i == (1 + s))
					continue;
				map[i][x] = map[i][x + s + 1] = '|';
			}
			for (j = x + 1; j < x + s + 1; j++)
				map[0][j] = map[2 * s + 2][j] = '-';
		}
		else if (str[k] == '1' || str[k] == '7')
		{
			j = x + 2 + s - 1;
			for (i = 1; i < 2 * s + 2; i++)
			{
				if (i == (1 + s))
					continue;
				map[i][j] = '|';
			}
			if (str[k] == '7')
			{
				for (j = x + 1; j < x + s + 1; j++)
					map[0][j] = '-';
			}
		}
		else if (str[k] == '2' || str[k] == '3')
		{
			j = x + 2 + s - 1;
			for (i = 1; i < 1 + s; i++)
				map[i][j] = '|';
			for (i = 1 + s + 1; i < 2 * s + 2; i++)
			{
				if (str[k] == '2')
					map[i][j - (s + 1)] = '|';
				else if (str[k] == '3')
					map[i][j] = '|';
			}
			for (j = x + 1; j < x + s + 1; j++)
				map[0][j] = map[1 + s][j] = map[2 * s + 2][j] = '-';
		}
		else if (str[k] == '4')
		{
			j = x + 2 + s - 1;
			for (i = 1; i < 1 + s; i++)
				map[i][j] = map[i][j - (s + 1)] = '|';
			for (i = 1 + s + 1; i < 2 * s + 2; i++)
				map[i][j] = '|';
			for (j = x + 1; j < x + s + 1; j++)
				map[1 + s][j] = '-';
		}
		else if (str[k] == '5' || str[k] == '6')
		{
			j = x + 2 + s - 1;
			for (i = 1; i < 1 + s; i++)
				map[i][j - (s + 1)] = '|';
			for (i = 1 + s + 1; i < 2 * s + 2; i++)
			{
				if (str[k] == '6')
					map[i][j - (s + 1)] = '|';
				map[i][j] = '|';
			}
			for (j = x + 1; j < x + s + 1; j++)
				map[0][j] = map[1 + s][j] = map[2 * s + 2][j] = '-';
		}
		else if (str[k] == '8' || str[k] == '9')
		{
			j = x + 2 + s - 1;
			for (i = 1; i < 1 + s; i++)
				map[i][j - (s + 1)] = map[i][j] = '|';
			for (i = 1 + s + 1; i < 2 * s + 2; i++)
			{
				if (str[k] == '8')
					map[i][j - (s + 1)] = '|';
				map[i][j] = '|';
			}

			for (j = x + 1; j < x + s + 1; j++)
				map[0][j] = map[1 + s][j] = map[2 * s + 2][j] = '-';
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int s;	string n;
	cin >> s >> n;
	
	memset(map, ' ', sizeof(map));
	Simulation(s, n);

	for (int i = 0; i < 2 * s + 3; i++)
	{
		for (int j = 0; j < (s + 2)*n.length() + 10; j++)
			cout << map[i][j];
		cout << endl;
	}
}