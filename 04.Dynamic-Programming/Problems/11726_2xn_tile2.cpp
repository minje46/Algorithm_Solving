#include<iostream>
#include<memory.h>

#define MAX 1001
#define MOD 10007

using namespace std;

int cache[MAX];								// cache = The memory of memoization.

int Tiling(int width)		// To figure out the number of tiles to attach.
{
	if (width <= 1)				// Base case #1.
		return 1;					// [넓이가 1인 tile]	

	int &res = cache[width];
	if (res != -1)
		return res;
	// [넓이가 2인 tile 2개로 취급]
	return res = (Tiling(width - 2) * 2 + Tiling(width - 1)) % MOD;
}

int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cout << Tiling(n) << endl;
}