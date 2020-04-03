#include<iostream>
#include<memory.h>
#include<vector>
#include<map>
#include<string>

#define MAX 51

using namespace std;

int N, M;														// N = The number of people.				M = The number of foods.
map<string, int>mp;									// mp = The map structure of <name, index>
vector<int> eat[MAX], food[MAX];				// eat = The foods i can eat.					food = The foods who can eat.
int tot[MAX];												// tot = The count of who can eat food.	
int answer;													// answer = The minimum set to serve foods.

void Init()			// To do initialize.
{
	memset(tot, 0, sizeof(tot));
	for (int i = 0; i < MAX; i++)
	{
		eat[i].clear();
		food[i].clear();
	}
	mp.clear();
	answer = MAX * MAX;
}

void DFS(int cnt)			// To figure out all of cases.
{
	if (cnt >= answer)				// Prunning.	
		return;

	int idx = 0;
	while (idx < N && tot[idx] > 0)
		idx++;
	if (idx == N)						// Base case.
	{
		answer = cnt;
		return;
	}

	for (int i = 0; i < eat[idx].size(); i++)			// [아직 먹을 음식이 없는 사람이 선택한 음식들 중에서]
	{
		int nxt = eat[idx][i];
		for (int j = 0; j < food[nxt].size(); j++)	// [해당 음식을 먹을 수 있는 다른 사람들 또한 check.]
			tot[food[nxt][j]]++;
		DFS(cnt + 1);
		for (int j = 0; j < food[nxt].size(); j++)
			tot[food[nxt][j]]--;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	
		Init();
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			mp.insert(make_pair(str, i));
		}
		for (int i = 0; i < M; i++)
		{
			int num;
			cin >> num;
			for (int j = 0; j < num; j++)
			{
				string str;
				cin >> str;
				food[i].push_back(mp[str]);			// 음식 : 먹을 수 있는 사람들 저장.
				eat[mp[str]].push_back(i);				// 사람 : 내가 먹을 수 있는 음식들 저장.
			}
		}

		DFS(0);
		cout << answer << endl;
	}
}