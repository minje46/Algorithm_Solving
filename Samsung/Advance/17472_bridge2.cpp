#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<vector>

#define MAX 11
#define INF 987654321

using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

struct info
{
	pair<int, int> dpt, dst;
	int cnt;
};

int N, M, idx;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> island[7];
vector<info>bridge;
bool used[MAX*MAX];
vector<int> node[7];
bool check[7];
int answer = INF;

bool Range(int ny, int nx)
{
	if (ny < 0 || ny >= N || nx < 0 || nx >= M)
		return false;
	return true;
}

void BFS(int y, int x, int num)
{
	queue<pair<int, int>>que;
	que.push(make_pair(y, x));
	visit[y][x] = true;	map[y][x] = num;		island[num].push_back(make_pair(y, x));
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		for (int k = 0; k < 4; k++)
		{
			int ny = cur.first + dy[k];
			int nx = cur.second + dx[k];

			if (!Range(ny, nx))
				continue;

			if (!visit[ny][nx] && map[ny][nx] == 1)
			{
				que.push(make_pair(ny, nx));
				visit[ny][nx] = true;		map[ny][nx] = num;	island[num].push_back(make_pair(ny, nx));
			}
		}
	}
}

bool Find(pair<int, int> start, pair<int, int> end)		// To figure out the same bridge is or not.
{
	for (int i = 0; i < bridge.size(); i++)
	{
		if (bridge[i].dpt == end && bridge[i].dst == start)		// [a->b] == [b->a] are same bridge.
			return false;														// That's why compare (dpt, end) and (dst, start).
	}
	return true;
}

void Build_bridge()
{
	for (int i = 1; i < idx; i++)
	{
		for (int j = 0; j < island[i].size(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = island[i][j].first, nx = island[i][j].second, cnt = 0, buf = 1;
				while (true)
				{
					ny += dy[k];		nx += dx[k];
					if (!Range(ny, nx) || map[ny][nx] == i)
					{
						buf = -1;
						break;
					}
					if (map[ny][nx] > 0 && map[ny][nx] != i)
						break;
					cnt++;
				}
				if (buf == 1 && cnt >= 2 && Find({ island[i][j].first, island[i][j].second }, { ny,nx }))
					bridge.push_back({ {island[i][j].first, island[i][j].second}, {ny,nx}, cnt });
			}
		}
	}
}

int Count()		// To count the total length of bridges.
{
	int tot = 0;
	for (int i = 0; i < bridge.size(); i++)
	{
		if (used[i])			// Consider the used bridge only.
			tot += bridge[i].cnt;
	}
	return tot;
}

void DFS(int cur)
{
	if (check[cur])
		return;

	check[cur] = true;
	for (int i = 0; i < bridge.size(); i++)
	{
		if (used[i])
		{
			int dpt = map[bridge[i].dpt.first][bridge[i].dpt.second];
			int dst = map[bridge[i].dst.first][bridge[i].dst.second];
			if (cur == dpt)
				DFS(dst);
			if (cur == dst)
				DFS(dpt);
		}
	}
}

int Simulation()
{
	for (int i = 1; i < idx; i++)
	{
		memset(check, false, sizeof(check));
		DFS(i);
		for (int j = 1; j < idx; j++)
		{
			if (!check[j])
				return false;
		}
	}
	return true;
}

void Select(int idx, int cnt)
{
	if (cnt > bridge.size())
		return;

	if (Simulation())
	{
		answer = min(answer, Count());
		return;
	}

	for (int k = idx; k < bridge.size(); k++)
	{
		if (!used[k])
		{
			used[k] = true;
			Select(k, cnt + 1);
			used[k] = false;
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

	idx = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
				BFS(i, j, idx++);
		}
	}

	Build_bridge();
	Select(0, 0);

	if (answer == INF)
		answer = -1;
	cout << answer << endl;
}