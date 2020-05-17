#include<iostream>
#include<memory.h>

#define MAX 6

using namespace std;

int colors[MAX];										// colors = The number of each size's color papers.
int paper[400][MAX][MAX];						// paper = The number of board to paste.
int answer = 0;										// answer = The total number of boards to paste all of color papers.

bool Check()		// Whethr it used all of color papers or not.
{
	for (int i = 0; i < MAX - 1; i++)
	{
		if (colors[i] > 0)
			return false;
	}
	return true;
}

void Paste(int idx, int y, int x, int k)		// To paste color paste on the current board.
{
	for (int i = y; i <= y + k; i++)
	{
		for (int j = x; j <= x + k; j++)
			paper[idx][i][j] = 1;
	}
}

bool Possible(int idx, int k)		// To figure out whether it has enough area or not.
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			bool flag = true;
			if (paper[idx][i][j] == 0 && i + k < MAX && j + k < MAX)		// [Paste 가능한, 시작 영역]
			{
				bool area = true;
				for (int y = i; y <= i + k; y++)
				{
					for (int x = j; x <= j + k; x++)
					{
						if (paper[idx][y][x] == 1)			// [Can't paste]
						{
							area = flag = false;
							break;
						}
					}
					if (!area)
						break;
				}
				if (flag)
				{
					Paste(idx, i, j, k);
					return true;
				}
			}
		}
	}
	return false;
}

void DFS(int cnt)		// To paste each color papers from big size to small one.
{
	if (Check())		// Base case.		
	{
		answer += cnt;
		return;
	}

	for (int i = 4; i >= 0; i--)		// From 5x5 size to 1x1 size.
	{										// [큰거부터 board에 paste 가능한지 확인하기]
		if (colors[i] > 0)				// [Greedy 선택 -> 최소 board 개수]
		{
			bool flag = false;			// [현재 가지고 있는 board 중에, i번째 size의 색종이 붙일 공간 있는지 확인]
			for (int j = 1; j <= cnt; j++)
			{
				if (Possible(j, i))		// [board에 붙일 수 있다면, next search]
				{
					colors[i]--;
					flag = true;
					DFS(cnt);			
					return;
				}
			}
			if (!flag)						// [board에 붙일 공간이 없다면, 새로운 board 추가]
			{
				Paste(cnt + 1, 0, 0, i);
				colors[i]--;
				DFS(cnt + 1);
				return;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	for (int i = 0; i < MAX; i++)
		cin >> colors[i];

	memset(paper, 0, sizeof(paper));
	int init = colors[5];			// Size 6x6 needs each different board.	
	DFS(1);

	cout << answer + init << endl;
}