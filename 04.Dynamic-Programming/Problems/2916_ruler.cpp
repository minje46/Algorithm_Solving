#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 15

using namespace std;

int N, K;												// N = The number of input data.			K = The number of queries.
int arr[MAX];										// arr = The memory of input data.
int cache[MAX][365];							// cache = The memory of memoization.
int answer[365];									// answer = The memory of whether degree has or not.

void DP(int idx, int sum)		// To figure out all degree set.
{
	if (idx > N || cache[idx][sum] != -1)		// Base case.
		return;

	cache[idx][sum] = 1;
	answer[sum] = 1;

	DP(idx, (360 + sum - arr[idx]) % 360);		// Addition of degree.
	DP(idx + 1, sum);									// Next degree.	
	DP(idx, (360 + sum + arr[idx]) % 360);		// Substraction of degree.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);
	memset(cache, -1, sizeof(cache));
	DP(0, 0);

	for (int i = 0; i < K; i++)
	{
		int num;		cin >> num;
		if (answer[num])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}