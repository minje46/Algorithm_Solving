#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 51

using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int N;													// N = The size of map.
char map[MAX][MAX];						// map = The memory of input data.
int answer = 0;									// answer = The maximum candy to take it.

int Init()		// To count the longest length with same color's candy on basic state.
{
	int mx = 0;
	for (int i = 0; i < N; i++)					// Y = (0~N) [Row]
	{
		for (int j = 0; j < N; j++)				// X = Start point.
		{
			int cnt = 1;
			for (int k = j + 1; k < N; k++)		// compare.
			{
				if (map[i][j] == map[i][k])
					cnt++;
				else
					break;
			}
			mx = max(mx, cnt);
		}
	}

	for (int i = 0; i < N; i++)					// X = (0~N) [Column]
	{
		for (int j = 0; j < N; j++)				// Y = Start point.
		{
			int cnt = 1;
			for (int k = j + 1; k < N; k++)		// compare
			{
				if (map[j][i] == map[k][i])
					cnt++;
				else
					break;
			}
			mx = max(mx, cnt);
		}
	}
	return mx;
}

int Check(int y, int x, int ny, int nx)		// To count the longest length which has same color's candy after swap.
{
	int mx = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt_a = 1, cnt_b = 1;
		for (int j = i + 1; j < N; j++)			// [Y, x]
		{
			if (map[y][i] == map[y][j])
				cnt_a++;
			else
				break;
		}
		for (int j = i + 1; j < N; j++)			// [NY, x]
		{
			if (map[ny][i] == map[ny][j])
				cnt_b++;
			else
				break;
		}
		mx = max(mx, max(cnt_a, cnt_b));
	}

	for (int i = 0; i < N; i++)
	{
		int cnt_a = 1, cnt_b = 1;
		for (int j = i + 1; j < N; j++)			// [y, X]
		{
			if (map[i][x] == map[j][x])
				cnt_a++;
			else
				break;
		}
		for (int j = i + 1; j < N; j++)			// [y, NX]	
		{
			if (map[i][nx] == map[j][nx])
				cnt_b++;
			else
				break;
		}
		mx = max(mx, max(cnt_a, cnt_b));
	}
	return mx;
}

void Simulation()				// To do 'Bomboni' game.
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)		// Overflow.
					continue;

				if (map[i][j] != map[ny][nx])
				{
					swap(map[i][j], map[ny][nx]);
					answer = max(answer, Check(i, j, ny, nx));
					swap(map[ny][nx], map[i][j]);
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	answer = Init();
	Simulation();

	cout << answer << endl;
}
