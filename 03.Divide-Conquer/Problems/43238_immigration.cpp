#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long solution(int n, vector<int> times)				// To figure out the total minimum time to take immigration.
{
	long long answer;
	sort(times.begin(), times.end());
	int m = times.size();
	long long lf = times[0], rt = (long long)times[m - 1] * n;
	while (lf <= rt)													// Binary search.
	{
		long long mid = (lf + rt) / 2;
		long long cnt = 0;
		for (int i = 0; i < m; i++)
		{
			cnt += (mid / times[i]);
			if (cnt >= n)										
			{
				answer = mid;
				break;
			}
		}
		if (cnt >= n)
			rt = mid - 1;
		else
			lf = mid + 1;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	//	vector<int> vc = { 7, 10 };
	vector<int> vc = { 3,4,5,10 };

	cout << solution(10, vc) << endl;
}