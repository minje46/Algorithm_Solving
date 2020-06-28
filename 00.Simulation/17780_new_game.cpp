#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 15

using namespace std;

const int dy[5] = { 0,0,0,-1,1 };
const int dx[5] = { 0,1,-1,0,0 };

struct info											// The data of knight.
{
	int y, x, dir;
};

int N, K;												// N = The size of mpa.			K = The number of knights.
int board[MAX][MAX];							// board = The memory of input data.	
vector<int>map[MAX][MAX];				// map = The number of knights on the board.
vector<info> knight;								// knight = The memory of knights.
int answer;											// answer = The time it takes for the game	to finish.

bool Range(int ny, int nx)			// To figure out whether it is correct range or not.
{
	if (ny<1 || ny>N || nx<1 || nx>N)		// Overflow.
		return false;
	return true;
}

void White(int ny, int nx, vector<int> vc)			// Move to next location with all of knights as stack.
{
	for (int i = 0; i < vc.size(); i++)
	{
		int d = knight[vc[i]].dir;
		knight[vc[i]] = { ny,nx,d };
		map[ny][nx].push_back(vc[i]);
	}
}

void Red(int ny, int nx, vector<int> vc)			// Move to next location with all of knights as stack.
{
	reverse(vc.begin(), vc.end());		// In reverse way.			
	for (int i = 0; i < vc.size(); i++)
	{
		int d = knight[vc[i]].dir;
		knight[vc[i]] = { ny,nx,d };
		map[ny][nx].push_back(vc[i]);
	}
}

void Blue(int y, int x, vector<int> vc)				// Move to next location with all of knights as stack.
{
	int d = knight[vc[0]].dir;				// In opposite direction.
	if (d == 1)
		d = 2;
	else if (d == 2)
		d = 1;
	else if (d == 3)
		d = 4;
	else if (d == 4)
		d = 3;

	knight[vc[0]].dir = d;
	int ny = y + dy[d], nx = x + dx[d];
	if (!Range(ny, nx) || board[ny][nx] == 2)
		map[y][x] = vc;
	else if (board[ny][nx] == 0)
		White(ny, nx, vc);
	else if (board[ny][nx] == 1)
		Red(ny, nx, vc);
}

int Simulation()			// To move all knights with specific rules.
{
	int turn = 1;
	while (turn < 1000)
	{
		for (int i = 0; i < K; i++)
		{
			int y = knight[i].y, x = knight[i].x, d = knight[i].dir;
			if (map[y][x][0] != i)			// Could move the knight which is located below.
				continue;

			vector<int> vc = map[y][x];		map[y][x].clear();

			int ny = y + dy[d], nx = x + dx[d];
			if (!Range(ny, nx) || board[ny][nx] == 2)
				Blue(y, x, vc);
			else if (board[ny][nx] == 0)
				White(ny, nx, vc);
			else if (board[ny][nx] == 1)
				Red(ny, nx, vc);

			if (map[knight[i].y][knight[i].x].size() >= 4)			// End condition.
				return turn;
		}
		turn++;
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < K; i++)
	{
		int r, c, d;
		cin >> r >> c >> d;
		knight.push_back({ r,c,d });
		map[r][c].push_back(i);
	}

	answer = Simulation();

	cout << answer << endl;
}