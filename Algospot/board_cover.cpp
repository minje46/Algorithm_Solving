#include<iostream>
#include<memory.h>

#define MAX 51

using namespace std;
											// r,ㄴ,ㄱ, ~ㄴ		
const int dir[4][2][2] = { {{0,1},{1,0}},{ { 1,0 },{ 1,1 } },{ { 0,1 },{ 1,1 } },{ { 1,0 },{ 1,-1 } } };

int H, W;								// H = The height of map.					W = The width of map.
char map[MAX][MAX];			// map = The memory of input data.
int answer;								// answer = The number of possible cases as ouput.

bool Range(int ny, int nx)			// To check whether (ny,nx) is correct location or not.
{											// Overflow.
	if (ny < 0 || ny >= H || nx < 0 || nx >= W)	
		return false;
	return true;
}

void Convert(int idx, int y, int x, char type)			// To convert specific location as fixed character.
{
	map[y][x] = type;
	for (int i = 0; i < 2; i++)
	{
		int ny = y + dir[idx][i][0];
		int nx = x + dir[idx][i][1];

		map[ny][nx] = type;
	}
}

void DFS(int y, int x)		// To figure out whether block cover is possible or not.
{			
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == '.')			// White space.
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)							// Search succeeded.
			break;
	}

	if (y == -1 && x == -1)			// All of map was blocked.
	{											// [White space를 찾지 못했다는 것은, 모두 board cover된 것.]
		answer++;
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		bool flag = true;
		for (int i = 0; i < 2; i++)
		{
			int ny = y + dir[k][i][0];
			int nx = x + dir[k][i][1];

			if (!Range(ny, nx) || map[ny][nx] == '#')
			{
				flag = false;
				break;
			}
		}

		if (!flag)						// Impossilbe figure.
			continue;
		
		Convert(k, y, x, '#');
		DFS(-1, -1);				// [(y,x)는 DFS() 시작하면서, seraching이 이루어지기 때문에, -1로 초기화.]
		Convert(k, y, x, '.');
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(map, ' ', sizeof(map));
		answer = 0;

		cin >> H >> W;
		int cnt = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '.')			// cnt = The number of white spaces.
					cnt++;
			}
		}

		if (cnt % 3 == 0)						// [white spaces는 3의 배수 공간이 존재해야, board cover가 가능.]
			DFS(-1, -1);
	
		cout << answer << endl;
	}
}