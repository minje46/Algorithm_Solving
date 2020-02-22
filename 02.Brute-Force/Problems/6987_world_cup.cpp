#include<iostream>

#define CASE 4
#define TEAM 6
#define MAX 3

using namespace std;

int A[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };		// The whole of cases team A and B could match.
int B[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };		// [두 개의 팀이 matching 될 수 있는 모든 경우의 수.]
int map[TEAM][MAX];											// map = The memory of team's score.
int tmp[TEAM][MAX];											// tmp = The memory of all possible cases.
bool answer[CASE];											// answer = The memory of brute force's result.

bool Check()							// To figure out those have same possibility or not.
{
	for (int i = 0; i < TEAM; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (map[i][j] != tmp[i][j])
				return false;
		}
	}
	return true;
}
	
void DFS(int idx, int cnt)			// To figure out the whole of cases.
{
	if (cnt >= 15)
	{
		if (!answer[idx] && Check())
			answer[idx] = true;
		return;
	}

	int a = A[cnt], b = B[cnt];	
	tmp[a][0] += 1;	tmp[b][2] += 1;
	DFS(idx, cnt + 1);
	tmp[a][0] -= 1;	tmp[b][2] -= 1;

	tmp[a][1] += 1;	tmp[b][1] += 1;
	DFS(idx, cnt + 1);
	tmp[a][1] -= 1;	tmp[b][1] -= 1;

	tmp[a][2] += 1;	tmp[b][0] += 1;
	DFS(idx, cnt + 1);
	tmp[a][2] -= 1;	tmp[b][0] -= 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	for (int k = 0; k < CASE; k++)					// Case 1~4
	{
		for (int i = 0; i < TEAM; i++)					// Team A~F
		{
			for (int j = 0; j < MAX; j++)				// Win, Draw, Lose
				cin >> map[i][j];
		}

		DFS(k, 0);
	}
	for (int k = 0; k < CASE; k++)
		cout << answer[k] << " ";
	cout << endl;
}
