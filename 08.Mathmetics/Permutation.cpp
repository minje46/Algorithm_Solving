#include<iostream>
#include<vector>
#include<string>

using namespace std;

int *arr, idx = 0;
vector<pair<int, string>> P;

void Permutation(int k, int m)
{
	if (k == m)
	{
		string str = "";
		for (int i = 0; i <= m; i++)
			str.append(to_string(arr[i]));

		P.push_back({ idx++, str });
	}

	else
	{
		for (int i = k; i <= m; i++)
		{
			swap(arr[k], arr[i]);				// �� �ڸ������� �� ���� ������ swap�ؼ� �������� ������ �Ұ���.
			Permutation(k + 1, m);				// swap �ϴ� �� ���� ���̿� �� ���� ���� ���� ���� �� �ִ�.
			swap(arr[k], arr[i]);				// Ex) 1 2 3���� 1�� 3�� swap �ϱ� ������ {3 2 1}�� {3 1 2}���� ���� ��µȴ�.
		}
	}

}

int main(void)
{
	int N, code;
	string str;

	cin >> N;

	arr = new int[N];							// Allocate array memory dynamically.
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;							// It starts from 1 to N.

	Permutation(0, N - 1);

	for (int i = 0; i < P.size(); i++)
		cout << P[i].first << " : " << P[i].second << endl;
}