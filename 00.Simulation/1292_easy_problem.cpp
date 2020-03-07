#include<iostream>

#define MAX 1002

using namespace std;

int arr[MAX];											// arr = The memory of each index's value.

int Simulation(int A, int B)			// To figure out the total sum value between A and B.
{
	int num = 1, idx = 1;
	while (idx <= 1000)								// From 1 to 1000.
	{
		for (int i = 1; i <= num; i++)				// store the integer value in each index.
		{
			arr[idx++] = num;
			if (idx > 1000)								// Avoid overflow.
				break;
		}
		num++;
	}

	int tot = 0;
	for (int k = A; k <= B; k++)					// From A to B.
		tot += arr[k];

	return tot;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int A, B;
	cin >> A >> B;

	int answer = Simulation(A, B);

	cout << answer << endl;
}