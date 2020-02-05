#include<iostream>
#include<algorithm>

#define MAX 1000000001
#define INF 9987654321

using namespace std;

long long X, Y;									// X = The total number of games.	Y = The number of winning games.
int Z;													// Z = The winning rates.
long long answer = INF;						// answer = Output.

void Binary(long long lf, long long rt)		// To do binary search.
{
	int mid = (lf + rt) / 2;						

	if (lf >= rt)			// Base case.
		return;			// [Overflow.]

	long long x = X + mid;
	long long y = Y + mid;
	int z = 100 * y / x;

	if (z <= Z)										// Winning rate isn't changed yet.
		Binary(mid + 1, rt);
	else												// Winning rate was changed.
	{
		answer = min(answer, (long long)mid);
		Binary(lf, mid);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> X >> Y;

	Z = 100 * Y / X;								// Original winning rate.

	Binary(0, MAX);								// Do binary search, that's because it has super long range.

	if (answer == INF)							// Exception.
		answer = -1;
	cout << answer << endl;
}