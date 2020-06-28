#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 11
#define INF 987654321

using namespace std;

int map[MAX][MAX];
int count[5] = { 5,5,5,5,5 };
int answer = INF;

bool Range(int ny, int nx)
{
	if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
		return false;
	return true;
}

bool Check(int y, int x, int k)
{
	for (int i = y; i <= y + k; i++)
	{
		for (int j = x; j <= x + k; j++)
		{
			if (!Range(i, j) || map[i][j] == 0)
				return false;
		}
	}
	return true;
}

void DFS(int y, int x, int cnt)
{

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 1)
				DFS(i, j, 0);
		}
	}

	if (answer == INF)
		answer == -1;
	cout << answer << endl;
}