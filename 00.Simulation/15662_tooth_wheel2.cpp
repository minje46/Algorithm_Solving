#include<iostream>
#include<vector>
#include<queue>

#define MAX 8

using namespace std;

int N, K;										// N = The nubmer of wheels.					K = The number of rotations.
char wheel[1001][8];					// wheel = The memory of each wheel's state.

void CW(int idx)		// To rotate in clock wise.
{
	queue<char>que;
	for (int i = 0; i < MAX; i++)
		que.push(wheel[idx][i]);
	for (int i = 1; i < MAX; i++)
		wheel[idx][i] = que.front(), que.pop();
	wheel[idx][0] = que.front();
}

void CCW(int idx)		// To rotate in counter clock wise.
{
	queue<char>que;
	for (int i = MAX - 1; i >= 0; i--)
		que.push(wheel[idx][i]);
	for (int i = MAX - 2; i >= 0; i--)
		wheel[idx][i] = que.front(), que.pop();
	wheel[idx][7] = que.front();
}

void Simulation(int dpt, int dir)		// To figure out each wheel's state.
{
	int d = dir;
	vector<pair<int, int>>vc;
	vc.push_back(make_pair(dpt, dir));		// The current wheel.
	for (int i = dpt; i < N - 1; i++)		// To right way.
	{
		d *= -1;
		if (wheel[i][2] == wheel[i + 1][6])
			break;
		vc.push_back(make_pair(i + 1, d));
	}

	d = dir;
	for (int i = dpt; i > 0; i--)				// To left way.
	{
		d *= -1;
		if (wheel[i][6] == wheel[i - 1][2])
			break;
		vc.push_back(make_pair(i-1, d));
	}
	
	for (int i = 0; i < vc.size(); i++)		
	{
		if (vc[i].second == 1)
			CW(vc[i].first);
		else
			CCW(vc[i].first);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < MAX; j++)
			cin >> wheel[i][j];
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int idx, dir;
		cin >> idx >> dir;
		Simulation(idx - 1, dir);
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (wheel[i][0] == '1')
			answer++;
	}
	cout << answer << endl;
}