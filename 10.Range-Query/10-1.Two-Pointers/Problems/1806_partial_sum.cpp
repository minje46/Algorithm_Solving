#include<iostream>
#include<algorithm>

#define MAX 100001
#define INF 987654321

using namespace std;

int N, S;										// N = The number of input data.				S = The target sum value.
int arr[MAX];								// arr = The memory of input data.
int answer = INF;							// answer = The minimnum length of target value.

void Simulation()			// To do range search based on two pointers algoritm.
{
	int lf = 0, rt = 0;					// lf, rt = Two pointers.
	int sum = arr[0];					// sum = The total sum value.
	while (lf <= rt && rt < N)		// Avoid overflow.
	{
		if (sum < S)					// Control right pointer.	
			sum += arr[++rt];
		else if (sum >= S)			// Control left pointer.
		{
			answer = min(answer, (rt - lf) + 1);
			sum -= arr[lf++];
			if (lf > rt && lf < N)		// Next step.
			{
				rt = lf;
				sum = arr[lf];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Simulation();

	if (answer == INF)
		answer = 0;
	cout << answer << endl;
}