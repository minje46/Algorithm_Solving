#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct info
{
	string num;
	int s, b;
};

int N, answer;								// N = The number of responses.		answer = The number of possible cases.	
vector<info> rp;							// rp = The memory of response lists.

bool Check(int arr[])		// To figure out whether input can be possible choice or not.
{
	bool flag = true;
	for (int i = 0; i < N; i++)			// Given response lists.
	{
		int s = 0, b = 0;
		for (int j = 0; j < 3; j++)		// Compare option with response.
		{
			for (int k = 0; k < 3; k++)
			{									// [Input arr�� rp�� ���Ͽ� strike, ball counting]	
				if (arr[j] == (rp[i].num[k] - '0'))
				{
					if (j == k)
						s++;
					else
						b++;
					break;
				}
			}
		}										// [Input arr�� rp�� �����ϴ� strike�� ball�� ���� ��츸 possible choice�� �� �� �ִ�]	
		if ((s != rp[i].s) || (b != rp[i].b))	
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int Simulation()		// To set all kinds of number cases with three numbers.
{
	int arr[3] = { 0, }, cnt = 0;			// arr = The number set with three integers.
	for (int i = 1; i <= 9; i++)
	{
		arr[0] = i;
		for (int j = i + 1; j <= 9; j++)
		{
			arr[1] = j;
			for (int k = j + 1; k <= 9; k++)
			{
				arr[2] = k;
				do									// Combination set with arr.
				{
					if (Check(arr))				// [1-9�� ���� ���� ������ �־��� response list�� ��]
						cnt++;					// [��� ������ �����ϸ� answer �ĺ� �� �Ѱ���]
				} while (next_permutation(arr, arr + 3));
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		struct info tmp;
		cin >> tmp.num >> tmp.s >> tmp.b;
		rp.push_back(tmp);
	}
	
	answer = Simulation();

	cout << answer << endl;
}