#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101

using namespace std;

int N;											// N = The number of players.
int russia[MAX], korea[MAX];		// russia, korea = The memory of input data.
bool check[MAX];						// check = The memory of used or not.
int answer;									// answer = The maximum number of winning players.

int Greedy()				// To figure out the maximum winning combination.	
{
	sort(russia, russia + N);			// Ascending sort.
	sort(korea, korea + N);

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (!check[j] && russia[i] <= korea[j])
			{
				check[j] = true;
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(check, false, sizeof(check));

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> russia[i];
		for (int j = 0; j < N; j++)
			cin >> korea[j];

		answer = Greedy();

		cout << answer << endl;
	}
}