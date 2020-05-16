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
								// [���� �� half pill �ۿ� ���⶧����, ����� ���� 1��]						
	cache[w][h] = DFS(w - 1, h + 1);		// [�������� ���� ���� ��� ���� �� ����, recursive]
	if (h > 0)
		cache[w][h] += DFS(w, h - 1);		// [���� ��Ȳ����, half pill�� ��ġ�� �� �ִ� ����� �� Ž��]

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