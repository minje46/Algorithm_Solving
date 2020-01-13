#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

#define MAX 16
#define BTN 10
#define INF 987654321

using namespace std;

int clocks[MAX];							// clocks = The memory of input data.
vector<int> button[BTN];				// button = The fixed button data which is connected to others.
int answer;									// answer = The number of pushed button as output.

void Init()		// To do initialize the button data is connected to other clocks.
{
	button[0] = { 0,1,2 };
	button[1] = { 3,7,9,11 };
	button[2] = { 4,10,14,15 };
	button[3] = { 0,4,5,6,7 };
	button[4] = { 6,7,8,10,12 };
	button[5] = { 0,2,14,15 };
	button[6] = { 3,14,15 };
	button[7] = { 4,5,7,14,15 };
	button[8] = { 1,2,3,4,5 };
	button[9] = { 3,4,5,9,13 };
}

bool Check()		// To figure out whether the clocks are synchronized or not.
{
	for (int i = 0; i < MAX; i++)
	{
		if (clocks[i] != 12)
			return false;
	}
	return true;
}

void Push(int idx)			// To change clocks with specific(idx) button.
{	
	for (int i = 0; i < button[idx].size(); i++)
	{
		clocks[button[idx][i]] += 3;

		if (clocks[button[idx][i]] > 12)			// Clock's feature.
			clocks[button[idx][i]] = 3;
	}
}

void DFS(int idx, int cnt)			// To do exhaustive search with specific button.
{
	if (idx == BTN)		// Base case. 
	{							// [Button�� 0~9���� �����ϹǷ�, 10�� overflow.]
		if (Check())			
			answer = min(answer, cnt);
		return;
	}

	for (int i = 0; i < 4; i++)		// [�ð� Ư����, 4�� ���� ���ڸ�.]
	{										// [�� �̻� Ž���� �ʿ� X.]
		DFS(idx + 1, cnt + i);		// [9~0�� ������ Ž��.]
		Push(idx);						// [0�� ȸ��, �ȵ����� �Ǵ� ��츦 ���� Ȯ���ϱ� ����, ��ȯ �Լ��� ���߿� ���.]
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	Init();

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(clocks, 0, sizeof(clocks));
		answer = INF;

		for (int i = 0; i < MAX; i++)
			cin >> clocks[i];

		DFS(0, 0);

		if (answer == INF)
			answer = -1;
		cout << answer << endl;
	}
}