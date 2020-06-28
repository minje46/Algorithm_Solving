#include<iostream>
#include<vector>

#define MAX 13

using namespace std;

const int dy[4] = { 0,0,-1,1 };
const int dx[4] = { 1,-1,0,0 };

struct info											// The data of knight.
{
	int y, x;
	int dir;
};

int N, K;												// N = The size of mpa.			K = The number of knights.
int map[MAX][MAX];							// map = The memory of input data.
vector<int> vc[MAX][MAX];					// vc = The number of knights on the board.
vector<info> knight;								// knight = The memory of knights.
int answer;											// answer = The time it takes for the game	to finish.

bool Range(int y, int x)			// To figure out the overflow or not.
{
	if (y < 0 || y >= N || x < 0 || x >= N)			// Overflow.
		return false;
	return true;
}

void White(int ny, int nx, vector<int> list)		// Move to next location with all of knights as stack.
{
	for (int i = 0; i < list.size(); i++)
	{
		vc[ny][nx].push_back(list[i]);
		knight[list[i]].y = ny;
		knight[list[i]].x = nx;
	}
}

void Red(int ny, int nx, vector<int> list)		// Move to next location with all of knights as stack.
{
	for (int i = list.size() - 1; i >= 0; i--)		// Reverse the sequence.
	{
		vc[ny][nx].push_back(list[i]);
		knight[list[i]].y = ny;
		knight[list[i]].x = nx;
	}
}

void Blue(int ny, int nx, vector<int> list, int idx)		// Move to next location with all of knights as stack.
{
	if (knight[idx].dir == 0)				// Reverse the direction.
		knight[idx].dir = 1;
	else if (knight[idx].dir == 1)
		knight[idx].dir = 0;
	else if (knight[idx].dir == 2)
		knight[idx].dir = 3;
	else if (knight[idx].dir == 3)
		knight[idx].dir = 2;

	ny += dy[knight[idx].dir], nx += dx[knight[idx].dir];
	if (!Range(ny, nx) || map[ny][nx] == 2)	// Overflow. + Blue.
	{
		ny -= dy[knight[idx].dir];		nx -= dx[knight[idx].dir];
		for (int i = 0; i < list.size(); i++)
		{
			vc[ny][nx].push_back(list[i]);
			knight[list[i]].y = ny;
			knight[list[i]].x = nx;
		}
	}
	else if (map[ny][nx] == 0)						// White.
		White(ny, nx, list);
	else if (map[ny][nx] == 1)						// Red.
		Red(ny, nx, list);
}

int Simulation()			// To move all knights with specific rules.
{
	int time = 1;
	while (time <= 1000)
	{
		for (int idx = 0; idx < K; idx++)						// The whole of kinghts.
		{
			int y = knight[idx].y, x = knight[idx].x, d = knight[idx].dir;
			vector<int>prev, stk;								// The temporary memory of knights in current coordinate.
			bool from = false;
			for (int i = 0; i < vc[y][x].size(); i++)
			{
				if (vc[y][x][i] == idx)							// From the current index's knight.			
					from = true;

				if (from)												// Going to move together.
					stk.push_back(vc[y][x][i]);
				else													//	Previous knighs keep staying.
					prev.push_back(vc[y][x][i]);
			}
			vc[y][x].clear();
			vc[y][x] = prev;

			int ny = y + dy[d], nx = x + dx[d];
			if (!Range(ny, nx) || map[ny][nx] == 2)	// Overflow. + Blue.
			{
				ny = y;	nx = x;
				Blue(ny, nx, stk, idx);
				ny = knight[idx].y, nx = knight[idx].x;
			}
			else if (map[ny][nx] == 0)						// White.
				White(ny, nx, stk);
			else if (map[ny][nx] == 1)						// Red.
				Red(ny, nx, stk);

			if (vc[ny][nx].size() >= 4)						// End condition.
				return time;
		}
		time++;
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < K; i++)
	{
		int y, x, d;
		cin >> y >> x >> d;
		knight.push_back({ y - 1,x - 1,d - 1 });
		vc[y - 1][x - 1].push_back(i);
	}

	answer = Simulation();

	cout << answer << endl;
}