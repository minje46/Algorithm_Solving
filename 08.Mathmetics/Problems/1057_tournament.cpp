#include<iostream>

using namespace std;

int N;												// N = The number of participants.
int A, B;											// A,B = The player's number.
int answer;										// answer = The round numer player A and B will have match.

int Simulation()			// To figure out the round A and B will have a match.
{
	int time = 1;
	while (N)
	{
		if ((A + 1) / 2 == (B + 1) / 2)			// End condition.
			return time;

		A = (A + 1) / 2;
		B = (B + 1) / 2;

		time++;
		N /= 2;
	}

	if (!N)											// Exception.
		return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	cin >> A >> B;

	answer = Simulation();

	cout << answer << endl;
}