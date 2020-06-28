#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 102

using namespace std;

int R, C, K;												// R = row.		C = column.		K = value.
int arr[MAX][MAX];									// arr = The memory of array.
int row = 3, col = 3;									// row = The memory of rows.		col = The memory of columns.

void R_computation()								// To figure out how many numbers are in each row.
{
	int max_col = 0;									// max_col = The maximum size of column after rotation.
	for (int i = 1; i <= row; i++)
	{
		int cnt[MAX] = { 0, };						// cnt = The temporary memory of count.
		for (int j = 1; j <= col; j++)
			cnt[arr[i][j]]++;

		vector<pair<int, int>> vc;					// vc = The temporary memory of number and count's pair.
		for (int k = 1; k < MAX - 1; k++)		// pair<int,int> = <count, number>
		{
			if (cnt[k] == 0)							// Exception. [None]
				continue;
			vc.push_back(make_pair(cnt[k], k));
		}
		sort(vc.begin(), vc.end());

		max_col = max(max_col, (int)vc.size() * 2);
		memset(arr[i], 0, sizeof(arr[i]));		// Initialization.
		int idx = 1;
		for (int k = 0; k < vc.size(); k++)
		{
			arr[i][idx++] = vc[k].second;		// Number.
			arr[i][idx++] = vc[k].first;			// Count.	
		}
	}
	col = max_col;									// Update the maximum column size.
}

void C_computation()								// To figure out how many numbers are in each row.
{
	int max_row = 0;									// max_col = The maximum size of column after rotation.
	for (int j = 1; j <= col; j++)
	{
		int cnt[MAX] = { 0, };						// cnt = The temporary memory of count.
		for (int i = 1; i <= row; i++)
			cnt[arr[i][j]]++;

		vector<pair<int, int>> vc;					// vc = The temporary memory of number and count's pair.
		for (int k = 1; k < MAX - 1; k++)		// pair<int,int> = <count, number>
		{
			if (cnt[k] == 0)							// Exception. [None]
				continue;
			vc.push_back(make_pair(cnt[k], k));
		}
		sort(vc.begin(), vc.end());

		max_row = max(max_row, (int)vc.size() * 2);
		for (int i = 1; i < MAX; i++)				// Initialization.
			arr[i][j] = 0;
		int idx = 1;
		for (int k = 0; k < vc.size(); k++)
		{
			arr[idx++][j] = vc[k].second;		// Number.
			arr[idx++][j] = vc[k].first;			// Count.	
		}
	}
	row = max_row;
}

int Simulation()										// To row and column rotation by simulation.
{
	int time = 0;
	while (time <= 100)
	{
		if (arr[R][C] == K)							// Base case.
			return time;

		if (row >= col)
			R_computation();
		else
			C_computation();

		time++;
	}
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}

	int answer = Simulation();

	cout << answer << endl;
}
