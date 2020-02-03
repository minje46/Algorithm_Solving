#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 4001
#define ARR 4

using namespace std;

int N;														// N = The size of arrays.	
long long map[ARR][MAX];						// map = The memory of input data.
vector<long long> sum;							// sum = The memory of the sum value from map[2][] + map[3][].		
long long answer = 0;								// answer = The number of sum zero as output.

void Simulation()			// To figure out the number of zero sum pairs.
{
	for (int i = 0; i < N; i++)						// Make data set to do binary search.
	{														// map[2][i] + map[3][j].
		for (int j = 0; j < N; j++)
			sum.push_back(map[2][i] + map[3][j]);
	}
	sort(sum.begin(), sum.end());				// For binary search.

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{													// tmp = map[0][i] + map[1][j].	
			long long tmp = map[0][i] + map[1][j];
															// [lf�� tmp ���� ��ġ�ϴ� ���� ���� index�� ��ȯ.]
			int lf = lower_bound(sum.begin(), sum.end(), -tmp) - sum.begin();
			int rt = upper_bound(sum.begin(), sum.end(), -tmp) - sum.begin();
															// [rt�� tmp ���� ��ġ�ϴ� ���� ������ index�� ��ȯ.]	
			if (tmp + sum[lf] == 0)				// [lower_bound�� upper_bound�� ��� ����� ������,
				answer += (rt - lf);					// ������ ���� tmp�� ������ �����ϴ� ���, ��� ������ count ���־�� �ϱ⶧��.]
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < ARR; j++)
			cin >> map[j][i];
	}

	Simulation();

	cout << answer << endl;
}