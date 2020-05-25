#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 11

using namespace std;

int map[MAX][MAX];								// map = The memory of input data.
bool visit[MAX];										// visit = The memory of visited or not.
int answer;												// answer = The maximum stats of team.

void DFS(int idx, int tot)		// To figure out all cases of permutation to make a team.
{
	if (idx == MAX)		// Base case.
	{
		answer = max(answer, tot);
		return;
	}

	for (int j = 0; j < MAX; j++)
	{
		if (!visit[j] && map[idx][j] > 0)
		{
			visit[j] = true;
			DFS(idx + 1, tot + map[idx][j]);
			visit[j] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				cin >> map[i][j];
		}

		answer = 0;
		DFS(0, 0);

		cout << answer << endl;
	}
}