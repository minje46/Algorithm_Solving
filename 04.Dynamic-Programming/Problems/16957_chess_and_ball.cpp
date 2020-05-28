#include<iostream>
#include<memory.h>

#define MAX 500

using namespace std;

const int dy[8] = { -1,-1,-1,0,0,1,1,1 };
const int dx[8] = { -1,0,1,-1,1,-1,0,1 };

int N, M;														// N,M = The size of map.
int map[MAX][MAX];									// map = The memory of input data.
pair<int, int> cache[MAX][MAX];					// cache = The memory of memoization.

pair<int, int> DFS(int y, int x)		// To figure out location which has the minimum value.
{
	if (cache[y][x].first == y && cache[y][x].second == x)		// Base case.
	{																					// [���� ��ǥ�� ���� ���� ���� ������ ��ġ]
		map[y][x]++;
		return make_pair(y, x);			// [���� �������� ��ǥ�� return���־��, memoization�� �ȴ�]
	}
	else	// [���� ��ǥ�� �ٸ� ���� ���� ������ ��ǥ�� �̵��ؾ� ���]
		cache[y][x] = DFS(cache[y][x].first, cache[y][x].second);
}

void Simulation()			// To figure out the minimum value within adjacent area.
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int mn = map[i][j], ni = i, nj = j;
			for (int k = 0; k < 8; k++)
			{
				int ny = i + dy[k], nx = j + dx[k];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)			// Overflow.
					continue;

				if (mn > map[ny][nx])				// Update the minimum one.
					mn = map[ny][nx], ni = ny, nj = nx;
			}
			cache[i][j] = make_pair(ni, nj);	// Set the minimum coordinates from (i,j) location.
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
	memset(map, 0, sizeof(map));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			DFS(i, j);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}