#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 21
#define INF 987654321

using namespace std;

int N, total;							// N = The size of map.
int map[MAX][MAX];			// map = The memory of input data.
int area[MAX][MAX];			// area = The memory of each district.
int population[6];				// population = The memory of population in each district.
int answer = INF;					// answer = The minimum gap between max and min population.

int Minimum()						// To figure out the minimum difference between biggest and smallest area.	
{
	int big = -INF, small = INF;
	for (int i = 1; i <= 5; i++)
	{
		big = max(big, population[i]);
		small = min(small, population[i]);
	}
	return big - small;
}

void Count()						// To count the number of population in each district.
{
	memset(population, 0, sizeof(population));		// Initialization.
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int idx = area[i][j];
			population[idx] += map[i][j];					// Population.
		}
	}
	population[5] = total-population[1]-population[2]-population[3]-population[4];
}

void District(int y, int x, int d1, int d2)					// To make a each different district.
{
	memset(area, 0, sizeof(area));							// Initialization.
	int lf = x, rt = x;
	for (int i = y; i <= y + d1 + d2; i++)						// # District 5.
	{
		if (i <= y + d1)
			area[i][lf--] = 5;
		else
		{
			if (lf <= x - d1)
				lf += 2;
			area[i][lf++] = 5;
		}

		if (i <= y + d2)
			area[i][rt++] = 5;
		else
		{
			if (rt >= x + d2)
				rt -= 2;
			area[i][rt--] = 5;
		}
	}
	for (int i = 1; i < y + d1; i++)								// # District 1.
	{
		for (int j = 1; j <= x; j++)
		{
			if (area[i][j] == 5)
				break;
			area[i][j] = 1;
		}
	}
	for (int i = 1; i <= y + d2; i++)							// # District 2.
	{
		for (int j = N; j >= 0; j--)
		{
			if (area[i][j] != 0)
				break;
			area[i][j] = 2;
		}
	}
	for (int i = y + d1; i <= N; i++)							// # District 3.
	{
		for (int j = 1; j < x - d1 + d2; j++)
		{
			if (area[i][j] == 5)
				break;
			area[i][j] = 3;
		}
	}
	for (int i = y + d2 + 1; i <= N; i++)						// # District 4.
	{
		for (int j = N; j >= 0; j--)
		{
			if (area[i][j] != 0)
				break;
			area[i][j] = 4;
		}
	}
}

void Simulation()				// To figure out the (y,x,d1,d2) combination set.
{
	for (int i = 2; i <= N - 1; i++)									// Y range.
	{
		for (int j = 2; j <= N - 1; j++)								// X range.
		{
			for (int a = 1; a <= N; a++)							// D1 range.
			{
				if (j - a < 1)
					break;
				for (int b = 1; b <= N; b++)						// D2 range.
				{
					if (i + a + b > N || j + b > N)
						break;

					District(i, j, a, b);								// Make a district.
					Count();												// Count the population.
					answer = min(answer, Minimum());		// Compare the minimum gap.
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	total = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];			
			total += map[i][j];	
		}
	}

	Simulation();

	cout << answer << endl;	
}