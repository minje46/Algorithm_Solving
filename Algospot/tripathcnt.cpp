#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101

using namespace std;

int N;														// N = The size of map.
int map[MAX][MAX];								// map = The memory of input data.
int sum[MAX][MAX];								// sum = The memory of calculationg memoization.
int cnt[MAX][MAX];								// cnt = The memory of counting memoization.

int Sum(int y, int x)					// To calculate the maximum sum value.
{
	if (y == N)											// Base case.
		return map[y][x];							// [End point.]

	int &ret = sum[y][x];
	if (ret != -1)										// Memoization.
		return ret;

	return ret = max(Sum(y + 1, x), Sum(y + 1, x + 1)) + map[y][x];
}

int Count(int y, int x)				// To count the paths which has maximum sum value.
{
	if (y == N)
		return 1;

	int &ret = cnt[y][x];
	if (ret != -1)
		return ret;

	ret = 0;
	if (Sum(y + 1, x + 1) >= Sum(y + 1, x))
		ret += Count(y + 1, x + 1);
	if (Sum(y + 1, x + 1) <= Sum(y + 1, x))
		ret += Count(y + 1, x);
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case; 
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(sum, -1, sizeof(sum));
		memset(cnt, -1, sizeof(cnt));

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
				cin >> map[i][j];
		}


		int answer = Count(1,1);

		cout << answer << endl;
	}
}