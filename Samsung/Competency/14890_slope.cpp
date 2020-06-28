#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 101

using namespace std;

int N, L;									// N = The size of map.			L = The least length of slope.
int map[MAX][MAX];				// map = The memory of original map.
int answer = 0;

bool Move_right(int idx)
{
	pair<int, int>val = { map[idx][0], 0 };		// value, cnt.

	for (int j = 0; j < N; j++)
	{
		if (val.first == map[idx][j])
		{
			val.second += 1;
		}

		else if (val.first + 1 == map[idx][j])
		{
			if (val.second >= L)
			{
				val = { map[idx][j], 1 };
			}
			else
				return false;
		}

		else if (val.first - 1 == map[idx][j])
		{
			for (int k = 0; k < L; k++)			
			{
				if (map[idx][j + k] != val.first - 1)	
					return false;
			}
			val = { map[idx][j], 0 };
			j += L - 1;
		}

		else
			return false;
	}
	return true;
}

bool Move_down(int idx)
{
	pair<int, int>val = { map[0][idx], 0 };		// value, cnt.

	for (int j = 0; j < N; j++)
	{
		if (val.first == map[j][idx])
		{
			val.second += 1;
		}

		else if (val.first + 1 == map[j][idx])
		{
			if (val.second >= L)
			{
				val = { map[j][idx], 1 };
			}
			else
				return false;
		}

		else if (val.first - 1 == map[j][idx])
		{
			for (int k = 0; k < L; k++)
			{
				if (map[j + k][idx] != val.first - 1)
					return false;
			}
			val = { map[j][idx], 0 };
			j += L - 1;
		}

		else
			return false;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];			// Original map.
	}

	for (int i = 0; i < N; i++)
	{
		if (Move_right(i))
			answer++;

		if (Move_down(i))
			answer++;
	}

	cout << answer << endl;
}