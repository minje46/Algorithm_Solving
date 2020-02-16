#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101
#define INF 987654321

using namespace std;

int N, S;										// N = The number of arrays.				S = The number of splited parts.
int arr[MAX];								// arr = The memory of input array.
int sum[MAX];							// sum = The memory of accumulated sum value.		[sum[i]=A[0]+...A[i]]
int square_sum[MAX];					// square_sum = The memory of squared sum value.	[squar_sum[i] = arr[0]^2+...arr[i]^2]	
int cache[MAX][10];					// cache = The memory of memoization.

void Pre_process()			// To calculate basic data values.
{
	sort(arr, arr + N);						
	sum[0] = arr[0];						// Initialization.
	square_sum[0] = pow(arr[0], 2);

	for (int i = 1; i < N; i++)			
	{
		sum[i] = sum[i - 1] + arr[i];
		square_sum[i] = square_sum[i - 1] + pow(arr[i], 2);
	}
}

int Calculation(int low, int high)			// To calculate the difference formula.
{													// [arr[low] ~ arr[high] 구간을 하나의 숫자로 표현할 때 최소 오차 합 계산.]
	int part_sum = sum[high] - (low == 0 ? 0 : sum[low - 1]);				// [부분합을 이용해 arr[low]...arr[high]의 합 구함.]
	int part_squared_sum = square_sum[high] - (low == 0 ? 0 : square_sum[low - 1]);
	int mean = (int)(0.5 + (double)part_sum / (high - low + 1));				// [반올림.]
																									// [sum(arr[i]-mean)^2를 전개한 결과를 부분합으로 표현]
	int res = part_squared_sum - (2 * mean*part_sum) + (pow(mean, 2)*(high - low + 1));
	return res;									// [∑(arr[i]-mean)^2 = (high-low+1)*mean^2 - 2*(∑arr[i])*mean + ∑arr[i]^2]
}

int Quantize(int idx, int parts)		// To split the array from "idx".	
{												// [idx번째 이후의 숫자들을 parts개의 묶음으로 묶는다.]
	if (idx == N)							// Base case.
		return 0;								// [모든 숫자를 다 양자화했을 때.]
	if (parts == 0)							// Base case2.
		return INF;							// [숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰 값 반환.]

	int &result = cache[idx][parts];
	if (result != -1)						// Memoization.
		return result;

	result = INF;
	for (int k = 1; idx + k <= N; k++)
		result = min(result, Calculation(idx, idx + k - 1) + Quantize(idx + k, parts - 1));
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

		cin >> N >> S;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		Pre_process();
		int answer = Quantize(0, S);

		cout << answer << endl;
	}
}