#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101

using namespace std;

int N;													// N = The size of map.
int map[MAX][MAX];							// map = The memory of input data.
int cache[MAX][MAX];						// cache = The memory of memoization.

// Recursion way.
int Memo(int y, int x)			// To write down optimal value in each sub problems.
{										// [각 부분 문제에 최적해를 저장.]
	if (y == N - 1)					// Base case.
		return map[y][x];			

	int &ret = cache[y][x];	// Memoization.
	if (ret != -1)
		return ret;
										// [Compare (y+1,x), (y+1,x+1) values.]
	return ret = max(Memo(y + 1, x), Memo(y + 1, x + 1)) + map[y][x];
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
		
		cout << Memo(0, 0) << endl;
	}
}