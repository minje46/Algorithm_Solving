#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 55

using namespace std;

char cube[MAX];				// cube = The figure of cube.
							// [1-9] : Back, [10-18] : Down, [19-27] : Front, [28-36] : Left, [37-45] : Right, [46-54] : Up
void Init()		// To initialize each side of cube with color.
{
	for (int i = 1; i <= 9; i++)
		cube[i] = 'o';				// Back : orange
	for (int i = 10; i <= 18; i++)
		cube[i] = 'y';				// Down : yellow
	for (int i = 19; i <= 27; i++)
		cube[i] = 'r';				// Front : red
	for (int i = 28; i <= 36; i++)
		cube[i] = 'g';				// Left : green
	for (int i = 37; i <= 45; i++)
		cube[i] = 'b';				// Right : blue
	for (int i = 46; i <= 54; i++)
		cube[i] = 'w';				// Up : white
}

void Print()			// To print the front side.
{
	for (int i = 48; i <= 54; i += 3)
	{
		for (int j = 0; j >= -2; j--)
			cout << cube[i + j];
		cout << endl;
	}
}

void Simulation(char d, char c)
{
	switch (d)
	{
	case 'L':
	{
		if (c == '+')
		{
			swap(cube[1], cube[54]);	swap(cube[1], cube[19]);	swap(cube[1], cube[10]);
			swap(cube[4], cube[51]);	swap(cube[4], cube[22]);	swap(cube[4], cube[13]);
			swap(cube[7], cube[48]);	swap(cube[7], cube[25]);	swap(cube[7], cube[16]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[28 + i] = cube[30 + (i * 3)];
				tmp[31 + i] = cube[29 + (i * 3)];
				tmp[34 + i] = cube[28 + (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		else
		{
			swap(cube[1], cube[10]);	swap(cube[1], cube[19]);	swap(cube[1], cube[54]);
			swap(cube[4], cube[13]);	swap(cube[4], cube[22]);	swap(cube[4], cube[51]);
			swap(cube[7], cube[16]);	swap(cube[7], cube[25]);	swap(cube[7], cube[48]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[28 + i] = cube[34 - (i * 3)];
				tmp[31 + i] = cube[35 - (i * 3)];
				tmp[34 + i] = cube[36 - (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		break;
	}
	case 'R':
	{
		if (c == '+')
		{
			swap(cube[3], cube[12]);	swap(cube[3], cube[21]);	swap(cube[3], cube[52]);
			swap(cube[6], cube[15]);	swap(cube[6], cube[24]);	swap(cube[6], cube[49]);
			swap(cube[9], cube[18]);	swap(cube[9], cube[27]);	swap(cube[9], cube[46]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[45 - (i * 3)] = cube[43 + i];
				tmp[44 - (i * 3)] = cube[40 + i];
				tmp[43 - (i * 3)] = cube[37 + i];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		else
		{
			swap(cube[3], cube[52]);	swap(cube[3], cube[21]);	swap(cube[3], cube[12]);
			swap(cube[6], cube[49]);	swap(cube[6], cube[24]);	swap(cube[6], cube[15]);
			swap(cube[9], cube[46]);	swap(cube[9], cube[27]);	swap(cube[9], cube[18]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[45 - (i * 3)] = cube[39 - i];
				tmp[44 - (i * 3)] = cube[42 - i];
				tmp[43 - (i * 3)] = cube[45 - i];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		break;
	}
	case 'U':
	{
		if (c == '+')
		{
			swap(cube[25], cube[28]);	swap(cube[25], cube[3]);	swap(cube[25], cube[45]);
			swap(cube[26], cube[31]);	swap(cube[26], cube[2]);	swap(cube[26], cube[42]);
			swap(cube[27], cube[34]);	swap(cube[27], cube[1]);	swap(cube[27], cube[39]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[48 - i] = cube[54 - (i * 3)];
				tmp[51 - i] = cube[53 - (i * 3)];
				tmp[54 - i] = cube[52 - (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		else
		{
			swap(cube[25], cube[45]);	swap(cube[25], cube[3]);	swap(cube[25], cube[28]);
			swap(cube[26], cube[42]);	swap(cube[26], cube[2]);	swap(cube[26], cube[31]);
			swap(cube[27], cube[39]);	swap(cube[27], cube[1]);	swap(cube[27], cube[34]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[48 - i] = cube[46 + (i * 3)];
				tmp[51 - i] = cube[47 + (i * 3)];
				tmp[54 - i] = cube[48 + (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		break;
	}
	case 'D':
	{
		if (c == '+')
		{
			swap(cube[19], cube[43]);	swap(cube[19], cube[9]);	swap(cube[19], cube[30]);
			swap(cube[20], cube[40]);	swap(cube[20], cube[8]);	swap(cube[20], cube[33]);
			swap(cube[21], cube[37]);	swap(cube[21], cube[7]);	swap(cube[21], cube[36]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[10 + i] = cube[12 + (i * 3)];
				tmp[13 + i] = cube[11 + (i * 3)];
				tmp[16 + i] = cube[10 + (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		else
		{
			swap(cube[19], cube[30]);	swap(cube[19], cube[9]);	swap(cube[19], cube[43]);
			swap(cube[20], cube[33]);	swap(cube[20], cube[8]);	swap(cube[20], cube[40]);
			swap(cube[21], cube[36]);	swap(cube[21], cube[7]);	swap(cube[21], cube[37]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[10 + i] = cube[16 - (i * 3)];
				tmp[13 + i] = cube[17 - (i * 3)];
				tmp[16 + i] = cube[18 - (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		break;
	}
	case 'F':
	{
		if (c == '+')
		{
			swap(cube[54], cube[45]);	swap(cube[54], cube[18]);	swap(cube[54], cube[36]);
			swap(cube[53], cube[44]);	swap(cube[53], cube[17]);	swap(cube[53], cube[35]);
			swap(cube[52], cube[43]);	swap(cube[52], cube[16]);	swap(cube[52], cube[34]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[25 + i] = cube[19 + (i * 3)];
				tmp[22 + i] = cube[20 + (i * 3)];
				tmp[19 + i] = cube[21 + (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		else
		{
			swap(cube[54], cube[36]);	swap(cube[54], cube[18]);	swap(cube[54], cube[45]);
			swap(cube[53], cube[35]);	swap(cube[53], cube[17]);	swap(cube[53], cube[44]);
			swap(cube[52], cube[34]);	swap(cube[52], cube[16]);	swap(cube[52], cube[43]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[25 + i] = cube[27 - (i * 3)];
				tmp[22 + i] = cube[26 - (i * 3)];
				tmp[19 + i] = cube[25 - (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		break;
	}
	case 'B':
	{
		if (c == '+')
		{
			swap(cube[48], cube[30]);	swap(cube[48], cube[12]);	swap(cube[48], cube[39]);
			swap(cube[47], cube[29]);	swap(cube[47], cube[11]);	swap(cube[47], cube[38]);
			swap(cube[46], cube[28]);	swap(cube[46], cube[10]);	swap(cube[46], cube[37]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[1 + i] = cube[3 + (i * 3)];
				tmp[4 + i] = cube[2 + (i * 3)];
				tmp[7 + i] = cube[1 + (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		else
		{
			swap(cube[48], cube[39]);	swap(cube[48], cube[12]);	swap(cube[48], cube[30]);
			swap(cube[47], cube[38]);	swap(cube[47], cube[11]);	swap(cube[47], cube[29]);
			swap(cube[46], cube[37]);	swap(cube[46], cube[10]);	swap(cube[46], cube[28]);
			char tmp[MAX];	memcpy(tmp, cube, sizeof(cube));
			for (int i = 0; i < 3; i++)
			{
				tmp[1 + i] = cube[7 - (i * 3)];
				tmp[4 + i] = cube[8 - (i * 3)];
				tmp[7 + i] = cube[9 - (i * 3)];
			}
			memcpy(cube, tmp, sizeof(cube));
		}
		break;
	}
	default:
		break;
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
		Init();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char d, c;
			cin >> d >> c;
			Simulation(d, c);
		}
		Print();
	}
}