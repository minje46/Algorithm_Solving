#include<iostream>
#include<memory.h>
//#pragma warning(disable:4996)
#define MAX 1001

using namespace std;

int N, M;									// N = The width of map.				M = The height of map.
bool visit[MAX][MAX];				// visit = The memory of visited or not.
int answer;								// answer = The number of available places as output.

int Count()			// To count the number of available places.
{
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
				cnt++;
		}
	}
	return cnt;
}

void Simulation()			// To chekc available places in simulation.
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j])				// Inavailable place.
				continue;

			if (i + 2 < M)				// Avoid overflow.
				visit[i + 2][j] = true;		
			if (j + 2 < N)				// Distance from current to destination : 2
				visit[i][j + 2] = true;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

//	freopen("input.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(visit, false, sizeof(visit));
		answer = 0;

		cin >> N >> M;

		Simulation();
		answer = Count();

		cout << "#" << t << " " << answer << endl;
	}
}
