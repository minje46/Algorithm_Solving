#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, H;													// N,H = The size of map.
vector<int>down, up;								// down, up = The height of bottom and top.

pair<int, int> Simulation()			// To figure out the minimum number of crashes.
{
	sort(down.begin(), down.end());		// To do binary search.
	sort(up.begin(), up.end());

	int mn = 1e9, cnt = 1;
	for (int i = 1; i <= H; i++)
	{
		int tot = down.size() - (lower_bound(down.begin(), down.end(), i) - down.begin());
		tot += up.size() - (upper_bound(up.begin(), up.end(), H - i) - up.begin());

		if (tot == mn)
			cnt++;
		else if (tot < mn)
			mn = tot, cnt = 1;
	}
	return make_pair(mn, cnt);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> H;
	down.resize(N / 2);		up.resize(N / 2);
	for (int j = 0; j < N / 2; j++)
		cin >> down[j] >> up[j];

	pair<int, int> answer = Simulation();

	cout << answer.first << " " << answer.second << endl;
}