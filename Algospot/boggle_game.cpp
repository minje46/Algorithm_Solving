#include<iostream>
#include<memory.h>
#include<string>

using namespace std;

const int dy[8] = { -1,-1,-1,0,1,1,1,0 };
const int dx[8] = { -1,0,1,1,1,0,-1,-1 };

int N;													// N = The number of words.
char map[5][5];									// map = The memory of input data.
bool visit[11][5][5];							// visit = The memory of visited or not.
string word;										// word = The memory of boggle words.
bool flag;											// flag = Whether boggle is or not.

void DFS(int y, int x, int idx)			// To figure out each character to do boggle.
{
	visit[idx][y][x] = true;

	if (idx == word.length() - 1)		// Base case.
	{											// Word is boggle in map.
		flag = true;
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)			// Overflow.
			continue;

		if (!visit[idx + 1][ny][nx] && map[ny][nx] == word[idx + 1])			// Not visited yet. + Matched.
			DFS(ny, nx, idx + 1);
	}
}

int main(void)
{
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		for (int i = 0; i < 5; i++)
			cin >> map[i];
		
		cin >> N;
		for (int k = 0; k < N; k++)
		{
			cin >> word;
			
			memset(visit, false, sizeof(visit));
			flag = false;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (map[i][j] == word[0])
						DFS(i, j, 0);
				}
			}

			if (flag)
				cout << word << " YES" << endl;
			else
				cout << word << " NO" << endl;
		}
	}
}