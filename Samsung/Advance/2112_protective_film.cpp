#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
//#pragma warning(disable:4996)
#define MAX_D 15
#define MAX_W 22

using namespace std;

int D, W, K;
int map[MAX_D][MAX_W], tmp[MAX_D][MAX_W];
vector<int>vc;
bool visit[MAX_D], used[MAX_D], flag;
int answer;

void Setting()
{
	vc.clear();
	for (int i = 1; i <= D; i++)
	{
		if (visit[i])
			vc.push_back(i);
	}
}

bool Check()
{
	for (int j = 1; j <= W; j++)
	{
		bool fg = false;
		int cnt = 1, cur = tmp[1][j];
		for (int i = 2; i <= D; i++)
		{
			if (cur == tmp[i][j])
				cnt++;
			else
				cur = tmp[i][j], cnt = 1;

			if (cnt >= K)
			{
				fg = true;
				break;
			}
		}
		if (!fg)
			return false;
	}
	return true;
}

void Convert(int i, int val)
{
	for (int j = 1; j <= W; j++)
		tmp[i][j] = val;
}

void Simulation()
{
	vector<int>c;
	for (int i = 0; i < vc.size(); i++)
		c.push_back(0);
	for (int i = 0; i <= vc.size(); i++)
	{
		int sz = i, idx = c.size() - 1;
		while (sz--)
			c[idx--] = 1;

		do
		{
			memcpy(tmp, map, sizeof(map));
			for (int k = 0; k < c.size(); k++)
				Convert(vc[k], c[k]);

			if (Check())
			{
				answer = vc.size();
				flag = true;
				return;
			}

		} while (next_permutation(c.begin(), c.end()));
	}
}

void DFS(int idx, int cnt, int target)
{
	if (flag)
		return;

	if (cnt == target)
	{
		Setting();
		Simulation();
		return;
	}

	for (int i = idx; i <= D; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			DFS(i, cnt + 1, target);
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//	freopen("film.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> D >> W >> K;
		for (int i = 1; i <= D; i++)
		{
			for (int j = 1; j <= W; j++)
				cin >> map[i][j];
		}

		answer = 0, flag = false;
		for (int k = 0; k <= D; k++)
		{
			memcpy(tmp, map, sizeof(map));
			if (k == 0)
			{
				if (Check())
					break;
				else
					continue;
			}
			memset(visit, false, sizeof(visit));
			DFS(1, 0, k);
			if (flag)
				break;
		}

		cout << "#" << t << " " << answer << endl;
	}
}