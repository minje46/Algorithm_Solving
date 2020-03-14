#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 51

using namespace std;

int R, C;														// R,C = The size of map.
char map[MAX][MAX];								// map = The memory of input data.	
vector<pair<int, int>>vc;								// vc = The memory of each team's distance and index.	
int answer[10];												// answer = Each team's current rank.

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first)
		return true;
	return false;
}

void Simulation()				// To figure out each team's current rank.
{
	sort(vc.begin(), vc.end(), comp);

	int rank = 1;
	answer[vc[0].second] = rank;
	int prev = vc[0].first;
	for (int i = 1; i < vc.size(); i++)
	{
		if (prev == vc[i].first)
			answer[vc[i].second] = rank;
		else
		{
			answer[vc[i].second] = ++rank;
			prev = vc[i].first;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		bool flag = true;
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= '1' && map[i][j] <= '9' && flag)
			{
				vc.push_back(make_pair(j, map[i][j] - '0'));
				flag = false;
			}
		}
	}

	Simulation();

	for (int i = 1; i < 10; i++)
		cout << answer[i] << endl;
}