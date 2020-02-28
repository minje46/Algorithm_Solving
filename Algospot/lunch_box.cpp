#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int Greedy(vector<pair<int, int>> vc)			// To figure out the minimum time for lunch.
{
	sort(vc.begin(), vc.end(), greater<pair<int, int>>());							// Descending sort by eating time.
		
	int time = vc[0].second, mx = vc[0].first + vc[0].second;
	for (int i = 1; i < vc.size(); i++)
	{
		time += vc[i].second;																// Total time = The whole of lunch heated time.
		mx = max(mx - vc[i - 1].second, vc[i].first + vc[i].second);		// [mx = Max of heat + eat time.]
	}																								// Compare the each time at that moment.
	return time + mx - vc[vc.size() - 1].second;									//	Additionally, the eating time of last lunch box.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		int N;															// N = The number of lunch boxes.
		cin >> N;
		vector<pair<int, int>> vc;								// vc = The memory of input data.
		for (int i = 0; i < N; i++)								// [eat, heat] time.	
		{
			int m;
			cin >> m;
			vc.push_back(make_pair(0, m));				
		}
		for (int i = 0; i < N; i++)
		{
			int e;
			cin >> e;
			vc[i].first = e;
		}

		int answer = Greedy(vc);

		cout << answer << endl;
	}
}