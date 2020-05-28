#include<iostream>
#include<algorithm>
#include<string>

#define MAX 251

using namespace std;

string cache[MAX];								// cache = The memory of memoization.

string DP(string a, string b)		// To calculate formula with string type.
{											// [Because of too big calculation]
	long long tot = 0;
	string res;
	
	while (!a.empty() || !b.empty() || tot)
	{										// [1의 자리 수(back)부터 더하기 연산을 수행]
		if (!a.empty())
		{
			tot += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty())
		{
			tot += b.back() - '0';
			b.pop_back();
		}

		res.push_back((tot % 10) + '0');
		tot /= 10;
	}

	reverse(res.begin(), res.end());			// [1의 자리부터 push했기에, reverse 필요]
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cache[0] = cache[1] = "1";		// Formula.
	for (int i = 2; i < MAX; i++)		// [i의 경우의 수 = (i-2) 경우의수 *2 + (i-1) 경우의 수
		cache[i] = DP(DP(cache[i - 2], cache[i - 2]), cache[i - 1]);

	int n;
	while (cin >> n)
		cout << cache[n] << endl;
}