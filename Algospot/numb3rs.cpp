#include<iostream>
#include<memory.h>

#define MAX_N 51
#define MAX_D 101

using namespace std;

int N, D, P;												// N = The size of map.		D = The days to escape.			P = The index of jail.
int map[MAX_N][MAX_D];						// map = The memory of input data.
double cache[MAX_N][MAX_D];				// cache = The memory of memoization.
int adjacent[MAX_N];								// adjacent = The number of adjacent nodes.	

void Init()			// To do initialize.
{
	memset(adjacent, 0, sizeof(adjacent));
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_D; j++)
			cache[i][j] = -1.0;
	}
}

double Search(int here, int day)			// To search the path from destination to departure within days.
{
	if (day == 0)										// Base case.
		return (here == P ? 1.0 : 0.0);			// [Whether arrived at departure or not.]

	double &ret = cache[here][day];			// [Node와 Day를 활용하는 것이 key point.]
	if (ret != -1.0)										// [From destination to departure의 역순 접근 key point.]
		return ret;

	ret = 0.0;
	for (int there = 0; there < N; there++)
	{
		if (map[here][there])						// ∑(1/adjacent(there) * search(there, days-1));
			ret += Search(there, day - 1) / adjacent[there];
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cout.precision(8);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		Init();
		cin >> N >> D >> P;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				adjacent[i] += map[i][j];			// Count the adjacent nodes.
			}
		}

		int T;
		cin >> T;
		for (int i = 0; i < T; i++)
		{
			int dst;
			cin >> dst;

			double answer = Search(dst, D);
			cout << answer << " ";
		}
		cout << endl;
	}
}