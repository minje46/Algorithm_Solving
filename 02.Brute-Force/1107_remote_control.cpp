#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>

#define MAX 1000001
#define BTN 10
#define INF 987654321

using namespace std;

int N, M;												// N = The target number.				M = The number of broken button.
bool button[BTN];								// button = The memory of button is able to use or not.

bool Check(int num)		// To figure out whether the number could be clicked with buttons.
{									// [Button���� num�� ���� ���� ���θ� Ȯ��.]
	string digits = to_string(num);
	for (int i = 0; i < digits.length(); i++)
	{
		int idx = digits[i] - '0';
		if (!button[idx])
			return false;
	}
	return true;
}

int Count(int num)		// To figure out the length of number. 
{
	if (num == 0)			// Exception.
		return 1;

	return to_string(num).length();
}

int Simulation()		// To do exhaustive search whether the minimum nubmer of clicked button.
{
	int res = INF, num = INF;					// res = The total number of clicked.			num = The optimal channel number.
	for (int chn = 0; chn < MAX; chn++)
	{													// [From 0 to MAX, ��� channel�� Ȯ��.]
		if (Check(chn))							// Whetehr the channel is valid or not.
		{
			int cnt = abs(N - chn);				// [���� channel���� target channel������ +-�� �̵��ؾ� �ϱ� ����.]
			if (res > cnt)							// Uupdate.
			{
				res = cnt;
				num = chn;
			}
		}
	}

	return res + Count(num);					// [+-�� ������ cnt�� channel�� �����ϱ� ���� channel�� ����.]
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	memset(button, true, sizeof(button));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		button[num] = false;
	}
	
	cout << min(abs(N - 100), Simulation()) << endl;
}