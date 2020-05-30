#include<iostream>
#include<memory.h>

#define MAX 1001
#define MOD 10007

using namespace std;

int cache[MAX];								// cache = The memory of memoization.

int Tiling(int width)		// To figure out the number of tiles to attach.
{
	if (width <= 1)				// Base case #1.
		return 1;					// [���̰� 1�� tile]	

	int &res = cache[width];
	if (res != -1)
		return res;
	// [���̰� 2�� tile 2���� ���]
	return res = (Tiling(width - 2) * 2 + Tiling(width - 1)) % MOD;
}

int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cout << Tiling(n) << endl;
}