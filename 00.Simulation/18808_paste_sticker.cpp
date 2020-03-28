#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 41
#define FIGURE 11

using namespace std;

int N, M, K;											// N,M = The size of map.			K = The number of stickers.
int map[MAX][MAX];								// map = The memory of basic state.
int R, C;													// R,C = The size of stickers.
int figure[4][FIGURE][FIGURE];				// figure = The memory of each rotated stickers.	
vector<pair<int, int>> vc[4];						// vc = Each sticker's relative coordinates.
int answer = 0;										// answer = The total number of stickers put on array.

void Rotations(int k)			// To 90 degree rotate from the current sticker.
{
	int r = R, c = C;
	if (k % 2 == 0)			// [직사각형의 경우, (r,c)가 90도 회전하면 (c,r)로 바뀌어야 한다.]
		swap(r, c);
	for (int i = 0; i < r; i++)
	{								// [이전 sticker의 column 순서를 현재 sticker의 row 순서로 회전.]
		for (int j = 0; j < c; j++)
			figure[k][j][r - i - 1] = figure[k - 1][i][j];
	}
}

void Rotated_coordinates()			// To figure out the relative sticker's coordinate.
{
	for (int k = 0; k < 4; k++)
	{
		vc[k].clear();
		int y = -1, x = -1;
		for (int i = 0; i < FIGURE; i++)
		{
			for (int j = 0; j < FIGURE; j++)
			{
				if (figure[k][i][j] == 1)
				{
					if (y == -1)
					{
						y = i;
						x = j;
					}							// [상대 주소를 저장하기 위함.]
					vc[k].push_back(make_pair(i - y, j - x));
				}
			}
		}
	}
}

bool Convert(int y, int x, int k, int val)			// To attach or detach the block on the map.
{
	bool flag = true;
	for (int r = 0; r < vc[k].size(); r++)
	{
		int ny = y + vc[k][r].first;
		int nx = x + vc[k][r].second;

		if (ny >= 0 && ny < N && nx >= 0 && nx < M)		// In range.
		{
			map[ny][nx] += val;									// Attach or Detach.		
			flag = flag && (map[ny][nx] == 1);				// The sticker is only attached on empty space on array.		
		}
		else
			flag = false;
	}
	return flag;
}

void Simulation()			// To figure out whether the sticker is possible to put on or not.
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
					continue;

				if (Convert(i, j, k, 1))
				{
					answer += vc[k].size();
					return;
				}
				Convert(i, j, k, -1);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M >> K;
	for (int k = 0; k < K; k++)
	{
		memset(figure, 0, sizeof(figure));
		cin >> R >> C;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				cin >> figure[0][i][j];
		}

		for (int i = 1; i < 4; i++)
			Rotations(i);
		Rotated_coordinates();
		Simulation();
	}

	cout << answer << endl;
}