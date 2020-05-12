#include<iostream>
#include<memory.h>

#define MAX 501

using namespace std;

int N, M;															// N, M = The size of map.
char map[MAX][MAX];									// map = The memory of input data.	
int visit[MAX][MAX];										// visit = The memory of visited or not as memoization.
int answer = 0;												// answer = The total number of ways to escape.

pair<int, int> Moved(int y, int x)			// To move next location with direction.
{
	char dir = map[y][x];
	if (dir == 'U')
		return make_pair(y - 1, x);
	else if (dir == 'D')
		return make_pair(y + 1, x);
	else if (dir == 'L')
		return make_pair(y, x - 1);
	else if (dir == 'R')
		return make_pair(y, x + 1);
}

int DFS(int y, int x)		// To figure out the way whether it could escape or not.
{
	if (y < 0 || y >= N || x < 0 || x >= M)		// Base case.
		return 1;

	if (visit[y][x] != -1)			// Exception.
		return visit[y][x];		// [Memoization]

	visit[y][x] = 0;
	pair<int, int> pr = Moved(y, x);					// Next position.
	visit[y][x] = DFS(pr.first, pr.second);		// [0 ¶Ç´Â 1ÀÌ return]

	return visit[y][x];
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

	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == -1)
				DFS(i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 1)
				answer++;
		}
	}
	cout << answer << endl;
}