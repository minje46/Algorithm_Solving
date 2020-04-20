#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define MAX 101

using namespace std;

const int dy[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
const int dx[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };

int N, M;																// N, M = The size of map.		
char map[MAX][MAX];										// map = The memory of input data.
pair<int, int>dpt;													// dpt = The normal arduino's location.
vector<pair<int, int>>vc;										// vc = The memory of crazy arduino's location.
string instruction;													// instruction = The direction instruction to move.	

pair<int, int>Moved(int y, int x)			// To calculate crazy arduino's new location based on distance.
{
	int sy = y, sx = x, md = MAX * MAX;
	for (int k = 1; k < 10; k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		int dist = abs(ny - dpt.first) + abs(nx - dpt.second);
		if (dist < md)			// Shortest path.
		{
			sy = ny;
			sx = nx;
			md = dist;
		}
	}
	return make_pair(sy, sx);
}

int Simulation()			// To do 'Robots' game based on simulation.
{
	for (int i = 0; i < instruction.length(); i++)
	{
		int dir = instruction[i] - '0';
		dpt.first += dy[dir];			
		dpt.second += dx[dir];

		vector<pair<int, int>> nv;						// nv = The new movement of crazy arduino.
		int tmp[MAX][MAX] = { 0, };				// tmp = The temporary memory of crazy arduino's new movement.
		for (int k = 0; k < vc.size(); k++)			// Crazy arduino's moving time.
		{
			pair<int, int> pr = Moved(vc[k].first, vc[k].second);

			if (pr.first == dpt.first && pr.second == dpt.second)		// End condition.
				return i + 1;
			tmp[pr.first][pr.second]++;
			nv.push_back(pr);
		}

		vc.clear();
		for (int k = 0; k < nv.size(); k++)
		{
			if (tmp[nv[k].first][nv[k].second] == 1)
				vc.push_back(nv[k]);
		}
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'I')
				dpt = { i,j };
			else if (map[i][j] == 'R')
				vc.push_back(make_pair(i, j));
			map[i][j] = '.';
		}
	}
	cin >> instruction;

	int res = Simulation();
	if (res != -1)
		cout << "kraj " << res << endl;
	else
	{
		map[dpt.first][dpt.second] = 'I';
		for (int k = 0; k < vc.size(); k++)
			map[vc[k].first][vc[k].second] = 'R';

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << map[i][j];
			cout << endl;
		}
	}
}