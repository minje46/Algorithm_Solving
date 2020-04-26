#include<iostream>
#include<memory.h>
//#pragma warning(disable:4996)
#define MAX 1001

using namespace std;

int N;												// N = The size of map.
char map[MAX][MAX];					// map = The memory of input data.
int row[MAX], col[MAX];					// row, col = The memory of counting black stone's number.
int answer;										// answer = The minimum number of changed as output.

void Simulation()					// To count the number of how many times black stones are flipped.
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tot = row[i] + col[j];
			if (map[i][j] == 'B')				// Duplication.
				tot -= 1;

			if (tot % 2 == 1)		// If black stones are odd number, it should be counted as flipped.			
				answer++;			// [Stone을 flipped한 위치만, row + column의 black stone 수가 홀수로 유지된다.]
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
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		answer = 0;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'B')			// [Each row와 column에 존재하는 black stone의 개수를 저장.]
				{
					row[i]++;						
					col[j]++;
				}
			}
		}

		Simulation();

		cout << "#" << t << " " << answer << endl;
	}
}