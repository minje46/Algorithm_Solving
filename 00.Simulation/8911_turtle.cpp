#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int dy[4] = { -1,0,1,0 };;				// [0:North		1:East
const int dx[4] = { 0,1,0,-1 };				//	2:South		3:West]

struct info
{
	int y, x;
	int dir;
};

string	str;											// str = The memory of input data.
info turtle;											// turtle = The memory of turtle's movement.
int s_y, s_x, b_y, b_x;							// The memory of smallest (y,x) and biggest (y,x).	

void Simulation()				// To figure out the turtle's movement.
{
	for (int i = 0; i < str.length(); i++)
	{
		int ny = turtle.y, nx = turtle.x, ndir = turtle.dir;
		if (str[i] == 'F')							// #. Front : go straight.
		{												
			ny += dy[ndir];
			nx += dx[ndir];
		}
		else if (str[i] == 'B')						// #. Back : go back.
		{												// opposite way = (dir+2)%4
			ny += dy[(ndir + 2) % 4];			
			nx += dx[(ndir + 2) % 4];
		}
		else if (str[i] == 'L')						// #. Left : Turn left.
		{												// turn left : index control.
			ndir -= 1;
			if (ndir < 0)								// Avoid underflow.
				ndir = 3;
		}
		else if (str[i] == 'R')						// #. Right : Turn right.
		{												// turn right : index control.
			ndir += 1;
			if (ndir > 3)								// Avoid overflow.
				ndir = 0;
		}
		b_y = max(b_y, ny);						// Compare the minimum and maximum (y,x) coordinate.
		s_y = min(s_y, ny);
		b_x = max(b_x, nx);
		s_x = min(s_x, nx);
		turtle = { ny,nx,ndir };					// Update to new movement.
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
		turtle = { 0,0,0 };
		s_y = s_x = b_y = b_x = 0;
		cin >> str;

		Simulation();
		int answer = (b_y - s_y) * (b_x - s_x);
		
		cout << answer << endl;
	}
}