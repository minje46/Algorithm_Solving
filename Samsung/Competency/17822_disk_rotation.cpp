#include<iostream>
#include<memory.h>
#include<queue>

#define MAX 51

using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int N, M, T;														// N,M = The size of map.			T = The number of rotation.
int map[MAX][MAX];										// map = The memory of input data.
bool visit[MAX][MAX];										// visit = The memory of visited or not.
int answer;														// answer = The total value in array.

void Rotation(int idx, int dir, int k)			// To rotate index's disk with direction(CW, CCW).
{		
	if (dir == 1)							// CCW.					
		k *= -1;
	int dpt = k + M + 1;				// Start point.
	if (dpt > M)							// Overflow.
		dpt -= M;
	else if (dpt < 1)					// Underflow.
		dpt += M;
	for (int i = 1; i <= N; i++)
	{
		if (i < 2 || i % idx != 0)				// Only index's disk.
			continue;
		
		queue<int>que;
		for (int j = 1; j <= M; j++)
			que.push(map[i][j]);
		
		int x = dpt;									// Start point is always same.
		while (!que.empty())
		{
			map[i][x++] = que.front();
			que.pop();
			if (x > M)								// Overflow.	
				x = 1;
		}
	}
}

void Duplication()			// To figure out the duplicated value which has same value around four directions.
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k < 4; k++)					// Four directions.
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				
				if (ny <= 0 || ny > N)					// First disk and Last disk.
					continue;
				else if (nx <= 0)							// Underflow.
					nx = M;
				else if (nx > M)							// Overflow.
					nx = 1;

				if (map[i][j] != 0 && map[i][j] == map[ny][nx])		// Duplication.
				{													
					visit[i][j] = true;
					visit[ny][nx] = true;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visit[i][j])									// Convert as zero.
				map[i][j] = 0;
		}
	}
}

bool Check()			// To figure out whether it has duplication or not.		
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			if (visit[i][j] == true)
				return true;
	}
	return false;
}

void Arrange()
{
	int cnt = 0, tot = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] != 0)
			{
				cnt++;
				tot += map[i][j];
			}
		}
	}

	double avg = (double)tot / cnt;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 0)
				continue;
			else if (map[i][j] > avg)
				map[i][j] -= 1;
			else if (map[i][j] < avg)
				map[i][j] += 1;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}

	int idx, dir, k;			// idx = The index of disk.		dir = The direction to rotate.			k = The distance to move.
	while (T--)
	{
		cin >> idx >> dir >> k;
		Rotation(idx, dir, k);
		memset(visit, false, sizeof(visit));
		Duplication();
		if (!Check())
			Arrange();
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] != 0)
				answer += map[i][j];
		}
	}
	cout << answer << endl;
}