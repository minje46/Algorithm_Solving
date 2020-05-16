#include<iostream>

#define MAX 31

using namespace std;

int N;														// N = The number of pills.
long long cache[MAX][MAX];					// cache = The memory of memoization.
long long answer;									// answer = The total cases of pills to take in.	

long long DFS(int w, int h)		// To figure out all of cases.
{
	if (cache[w][h])		// Prunning.
		return cache[w][h];

	if (w == 0)				// Base case.
		return 1;				// [No more regular pill]
								// [남은 건 half pill 밖에 없기때문에, 경우의 수는 1개]						
	cache[w][h] = DFS(w - 1, h + 1);		// [정상적인 약을 먼저 모두 먹을 때 까지, recursive]
	if (h > 0)
		cache[w][h] += DFS(w, h - 1);		// [현재 상황에서, half pill을 배치할 수 있는 경우의 수 탐색]

	return cache[w][h];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	while (true)
	{
		cin >> N;
		if (N == 0)
			break;

		answer = DFS(N, 0);
		
		cout << answer << endl;
	}
}