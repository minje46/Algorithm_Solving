#include <iostream>
using namespace std;

char map[30000][30];

int R, C;

struct parameter
{
	int col[30000];
	int r;

}P[30];

void go(int c)
{
	while (1)
	{
		int col = P[c].col[P[c].r - 1];

		if (P[c].r > 1 && map[P[c].r - 1][col] != '.')
		{
			P[c].r--; continue;
		}

		if (P[c].r == R || map[P[c].r][col] == 'X')  break;
		else if (map[P[c].r][col] == '.')
			P[c].col[P[c].r++] = col;
		else
		{
			if (col > 0 && map[P[c].r][col - 1] == '.' && map[P[c].r - 1][col - 1] == '.')
				P[c].col[P[c].r++] = col - 1;
			else if (col + 1 < C && map[P[c].r][col + 1] == '.' && map[P[c].r - 1][col + 1] == '.')
				P[c].col[P[c].r++] = col + 1;
			else
				break;
		}

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < C; i++)
	{
		P[i].col[0] = i;
		P[i].r = 1;
		go(i);
	}

	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		int col; cin >> col; col--;

		map[P[col].r - 1][P[col].col[P[col].r - 1]] = 'O';

		for (int j = 0; j < C; j++)
			go(j);
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << map[i][j];
		cout << "\n";
	}

}