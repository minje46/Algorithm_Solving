#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

//입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로 인위적인 최소치는 64비트여야한다.
const long long NEGINF = numeric_limits<long long>::min();
int N, M;											// N, M = The number of input arrays.	
int A[100], B[100];							// A, B = The memory of input array.
int cache[101][101];						// cache = The memory of memoization.

//min(A[a_idx], B[b_idx]), max(A[a_idx], B[b_idx])로 시작하는
//합친 증가 부분 수열의 최대 길이를 반환
//단 a_idx==b_idx==-1 혹은 A[a_idx]!=B[b_idx]라고 가정
int JLIS(int a_idx, int b_idx)
{
	int &result = cache[a_idx + 1][b_idx + 1];	
	if (result != -1)							// Memoization.
		return result;
	
	result = 0;
	long long a = (a_idx == -1 ? NEGINF : A[a_idx]);
	long long b = (b_idx == -1 ? NEGINF : B[b_idx]);
	long long biggest = max(a, b);

	for (int nxt = a_idx + 1; nxt < N; nxt++)
	{
		if (biggest < A[nxt])
			result = max(result, JLIS(nxt, b_idx) + 1);
	}
	for (int nxt = b_idx + 1; nxt < M; nxt++)
	{
		if (biggest < B[nxt])
			result = max(result, JLIS(a_idx, nxt) + 1);
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

		cin >> N >> M;
		for (int j = 0; j < N; j++)
			cin >> A[j];
		for (int j = 0; j < M; j++)
			cin >> B[j];

		cout << JLIS(-1, -1) << endl;
	}
}