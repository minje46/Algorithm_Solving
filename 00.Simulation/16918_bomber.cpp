#include<iostream>
#include<queue>

#define MAX 201

using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int N, M, T;										// N,M = The size of map.				T = The target time.
int map[MAX][MAX];						// map = The memory of input data.

void Count_down()			// To decrease the bomb's time.
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] > 0)
				map[i][j]--;
	}
}

void Bomb(queue<pair<int, int>>que)		// To do bomb with adjacent spaces.
{
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		for (int k = 0; k < 4; k++)
		{
			int ny = cur.first + dy[k];
			int nx = cur.second + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)			// Overflow.
				continue;

			map[ny][nx] = 0;
		}
	}
}

void Simulation()			// Do simulation.
{
	int time = 2;
	while (time <= T)
	{
		Count_down();		

		if (time % 2 == 1)		// In odd time, some bombs are going to bomb.
		{
			queue<pair<int, int>>que;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (map[i][j] <= 1)
					{
						map[i][j] = 0;
						que.push(make_pair(i, j));
					}
				}
			}
			Bomb(que);
		}
		else							// In even time, bombs are going to be installed.	
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (map[i][j] == 0)
						map[i][j] = 3;
				}
			}
		}
		time++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '.')				// Empty
				map[i][j] = 0;
			else							// Bomb
				map[i][j] = 3;
		}
	}

	Simulation();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)		// Empty
				cout << '.';
			else							// Bomb	
				cout << 'O';
		}
		cout << endl;
	}
}