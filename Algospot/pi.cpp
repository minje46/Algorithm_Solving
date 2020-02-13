#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
#include<vector>

#define MAX 10002
#define INF 987654321

using namespace std;

int cache[MAX];									// cache = The memory of memoization.
string str;											// str = The memory of input data.

int Calculation(int a, int b)					// To figure out which level the string has.
{														// sub = The sub string from a_index to b_index.	
	string sub = str.substr(a, b - a + 1);

	// #Level 1.
	if (sub == string(sub.length(), str[a]))					// [동일한 구성.]
		return 1;

	// #Level 5.
	bool level_5 = true;
	for (int i = 0; i < sub.length() - 1; i++)
	{
		if (sub[i + 1] - sub[i] != sub[1] - sub[0])			// [등차 수열 여부.]
			level_5 = false;
	}

	// #Level 2.
	if (level_5 && abs(sub[1] - sub[0]) == 1)				// [증감 1.]
		return 2;

	// #Level 4.
	bool level_4 = true;
	for (int i = 0; i < sub.length(); i++)						
	{
		if (sub[i] != sub[i % 2])									// [동일한 패턴 반복.]
			level_4 = false;
	}
	if (level_4)
		return 4;

	// #Level 5.
	if (level_5)
		return 5;

	return 10;
}

int DP(int idx)							// To memorize the result in cache.
{
	if (idx == str.length())			// Base case.
		return 0;

	int &ret = cache[idx];			// Memoization.
	if (ret != -1)
		return ret;

	ret = INF;
	for (int k = 3; k <= 5; k++)
	{
		if (idx + k <= str.length())
			ret = min(ret, DP(idx + k) + Calculation(idx, idx + k - 1));
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(cache, -1, sizeof(cache));

		cin >> str;
		
		int answer= DP(0);

		cout << answer << endl;
	}
}