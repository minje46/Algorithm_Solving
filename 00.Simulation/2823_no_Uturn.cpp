#include<iostream>

#define MAX 11

using namespace std;

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,-1,0,1 };

int N, M;												// N, M = The size of map.
char map[MAX][MAX];						// map = The memory of input data.
bool answer;										// answer = Whether it could return without U-Turn or not.

bool Simulation()				// To figure out it has cycle or not.
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'X')					// Wall.	
				continue;

			int cnt = 0;								// cnt = The number of roads to move.
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;						// Overflow.

				if (map[ny][nx] == '.')			// Empty space.
					cnt++;
			}

			if (cnt <= 1)							// No way or U-Turn.
				return true;							// Cycle exists.
		}
	}
	return false;									// No cycle = No U-Turn.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	answer = Simulation();

	cout << answer << endl;
}