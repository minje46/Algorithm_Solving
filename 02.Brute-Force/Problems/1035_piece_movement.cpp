#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<vector>

#define MAX 5

using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

char map[MAX][MAX];					// map = The memory of input data.
bool visit[MAX][MAX];						// visit = The memory of visited or not.
vector<pair<int, int>> piece;				// piece = The coordinates of piece's location.
int answer = 1e9;							// answer = The shortest distance of total movement.

bool Range(int ny, int nx)		// To figure out whether it is coreect range or not.
{
	if (ny < 0 || ny >= MAX || nx < 0 || nx >= MAX)		// Overflow.
		return false;
	return true;
}

int Distance(pair<int, int>A, pair<int, int>B)		// To calculate the distance between A and B.
{
	return abs(A.first - B.first) + abs(A.second - B.second);
}

bool BFS()		// To figure out whether all of pieces are connect or not.
{					// [BFS 반복 수 = adjacent piece 개수]	
	bool flag = false;
	queue<pair<int, int>> que;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (map[i][j] == '*')
			{
				que.push(make_pair(i, j));
				visit[i][j] = true;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	int cnt = 0;
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		cnt++;
		for (int k = 0; k < 4; k++)
		{
			int ny = cur.first + dy[k];
			int nx = cur.second + dx[k];

			if (!Range(ny, nx))
				continue;
			if (!visit[ny][nx] && map[ny][nx] == '*')
			{
				que.push(make_pair(ny, nx));
				visit[ny][nx] = true;
			}
		}
	}
	return (cnt == piece.size() ? true : false);
}

void DFS(int cnt, int dist)			// To figure out all cases of movement.
{											// [5*5의 모든 좌표에 piece를 옮겨보는 brute-force]
	if (dist > answer)		// Prunning.
		return;

	if (cnt == piece.size())		// Base case.
	{
		memset(visit, false, sizeof(visit));
		if (BFS())			// Whetehr they are adjacent or not.			
			answer = min(answer, dist);
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (map[i][j] == '.')
			{
				map[i][j] = '*';			// [5*5 모든 좌표에 차례대로 piece 배치 해보는 것]
				DFS(cnt + 1, dist + Distance(piece[cnt], { i,j }));
				map[i][j] = '.';
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int cnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				piece.push_back(make_pair(i, j)), map[i][j] = '.';
		}
	}

	DFS(0, 0);
	
	cout << answer << endl;
}