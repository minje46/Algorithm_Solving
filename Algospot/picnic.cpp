#include<iostream>
#include<memory.h>

#define MAX 10

using namespace std;

int N, M;									// N = The number of students.					M = The number of student pairs.
bool map[MAX][MAX];			// map = The memory of input data.
bool visit[MAX];						// visit = The memory of visited or not.
int answer;								// answer = The number of combinations as output.

void DFS()			// To figure out whether combination is possible or not.
{
	int idx = -1;						// idx = The index of not matched student.
	for (int i = 0; i < N; i++)
	{
		if (!visit[i])
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)						// Base case. 
	{										// All of student are mathced.
		answer++;
		return;
	}

	for (int k = idx + 1; k < N; k++)		
	{										// [idx가 아직 matching되지 않은 students 중에서 가장 첫 index이기 때문에, idx+1부터 search.]
		if (!visit[k] && map[idx][k])
		{
			visit[k] = visit[idx] = true;
			DFS();
			visit[k] = visit[idx] = false;
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
		memset(map, false, sizeof(map));
		answer = 0;

		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = true;
			map[b][a] = true;
		}

		DFS();
	
		cout << answer << endl;
	}
}