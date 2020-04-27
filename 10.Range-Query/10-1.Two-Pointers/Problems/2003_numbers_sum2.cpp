#include<iostream>

#define MAX 10001

using namespace std;

int N, M;													// N = The number of input data.					M = The target sum value.
int arr[MAX];											// arr = The memory of input data.
int answer = 0;										// answer = The number of target sum value.

void Simulation()			// To do range search based on two pointers algoritm.
{
	int lf = 0, rt = 0;						// lf, rt = Two pointers.
	int sum = arr[0];						// sum = The total sum value.
	while (lf <= rt && rt < N)			// Avoid overflow.
	{
		if (sum < M)						// Control right pointer.
			sum += arr[++rt];
		else if (sum == M)
		{
			answer++;
			sum += arr[++rt];
		}
		else if (sum > M)					// Control left pointer.
		{
			sum -= arr[lf++];
			if (lf > rt && lf < N)			// [left pointer가 right pointer를 초과한 경우,
			{									// left pointer를 이전의 시작 지점보다 +1 위치에서 재시작]
				rt = lf;						// Start right pointer at first step.
				sum = arr[lf];				// [right pointer도 처음 단계부터 점차 증가하며 search]
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Simulation();

	cout << answer << endl;
}