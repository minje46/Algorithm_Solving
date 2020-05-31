#include<iostream>
#include<memory.h>

#define MAX 31

using namespace std;

long long cache[MAX];					// cache = The memory of memoization.

long long tiling(int width)		// To figure out the number of tiles.
{
	if (width <= 1)		// Base case.
		return 1;

	long long &res = cache[width];
	if (res != -1)		// Memoization.
		return res;
							// Formula : tile(n) = 2*tile(n-2) + tile(n-1)
	return res = 2 * tiling(width - 2) + tiling(width - 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	
	int answer;
	if (n % 2 == 1)
		answer = (tiling(n) + tiling(n / 2)) / 2;
	else
		answer = (tiling(n) + tiling(n / 2) + 2 * tiling(n / 2 - 1)) / 2;

	cout << answer << endl;
}