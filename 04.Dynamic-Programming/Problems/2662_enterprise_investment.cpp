#include<iostream>
#include<memory.h>

#define MAX_N 301
#define MAX_M 22

using namespace std;

int N, M;											// N = The total money of investment.				M = The number of companies.
int company[MAX_N][MAX_M], invest[MAX_N][MAX_M];			// company, invest = The memory of input data.
int cache[MAX_N][MAX_M];				// cache = The memory of memoization.

int DFS(int rem, int idx)		// To figure out all results after invest.
{
	if (idx > M)			// Base case.
		return 0;		

	int &res = cache[rem][idx];
	if (res != -1)		// Memoization.
		return res;

	res = 0;				// [0~���� ���� money����, ��� invest �غ���]
	for (int k = 0; k <= rem; k++)
	{						// [���� money��, idx����� �������� ���� res ���]
		int tmp = company[k][idx] + DFS(rem - k, idx + 1);
		if (res < tmp)	// [�ִ� ������ ����� ���ڱݾ� k�� invest�� ���� -> backtracking]
			res = tmp, invest[rem][idx] = k;
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int val;	cin >> val;
		for (int j = 1; j <= M; j++)
		{
			int res;	cin >> res;
			company[val][j] = res;		// [1~M ����� val ����, res ��ȯ]
		}
	}
	
	memset(cache, -1, sizeof(cache));
	cout << DFS(N, 1) << endl;
	int tot = N;
	for (int i = 1; i <= M; i++)
	{
		cout << invest[tot][i] << " ";
		tot -= invest[tot][i];
	}
}