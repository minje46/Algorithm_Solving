#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 101

using namespace std;

int N, M;									// N, M = The size of map.
int map[MAX][MAX];				// map = The memory of input data.
int cache[MAX][MAX];			// cache = The memory of memoization.
int A, B;									// A, B = The number of item and walls.
vector<pair<int, int>>vc;			// vc = The memory of item zoen.
int answer = 1;						// answer = The total number of path to arrive at destination.

int DP(int dpt_y, int dpt_x, int dst_y, int dst_x)				// To figure out the total way from departure to destination.
{
	if (dpt_y > dst_y || dpt_x > dst_x)			// Oveflow.
		return 0;

	if (dpt_y == dst_y && dpt_x == dst_x)		// End condition. [Destination]
		return 1;

	int &ret = cache[dpt_y][dpt_x];
	if (ret != -1)										// Already visited.	
		return ret;

	ret = 0;
	if (map[dpt_y][dpt_x + 1] != 1)			// Go right.
		ret += DP(dpt_y, dpt_x + 1, dst_y, dst_x);
	if (map[dpt_y + 1][dpt_x] != 1)			// Go up.
		ret += DP(dpt_y + 1, dpt_x, dst_y, dst_x);
	return ret;											// Total paths.	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	memset(cache, -1, sizeof(cache));
	memset(map, 0, sizeof(map));
	cin >> N >> M >> A >> B;
	vc.push_back(make_pair(1, 1));
	for (int i = 0; i < A; i++)
	{
		int y, x;
		cin >> y >> x;
		vc.push_back(make_pair(y, x));
	}
	vc.push_back(make_pair(N, M));
	for (int i = 0; i < B; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}

	sort(vc.begin(), vc.end());
	for (int k = 0; k < vc.size() - 1; k++)
		answer *= DP(vc[k].first, vc[k].second, vc[k + 1].first, vc[k + 1].second);

	cout << answer << endl;
}