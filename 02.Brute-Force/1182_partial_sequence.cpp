#include<iostream>

#define MAX 21

using namespace std;

int N, S;								// N = The number of sequence.				S = The target value.
int arr[MAX];						// arr = The memory of input data.
int answer = 0;					// answer = The number of target's value as output.

void DFS(int idx, int tot)		// To do exhaustive search. 
{
	if (idx >= N)					// Base case.
		return;						// [Overflow.]
	
	tot += arr[idx];				
	if (tot == S)
		answer++;

	DFS(idx + 1, tot);					// [증가시키면서, search.]
	DFS(idx + 1, tot - arr[idx]);		// [현재 idx는 건너뛰고, 다음 idx부터 search.]
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	DFS(0, 0);

	cout << answer << endl;
}