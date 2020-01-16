#include<iostream>

using namespace std;

int N;										// N = The natural number.
int answer = 0;						// answer = The sum value of decomposition as output.

int Digits(int num)					// To do decompose number.
{
	if (num < 10)						// Base case.
		return num;					// [Less than 10.]

	int r = num % 10;				// Each digit.
		
	return r + Digits(num / 10);	// Recursive.
}

void Simulation()						// To do exhaustive search.	
{
	for (int i = 1; i <= N; i++)
	{
		int res = i;

		res += Digits(i);				// Sum value of decompositions.
		if (res == N)			
		{
			answer = i;
			return;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;

	Simulation();

	cout << answer << endl;
}