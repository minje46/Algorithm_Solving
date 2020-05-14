#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>

#define MAX 5

using namespace std;

const int dz[6] = { -1,1,0,0,0,0 };		// [0] : Go up.		[1] : Go down.		-> Floor moving.
const int dy[6] = { 0,0,-1,1,0,0 };		// [2] : Go up.		[3] : Go down.		-> Plane moving.
const int dx[6] = { 0,0,0,0,-1,1 };		// [4] : Go left.		[5] : Go rihgt.			-> Plane moving.

struct info
{
	int z, y, x;
	int cnt;
};

int map[MAX][4][MAX][MAX];						// map = The memory of input data with rotated as well.
int maze[MAX][MAX][MAX];							// maze = The memory of all case's maze.
bool visit[MAX][MAX][MAX];							// visit = The memory of visited maze or not.
int answer = 1e9;											// answer = The shortest way to escape.

void Rotation(int idx)		// To rotate the map with 90, 180, 270 degree.
{
	for (int k = 1; k < 4; k++)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				map[idx][k][j][MAX - i - 1] = map[idx][k - 1][i][j];
		}
	}
}

void Set_maze(int idx, int k, int r)		// To set the maze.
{													// [idx 층의 미로를 k번째 + r방향의 map으로 set]
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			maze[idx][i][j] = map[k][r][i][j];
	}
}

int BFS()		// To figure out the shortest way to arrive at destination.
{
	queue<info>que;
	que.push({ 0,0,0,0 });
	visit[0][0][0] = true;
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		if (cur.z == 4 && cur.y == 4 && cur.x == 4)			// End condition.
			return cur.cnt;												// [Destination]

		for (int k = 0; k < 6; k++)
		{
			int nz = cur.z + dz[k];
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];

			if (nz < 0 || nz >= MAX || ny < 0 || ny >= MAX || nx < 0 || nx >= MAX)		// Overflow.
				continue;

			if (!visit[nz][ny][nx] && maze[nz][ny][nx] == 1)			// Not visit yet + empty space
			{
				que.push({ nz,ny,nx,cur.cnt + 1 });
				visit[nz][ny][nx] = true;
			}
		}
	}
	return 1e9;
}

void Simulation()		// To set permutation's map with duplicated permutation's rotation maze and escape cases.
{
	int arr[MAX];			// arr = The memory of permutation.	
	for (int i = 0; i < MAX; i++)
		arr[i] = i;			// permuation -> [5개의 판을 쌓기 위한 순서를 저장하기 위한 array]

	do
	{							// [정해진 순서의 판을 4방향 회전 모두 돌려가며 maze를 만들기 위함]				
		for (int a = 0; a < 4; a++)		
		{						// Each floor with four directions.
			Set_maze(0, arr[0], a);
			for (int b = 0; b < 4; b++)
			{
				Set_maze(1, arr[1], b);
				for (int c = 0; c < 4; c++)
				{
					Set_maze(2, arr[2], c);
					for (int d = 0; d < 4; d++)
					{
						Set_maze(3, arr[3], d);
						for (int e = 0; e < 4; e++)
						{
							Set_maze(4, arr[4], e);	
							if (maze[0][0][0] == 0 || maze[4][4][4] == 0)		// Impossible case to escape.
								continue;

							memset(visit, false, sizeof(visit));
							answer = min(answer, BFS());
						}
					}
				}
			}
		}
	} while (next_permutation(arr, arr + MAX));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	for (int k = 0; k < MAX; k++)				// [0~4번 까지의 초기 map]
	{
		for (int i = 0; i < MAX; i++)			
		{
			for (int j = 0; j < MAX; j++)
			{
				cin >> map[k][0][i][j];		// [k][0] : Not rotated initial map.
				Rotation(k);						
			}
		}
	}

	Simulation();

	if (answer == 1e9)			// Exception.
		answer = -1;
	cout << answer << endl;
}