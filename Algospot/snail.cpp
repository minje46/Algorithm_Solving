#include<iostream>

#define MAX 1001

using namespace std;

int N, M;													// N = The height of well.					M = The number of days.
double cache[MAX][MAX * 2];					// cache = The memory of memoization.

void Init()									// To initialize the cache memory because of double data type.
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX * 2; j++)
			cache[i][j] = -1.0;
	}
}

double DP(int day, int height)		// To figure out the snail's movement in each day. 
{
	if (day == M)										// Base case.
		return height >= N ? 1 : 0;				// [When day is finished, heightance is over or not.]

	double &ret = cache[day][height];
	if (ret != -1.0)
		return ret;
															// [0.75 : Rainy day.]	[0.25 : Sunny day.]
	return ret = 0.75*(DP(day + 1, height + 2)) + 0.25*(DP(day + 1, height + 1));
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
		cin >> N >> M;

		double answer = DP(0, 0);

		cout.precision(11);
		cout << answer << endl;
	}
}