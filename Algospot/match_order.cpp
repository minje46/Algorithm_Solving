#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;											// N = The number of players.
vector<int> vc[2];						// vc = The memory of input data.
int answer;									// answer = The maximum number of winning players.

void Greedy()
{
	for (int i = 0; i < 2; i++)
		sort(vc[i].begin(), vc[i].end(), greater<int>());

	while (!vc[0].empty())
	{
		if (vc[0][0] > vc[1][0])
		{
			vc
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
	{
		cin >> N;
		for (int i = 0; i < 2; i++)
		{
			int num;
			for (int j = 0; j < N; j++)
			{
				cin >> num;
				vc[i].push_back(num);
			}
		}

		Greedy();

		cout << answer << endl;
	}
}