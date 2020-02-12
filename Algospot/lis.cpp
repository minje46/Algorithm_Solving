#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 501

using namespace std;

int N;												// N = The number of input array.
int arr[MAX];									// arr = The memory of input data.

int LIS()			// To make longest increasing subsequence.
{
	vector<int> lis;								// lis = The longest increasing subsequence.
	for (int i = 0; i < N; i++)
	{
		if (i == 0)								// #1. Base state.
			lis.push_back(arr[i]);

		if (lis.back() < arr[i])				// #2. If the array value is bigger, make subsequence.
			lis.push_back(arr[i]);

		else										// #3. If the array is smaller than last value in lis, do compare the position to insert.
		{											// ex) [1, 3, 3, 5]
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();	
			lis[idx] = arr[i];					// [lower_bound : key 값을 찾으면, 가장 왼쪽 index를 return.					ex) key = 3, index = 1.
		}											// key 값을 찾지 못하면, key 값보다 큰 가장 작은 값의 index를 return.		ex) key = 2, index = 1.]
	}
	return lis.size();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case; 
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int answer = LIS();

		cout << answer << endl;
	}
}