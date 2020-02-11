#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101

using namespace std;

int N;													// N = The size of map.
int map[MAX][MAX];							// map = The memory of input data.
int cache[MAX][MAX];						// cache = The memory of memoization.

void DP()		// To write down maximum value in each location.
{														// Basic state.	
	cache[0][0] = map[0][0];
	cache[1][0] = cache[0][0] + map[1][0];
	cache[1][1] = cache[0][0] + map[1][1];

	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int &ret = cache[i][j];

			if (j == 0)								// Exception #1. Left side.
				ret = cache[i - 1][j] + map[i][j];
			else if (j == i)							// Exception #2. Right side.
				ret = cache[i - 1][j - 1] + map[i][j];
			else										// [Compare (y+1,x), (y+1,x+1) values.]
				ret = max(cache[i - 1][j - 1], cache[i - 1][j]) + map[i][j];
		}
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
		memset(cache, -1, sizeof(cache));

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i + 1; j++)
				cin >> map[i][j];
		}

		DP();

		int answer = 0;
		for (int i = 0; i < N; i++)
			answer = max(answer, cache[N - 1][i]);
		cout << answer << endl;
	}
}