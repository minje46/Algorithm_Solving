#include<iostream>
#include<memory.h>

#define MAX 101
#define MOD 1000000007

using namespace std;

int cache[MAX];									// cache = The memory of memoization.

int Tiling(int area)			// To figure out how many squares it has.
{
	if (area <= 1)									// Base case.
		return 1;

	int &ret = cache[area];
	if (ret != -1)									// Memoization.	
		return ret;

	return ret = (Tiling(area - 2) + Tiling(area - 1)) % MOD;
}

int Asymmetric(int width)		// To figure out how many assymetric squares.
{
	if (width % 2 == 1)							// Base case.
		return (Tiling(width) - Tiling(width / 2) + MOD) % MOD;		// [Ȧ���� ���, �߽� �� �������� ��Ī�Ǵ� squares.]

	int ret = Tiling(width);						// The whole of squares.	// [¦���� ���,]
	ret = (ret - Tiling(width / 2) + MOD) % MOD;							// [������ �������� ��Ī�Ǵ� squares.]
	ret = (ret - Tiling(width / 2 - 1) + MOD) % MOD;						// [����� �������� ��Ī�Ǵ� squares.]	
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	memset(cache, -1, sizeof(cache));
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		int N;
		cin >> N;

		int answer = Asymmetric(N);

		cout << answer << endl;
	}
}