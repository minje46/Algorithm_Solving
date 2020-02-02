#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 20001

using namespace std;

int N;									// N = The number of fences.
int fence[MAX];					// fence = The memory of input data.
int answer;							// answer = The biggest rectangle area in fences as output.

int DFS(int lf, int rt)		// To figure out the rectangle's area.
{								
	if (lf == rt)						// Base case.
		return fence[lf];			// [Both index point same fence.]

	int mid = (lf + rt) / 2;
	int res = 0;						
	res = max(DFS(lf, mid), DFS(mid + 1, rt));				// Divide the problem as [left ~ mid] and [mid+1 ~ right].
											
	int low = mid, high = mid + 1;								// [Fence가 2개 이상일 경우, left & right를 확장하면서 탐색.]	
	int height = min(fence[low], fence[high]);				// Base state.
	res = max(res, height * 2);									// [min_height이 기준점.]
	while (lf < low || high < rt)									// Not overflow.
	{	
		if (high < rt && (low == lf || fence[low - 1] < fence[high + 1]))	
		{																	// [right fence가 left fence보다 더 높은 경우, right으로 확장.]
			high++;
			height = min(height, fence[high]);
		}
		else
		{																	// [left fence가 right fence보다 더 높은 경우, left으로 확장.]	
			low--;
			height = min(height, fence[low]);
		}
		res = max(res, height * (high - low + 1));			// Compare the current rectangle area.
	}
	return res;
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
			cin >> fence[i];
	
		answer = DFS(0, N - 1);

		cout << answer << endl;
	}
}