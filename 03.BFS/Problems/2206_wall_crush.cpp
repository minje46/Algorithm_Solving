#include<iostream>
#include<memory.h>
#include<queue>

#define MAX 1001
#define INF 987654321

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

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)			// Overflow.
				continue;

			if (!dist[cur.crush][ny][nx] && map[ny][nx] == '0')		// Not visit yet. + Empty space.
			{																	// [Empty space인 경우에는, bfs로 방문한 것 자체가 최단거리.]
				que.push({ ny,nx, cur.crush });
				dist[cur.crush][ny][nx] = dist[cur.crush][cur.y][cur.x] + 1;
			}

			if (map[ny][nx] == '1' && !cur.crush)				// Wall. + Possible crush.		
			{																	// [Wall인 경우에는, 이미 방문했을 수가 없기 때문에 고려X.]
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