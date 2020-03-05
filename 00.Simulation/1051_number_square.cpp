#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 51

using namespace std;

const int dy[4] = { 0,0,1,1 };
const int dx[4] = { 0,1,1,0 };

int N, M;													// N = The height of map.			M = The width of map.
char map[MAX][MAX];							// map = The memory of input data.
int answer = 1;										// answer = The maximum area of square.

bool Range(int y, int x, int k)				// To figure out whether it has correct range or not.
{
	for (int d = 0; d < 4; d++)
	{
		int ny = y + (k*dy[d]);
		int nx = x + (k*dx[d]);
		
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)			// Overflow.
			return false;
	}
	return true;
}

bool Check(int y, int x, int k)				// To figure out whether it has same value in each vertex.
{
	for (int d = 0; d < 4; d++)
	{
		int ny = y + (k*dy[d]);
		int nx = x + (k*dx[d]);

		if (map[ny][nx] != map[y][x])							// Same vertex value.
			return false;
	}
	return true;
}

void Simulation()				// To figure out the whole of coordinate with conditions.
{
	int len = min(N, M);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 1; k < len; k++)
			{
				if (!Range(i, j, k))				// Overflow.
					continue;

				if (Check(i, j, k))					// Same vertex value.
					answer = max(answer, (int)pow(k + 1, 2));
			}
		}
	}
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

	Simulation();

	cout << answer << endl;
}