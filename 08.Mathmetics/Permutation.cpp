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
			swap(arr[k], arr[i]);				// 각 자리수에서 두 인자 끼리만 swap해서 순차적인 순열은 불가능.
			Permutation(k + 1, m);				// swap 하는 두 인자 사이에 더 작은 값이 끼어 있을 수 있다.
			swap(arr[k], arr[i]);				// Ex) 1 2 3에서 1과 3만 swap 하기 때문에 {3 2 1}이 {3 1 2}보다 먼저 출력된다.
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