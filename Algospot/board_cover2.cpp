#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 11

using namespace std;

int H, W;																// H,W = The size of map.	
char map[MAX][MAX];											// map = The memory of input data.	
int R, C;																	// R,C = The size of block.
char block[4][MAX][MAX];										// block = The memory of block.
vector<vector<pair<int, int>>> vc;								// vc = The memory of each block's relative coordinates.
int empty_space, block_size;									// empty_space = The total number of empty space.
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
	block_size = vc[0].size();
}

pair<int, int> Coordinate(int y, int x)			// To figure out the next empty space's coordinate.
{
	for (int i = y; i < H; i++)
	{
		for (int j = x + 1; j < W; j++)
		{
			if (map[i][j] == '.')
				return make_pair(i, j);
		}
		x = -1;
	}
	return make_pair(-1, -1);
}

bool Check(int y, int x, int k)				// To check whetehr it is possible to put block on or not.
{
	for (int r = 0; r < vc[k].size(); r++)
	{
		int ny = y + vc[k][r].first;
		int nx = x + vc[k][r].second;

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)			// Overflow.
			return false;

		if (map[ny][nx] == '#')									// The wall already exists.
			return false;
	}
	return true;
}

void Convert(int y, int x, int k, bool flag)			// To attach or detach the block on the map.
{
	for (int r = 0; r < vc[k].size(); r++)
	{
		int ny = y + vc[k][r].first;
		int nx = x + vc[k][r].second;

		if (!flag)					// Detach condition.		
			map[ny][nx] = '.';
		else						// Attach condition.
			map[ny][nx] = '#';
	}
}

void DFS(int y, int x, int cnt)			// To figure out the maximum blocks to put on.
{
	if (empty_space / block_size + cnt < answer)		// Prunning.
		return;														// [남은 empty space를 모두 block으로 채워도, answer보다 작다면 가지치기.]

	pair<int, int> pr = Coordinate(y, x);
	if (pr.first == -1 && pr.second == -1)				// Base case.
	{																	// [No more empty space to check.]
		answer = max(answer, cnt);
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		if (Check(pr.first, pr.second, k))					// Whether it is possible to put block on or not.
		{
			Convert(pr.first, pr.second, k, true);			// Put the current block on.
			empty_space -= block_size;						// Decrease the number of empty spcae.
			DFS(pr.first, pr.second, cnt + 1);				// Exhaustive search.
			empty_space += block_size;
			Convert(pr.first, pr.second, k, false);
		}
	}
	DFS(pr.first, pr.second, cnt);							// Exhaustive search.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		empty_space = answer = 0;
		vc.clear();

		cin >> H >> W >> R >> C;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
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

		DFS(0, 0, 0);

		cout << answer << endl;
	}
}