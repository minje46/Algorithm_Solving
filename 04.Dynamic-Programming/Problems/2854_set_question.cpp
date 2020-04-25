#include<iostream>
#include<memory.h>

#define MAX 100001
#define MOD 1000000007

using namespace std;

int N;															// N = The number of problems.
int A[MAX], B[MAX];									// A = The fixed level.				B = The unfixed level.	
long long cache[MAX][2];							// cache = The memory of memoization.

void DP()			// To do memoization based on formula.
{
	cache[0][0] = 1;				// Basic state.
	for (int i = 1; i <= N; i++)
	{
		cache[i][0] = ((long long)(cache[i - 1][0] + cache[i - 1][1]) * (A[i] + B[i - 1] - 1) + cache[i - 1][0]) % MOD;
		cache[i][1] = (long long)(cache[i - 1][0] + cache[i - 1][1]) * B[i] % MOD;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i < N; i++)
		cin >> B[i];

	DP();

	cout << cache[N][0] << endl;
}