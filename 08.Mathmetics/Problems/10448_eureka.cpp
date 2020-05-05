#include<iostream>

#define MAX 1001

using namespace std;

int N;									// N = The target number.
int arr[MAX];						// arr = The memory of trianlge theory based on eureka.
bool answer;						// answer = Whether there is triangle sum value exists or not.	

void Init()		// To set all kinds of triangle theory.
{
	for (int i = 1; i < MAX; i++)
		arr[i] = (i*(i + 1)) / 2;			// Formula.
}

void DFS(int idx, int cnt, int tot)			// To figure out duplicated combination.
{
	if (answer || tot > N)		// Prunning.
		return;						// [Figure out the answer + Impossible case]

	if (cnt == 3)					// Base case.
	{
		if (tot == N)				// [Triangle sum value]
			answer = true;
		return;
	}

	for (int i = idx; i < MAX; i++)			// Duplicated combination.
		DFS(i, cnt + 1, tot + arr[i]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	Init();
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N;
		
		answer = false;
		DFS(1, 0, 0);

		cout << answer << endl;
	}
}
