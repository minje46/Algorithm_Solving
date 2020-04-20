#include<iostream>

#define MAX 103

using namespace std;

const int dy[4] = { -1,0,1,0 };				// [0] : North.			[1] : East.
const int dx[4] = { 0,1,0,-1 };				// [2] : South.		[3] : West.

struct info
{
	int y, x;
	int dir;
};

int R, C;												// R, C = The size of map.
int map[MAX][MAX];							// map = The map of robot's location.
int N, M;												// N = The number of robots.			M = The number of operation.
info robot[MAX];									// robot = The memory of robot's information.

int Direction(char ch)			// To figure out the direction.
{
	if (ch == 'N')
		return 0;
	else if (ch == 'E')
		return 1;
	else if (ch == 'S')
		return 2;
	else if (ch == 'W')
		return 3;
}

void Moved(int idx, int num)			// To move current robot in forward.
{
	int y = robot[idx].y, x = robot[idx].x, k = robot[idx].dir;
	map[y][x] = 0;			// Departure point.			
		
	for (int i = 1; i <= num; i++)
	{
		y += dy[k];
		x += dx[k];

		if (y<1 || y>R || x<1 || x>C)	// End condition 1 : Overflow.
		{
			cout << "Robot " << idx << " crashes into the wall" << endl;
			exit(0);
		}
		
		if (map[y][x] != 0)					// End condition 2 : Crash.
		{
			cout << "Robot " << idx << " crashes into robot " << map[y][x] << endl;
			exit(0);
		}
	}
	map[y][x] = idx;
	robot[idx] = { y,x,k };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> C >> R >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		char ch;
		cin >> x >> y >> ch;
		robot[i] = { (R - y + 1), x, Direction(ch) };
		map[robot[i].y][robot[i].x] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int idx, num;
		char ch;
		cin >> idx >> ch >> num;
		if (ch == 'F')
			Moved(idx, num);
		else if (ch == 'L')
			robot[idx].dir = (robot[idx].dir + (num * 3)) % 4;
		else if (ch == 'R')
			robot[idx].dir = (robot[idx].dir + num) % 4;
	}

	cout << "OK" << endl;
}