#include<iostream>
#include<memory.h>
#include<string>

using namespace std;

const int dy[4] = { 0,-1,0,1 };						// Left, Up, Right, Down.				
const int dx[4] = { -1,0,1,0 };

int r1, c1, r2, c2;											// r,c = The row and column number to print out.
int map[50][5];											// map =The memory of vortex data in ccw.
string len;													// len = The length of maximum value.	

void Simulation()				// To figure out the vortex in CCW.
{
	int y = 0, x = 0;										
	int dir = 3;
	int cnt = 0, tot = 1, num = 1;						

	while (!(map[0][0] != 0 && map[0][c2 - c1] != 0 && map[r2 - r1][0] != 0 && map[r2 - r1][c2 - c1] != 0))
	{
		if (x - r1 >= 0 && x - r1 <= (r2 - r1) && y - c1 >= 0 && y - c1 <= (c2 - c1))
			map[x - r1][y - c1] = num;				// [In range.]
	
		num++;
		cnt++;
		y += dy[dir];
		x += dx[dir];

		if (cnt == tot)										// Increasing moment.
		{
			cnt = 0;
			dir = (dir + 1) % 4;							// Change direction.
			if (dir == 3 || dir == 1)
				tot++;										// When direction was changed twice, increase the total count.
		}
	}

	len = to_string(num);								// The length of maximum value.	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	memset(map, -1, sizeof(map));
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i <= r2 - r1; i++)
	{
		for (int j = 0; j <= c2 - c1; j++)
			map[i][j] = 0;										// Initialization.
	}

	Simulation();

	for (int i = 0; i <= r2 - r1; i++)
	{
		for (int j = 0; j <= c2 - c1; j++)
		{
			string val = to_string(map[i][j]);
			int white_space = len.length() - val.length();
			string str = "";
			while (white_space--)								// Make same length.	
				str += " ";
			str += val;
			cout << str << " ";
		}
		cout << endl;
	}
}