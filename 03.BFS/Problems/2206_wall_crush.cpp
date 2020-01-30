#include<iostream>
#include<memory.h>
#include<queue>

#define MAX 1001

using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

struct Location						// Location = The memory for queue.
{
	int y, x;								// Coordinates.
	bool crush;							// Wall crush.
};

int N, M;									// N = The height of mpa.				M = The width of map.
char map[MAX][MAX];			// map = The memory of input data.
int dist[2][MAX][MAX];			// dist = The memory of how far the distance is.
int answer;								// answer = The shortest way to arrive as output.

int BFS()			// To figure out the shortest way to arrived at destination.	
{
	queue<Location> que;			// Base state.
	que.push({ 0,0,false });
	dist[0][0][0] = 1;
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		if (cur.y == N - 1 && cur.x == M - 1)						// Destination.
			return dist[cur.crush][cur.y][cur.x];

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || dist[cur.crush][ny][nx])			// Overflow.
				continue;
			// [Wall crush를 구분해서 dist[]로 저장하고 있기 때문에, 최단거리가 update되는 경우는 고려 X.]
			if (map[ny][nx] == '0')							// Not visit yet. + Empty space.
			{
				que.push({ ny,nx, cur.crush });
				dist[cur.crush][ny][nx] = dist[cur.crush][cur.y][cur.x] + 1;
			}

			if (map[ny][nx] == '1' && !cur.crush)		// Wall. + Possible crush.		
			{
				que.push({ ny,nx, !cur.crush });
				dist[!cur.crush][ny][nx] = dist[cur.crush][cur.y][cur.x] + 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	memset(dist, 0, sizeof(dist));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	answer = BFS();

	cout << answer << endl;
}