#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 101

using namespace std;

int N, M, R;						// N = The height of map.		M = The width of map.			R = The number of rotations.
int map[MAX][MAX];			// map = The memory of input data.
vector<int> rotation;			// rotation = The memory of rotation data.

void Up_Down()			// To reverse the array from top-bottom to bottom-top.
{
	int tmp[MAX][MAX];
	memcpy(tmp, map, sizeof(map));
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
			map[i][j] = tmp[N - 1 - i][j];
	}
}

void Left_Right()			// To reverse the array from left-right to right-left.
{
	int tmp[MAX][MAX];
	memcpy(tmp, map, sizeof(map));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			map[i][j] = tmp[i][M - j - 1];
	}
}

void Right_rotation()	// To rotate the array in right way.
{
	int tmp[MAX][MAX];
	memcpy(tmp, map, sizeof(map));
	memset(map, 0, sizeof(map));
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
			map[i][j] = tmp[N - j - 1][i];
	}
	swap(N, M);
}

void Left_rotation()		// To rotate the array in left way.
{
	int tmp[MAX][MAX];
	memcpy(tmp, map, sizeof(map));
	memset(map, 0, sizeof(map));
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
			map[i][j] = tmp[j][M - i - 1];
	}
	swap(N, M);
}

void CW()					// To rotate the array in clock wise.
{
	int tmp[MAX][MAX];
	memcpy(tmp, map, sizeof(map));
	int n = N / 2, m = M / 2;
	for (int i = 0; i < n; i++)			// Area #1.
	{
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[n + i][j];
	}
	for (int i = 0; i < n; i++)			// Area #2.
	{
		for (int j = m; j < M; j++)
			map[i][j] = tmp[i][j - m];
	}
	for (int i = n; i < N; i++)			// Area #3.
	{
		for (int j = m; j < M; j++)
			map[i][j] = tmp[i - n][j];
	}
	for (int i = n; i < N; i++)			// Area #4.
	{
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[i][m + j];
	}
}

void CCW()					// To rotate the array in counter clock wise.
{
	int tmp[MAX][MAX];
	memcpy(tmp, map, sizeof(map));
	int n = N / 2, m = M / 2;
	for (int i = 0; i < n; i++)			// Area #1.
	{
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[i][m + j];
	}
	for (int i = 0; i < n; i++)			// Area #2.
	{
		for (int j = m; j < M; j++)
			map[i][j] = tmp[n + i][j];
	}
	for (int i = n; i < N; i++)			// Area #3.
	{
		for (int j = m; j < M; j++)
			map[i][j] = tmp[i][j - m];
	}
	for (int i = n; i < N; i++)			// Area #4.
	{
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[i - n][j];
	}
}

void Simulation()
{
	for (int i = 0; i < R; i++)
	{
		switch (rotation[i])
		{
		case 1:
			Up_Down();
			break;
		case 2:
			Left_Right();
			break;
		case 3:
			Right_rotation();
			break;
		case 4:
			Left_rotation();
			break;
		case 5:
			CW();
			break;
		case 6:
			CCW();
			break;
		default:
			break;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < R; i++)
	{
		int num;
		cin >> num;
		rotation.push_back(num);
	}

	Simulation();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
				cout << map[i][j] << " ";
			cout << endl;
	}
}