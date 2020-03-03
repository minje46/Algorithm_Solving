#include<iostream>

using namespace std;

int *arr;

void right(int start, int end)
{
	int last = arr[end];
	for (int i = end; i > start; i--)
		arr[i] = arr[i - 1];
	arr[start] = last;
}

void left(int start, int end)
{
	int first = arr[start];
	for (int i = start; i < end; i++)
		arr[i] = arr[i + 1];
	arr[end] = first;
}

void Permutation(int k, int m)
{
	if (k == m)
	{
		for (int i = 0; i <= m; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	else
	{
		for (int i = k; i <= m; i++)
		{
			right(k, i);							// Array의 숫자를 (start,end) 지점까지 오른쪽으로 이동시키면서, 
			Permutation(k + 1, m);			// Ordering이 가능하도록 한다.
			left(k, i);								// 오른쪽으로 이동시킨 것을 다시 왼쪽으로 이동시켜 기존의 array로 복구.
		}
	}
}

int main(void)
{
	int N, code;
	string str;

	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;

	Permutation(0, N - 1);
}