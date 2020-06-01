#include<iostream>
#include<memory.h>

#define MAX 33000

using namespace std;

int cache[MAX][5];						// cache = The memory of memoization.

void DP()			// To figure out lagrange numbers.
{
	cache[0][0] = 1;
	for (int i = 1; i*i < MAX; i++)
	{
		for (int j = 0; j + i * i < MAX; j++)
		{
			for (int k = 0; k < 4; k++)
				cache[j + i * i][k + 1] += cache[j][k];
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	 
	DP();
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		int answer = 0;						// answer = The number of lagrange numbers.
		for (int i = 1; i <= 4; i++)
			answer += cache[n][i];

		cout << answer << endl;
	}
}