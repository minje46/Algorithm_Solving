#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 11

using namespace std;

int H, W;																// H,W = The size of map.	
char map[MAX][MAX];											// map = The memory of input data.
bool visit[MAX][MAX];												// visit = The memory of visited or not.		
int R, C;																	// R,C = The size of block.
char block[4][MAX][MAX];										// block = The memory of block.
int answer;																// answer = The maximum number of blocks to put in map.

void DFS(int y, int x, int cnt)																										//
{
	for (int k = 0; k < 4; k++)
	{
		if (Check(y, x, k))		// 4 방향을 모두 체크하고 range, 방향, visit다 되면,
		{
			// for 통해서 다음 white 위치 찾아서 dfs 진행?
		}
	}
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

		answer = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == '.')
				{
					memset(visit, false, sizeof(visit));
					DFS(i, j, 0);
				}
			}
		}

		cout << answer << endl;
	}

}