#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 202

using namespace std;

int N;														// N = The number of input data.
int arr[MAX];											// arr = The memory of input data.			
int cache[MAX];										// cache = The memory of memoization.

int LIS(int dpt)			// To figure out the longest increasing sequence.
{
	int &res = cache[dpt + 1];			// Memoization.
	if (res != -1)
		return res;

	res = 0;
	for (int nxt = dpt + 1; nxt < N; nxt++)
	{
		if (dpt == -1 || arr[dpt] < arr[nxt])		// Increasing condition.
		{
			int cnt = 1 + LIS(nxt);			// Length of sequence.
			res = max(res, cnt);
		}
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	memset(cache, -1, sizeof(cache));
	int answer = N - LIS(-1);

	cout << answer << endl;
}