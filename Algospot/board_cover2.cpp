#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 11

using namespace std;

int H, W;																// H,W = The size of map.	
char map[MAX][MAX];											// map = The memory of input data.
int board[MAX][MAX];												// board = The memory of map to deal with easily.
int R, C;																	// R,C = The size of block.
char block[4][MAX][MAX];										// block = The memory of block.
vector<vector<pair<int, int>>> vc;								// vc = The memory of each block's relative coordinates.
int empty_space, block_size;									// The size of empty space and block size.
int answer;																// answer = The maximum number of blocks to put in map.

void Rotations(int k)				// To 90 degree rotate from the current blcok.
{
	int r = R, c = C;
	if (k % 2 == 0)								// [직사각형의 경우, (r,c)가 90도 회전하면 (c,r)로 바뀌어야 한다.]
		swap(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)					// [이전 block의 column 순서를 현재 block의 row 순서로 회전.]
			block[k][j][r - i - 1] = block[k - 1][i][j];
	}
}

void Rotated_coordinates()			// To figure out the relative block's coordinate.
{
	vc.clear();
	vc.resize(4);
	for (int k = 0; k < 4; k++)
	{
		int y = -1, x = -1;
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (block[k][i][j] == '#')
				{
					if (y == -1)
					{
						y = i;
						x = j;
					}
					vc[k].push_back(make_pair(i - y, j - x));
				}
			}
		}
	}
	sort(vc.begin(), vc.end());										// To delete duplicated blocks.
	vc.erase(unique(vc.begin(), vc.end()), vc.end());		// [Block 회전 후에 동일한 모양인 것들 delete.]	
	block_size = vc[0].size();											// The size of blocks.
}

bool Convert(int y, int x, int k, int flag)			// To attach or detach the block on the map.
{
	bool res = true;
	for (int r = 0; r < vc[k].size(); r++)
	{
		int ny = y + vc[k][r].first;
		int nx = x + vc[k][r].second;

		if (ny >= 0 && ny < H && nx >= 0 && nx < W)		// In range.
		{
			board[ny][nx] += flag;
			res = res && (board[ny][nx] == 1);
		}
		else
			res = false;
	}
	return res;
}

void DFS(int cnt)			// To figure out the maximum blocks to put on.
{
	if (empty_space / block_size + cnt <= answer)		// Prunning.
		return;				// [남은 empty space를 모두 block으로 채워도, answer보다 작다면 가지치기.]

	int y = -1, x = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}

	if (y == -1)								// Base case.
	{											// [No more empty space to check.]
		answer = max(answer, cnt);
		return;
	}

	for (int k = 0; k < vc.size(); k++)
	{
		if (Convert(y, x, k, 1))			// Whether it is possible to put block on or not.
		{
			empty_space -= block_size;
			DFS(cnt + 1);					// Exhaustive search.
			empty_space += block_size;
		}
		Convert(y, x, k, -1);
	}
	
	board[y][x] = 1;		empty_space--;
	DFS(cnt);								// Treat as wall exists simliar as visit[][].
	board[y][x] = 0;		empty_space++;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(block, ' ', sizeof(block));
		empty_space = block_size = answer = 0;

		cin >> H >> W >> R >> C;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				board[i][j] = (map[i][j] == '#' ? 1 : 0);
				if (map[i][j] == '.')
					empty_space++;
			}
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				cin >> block[0][i][j];
		}

		for (int k = 1; k < 4; k++)
			Rotations(k);
		Rotated_coordinates();

		DFS(0);
		cout << answer << endl;
	}
}