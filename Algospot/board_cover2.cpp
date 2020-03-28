#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 11

using namespace std;

int H, W;																// H,W = The size of map.	
char map[MAX][MAX];											// map = The memory of input data.	
int R, C;																	// R,C = The size of block.
char block[4][MAX][MAX];										// block = The memory of block.
int answer;																// answer = The maximum number of blocks to put in map.

void Rotation_90()
{
	int y = 0, x = 0;
	int r = C, c = R;
	for (int i = c - 1; i >= 0; i--)
	{
		for (int j = 0; j < r; j++)
			block[1][j][i] = block[0][y][x++];
		y++;
		x = 0;
	}
}

void Rotation_180()
{
	int y = C - 1, x = 0;
	int r = R, c = C;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			block[2][i][j] = block[1][y--][x];
		y = C - 1;
		x++;
	}
}

void Rotation_270()
{
	int y = 0, x = 0;
	int r = C, c = R;
	for (int i = c - 1; i >= 0; i--)
	{
		for (int j = 0; j < r; j++)
			block[3][j][i] = block[2][y][x++];
		y++;
		x = 0;
	}
}

pair<int, int> Coordinate(int y, int x)
{
	for (int i = y; i < H; i++)
	{
		for (int j = x + 1; j < W; j++)
		{
			if (map[i][j] == '.')
				return make_pair(i, j);
		}
		x = 0;
	}
	return make_pair(-1, -1);
}

bool Check(int y, int x, int k)
{
	int r = R, c = C;
	if (k % 2 == 1)
		swap(r, c);

	for (int i = 0; i < r; i++)
	{
		int ny = y + i;
		for (int j = 0; j < c; j++)
		{
			int nx = x + j;
			if (block[k][i][j] == '#')
			{
				if (ny < 0 || ny >= H || nx < 0 || nx >= W)			// Overflow.
					return false;

				if (map[ny][nx] == '#')									// Wall exists.	
					return false;
			}
		}
	}
	return true;
}

void Convert(int y, int x, int k)
{
	int r = R, c = C;
	if (k % 2 == 1)
		swap(r, c);

	for (int i = 0; i < r; i++)
	{
		int ny = y + i;
		for (int j = 0; j < c; j++)
		{
			int nx = x + j;
			if (ny < 0 || ny >= H || nx < 0 || nx >= W)			// Overflow.
				continue;

			if (k == -1)
				map[ny][nx] = '.';
			else
			{
				if (block[k][i][j] == '#')
					map[ny][nx] = block[k][i][j];
			}
		}
	}
}

void DFS(int y, int x, int cnt)
{
	answer = max(answer, cnt);
	pair<int, int> pr = Coordinate(y, x);
	if (pr.first == -1 && pr.second == -1)
		return;

	for (int k = 0; k < 4; k++)
	{
		if (Check(pr.first, pr.second, k))		// 4 방향을 모두 체크하고 range, 방향, visit다 되면,
		{
			Convert(pr.first, pr.second, k);
			DFS(pr.first, pr.second, cnt + 1);
			Convert(pr.first, pr.second, -1);
		}
	}
	DFS(pr.first, pr.second, cnt);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> H >> W >> R >> C;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				cin >> map[i][j];
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				cin >> block[0][i][j];
		}

		Rotation_90();
		Rotation_180();
		Rotation_270();

		answer = 0;
		DFS(0, 0, 0);

		cout << answer << endl;
	}
}