#include<iostream>
#include<memory.h>

#define MOD 10000000
using namespace std;

int cache[101][101];	

int poly(int n, int first)			// To figure out polyominos.	
{
	if (n == first)										// Base case.
		return 1;											// [Used the whole square blocks.]

	int &result = cache[n][first];
	if (result != -1)
		return result;

	result = 0;		
	for (int second = 1; second <= n - first; second++)
	{	//�� �� �����ٿ������� second��° �ؿ� �ִ� ���� ��� �� poly(n, first)=��(second+first-1) * poly(n-first, second)								
		int add = second + first - 1;
		add *= poly(n - first, second);			//n-first���� ���簢�� �� �ش� ������ second�� ���
		add %= MOD;
		result += add;
		result %= MOD;
	}
	return result;
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
		int N, answer = 0;
		cin >> N;
		for (int k = 1; k <= N; k++)
		{
			answer += poly(N, k);
			answer %= MOD;
		}
		cout << answer << endl;
	}
}