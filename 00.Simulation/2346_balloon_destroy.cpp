#include<iostream>
#include<vector>

using namespace std;

int N;																		// N = The number of balloons.
vector<pair<int, int>>vc;											// vc = The memory of input data. [index, value]	
vector<int>answer;													// answer = The sequence of destroyed balloon.

void Simulation()
{
	int idx = 0, n = vc.size();
	while (true)
	{
		answer.push_back(vc[idx].first);					// The sequence of destroyed balloon's index.

		int num = vc[idx].second;							// num = The distance to move.
		if (num > 0)												// [����� ���, vector���� erase �ϴ� ���� ����Ͽ� -1 ��ŭ �̵�.]
			num--;

		vc.erase(vc.begin() + idx);							// To erase destroyed balloon.
		if (--n == 0)												// End condition.
			return;

		idx += num;
		if (idx < 0)													// Avoid underflow.
			idx = n + (idx % n);									// [���� ��ġ�� ����ؼ�, n(=vc.size) ���� ���� �� ��ŭ �̵�.]
		idx %= n;													// Aoid overflow.	
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		vc.push_back(make_pair(i, num));
	}

	Simulation();

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	cout << endl;
}