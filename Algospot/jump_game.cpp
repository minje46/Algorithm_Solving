#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101

using namespace std;

int N;												// N = The size of map.
int map[MAX][MAX];						// map = The memory of input data.
int cache[MAX][MAX];					// cache = The memory of memoization.

int DFS(int y, int x)			// To figure out whether it arrives at destination or not.
{
	if (y >= N || x >= N)					// Base case.
		return 0;									// [Overflow.]
	if (y == N - 1 && x == N - 1)		// Base case.
		return 1;									//	[Destination.]		
	
	int &ret = cache[y][x];
	if (ret != -1)								// Exception.
		return ret;								// [Already visited.]	

	return ret = (DFS(y + map[y][x], x) || DFS(y, x + map[y][x]));	
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
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		}

		if (DFS(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}