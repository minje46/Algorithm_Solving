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
			right(k, i);							// Array�� ���ڸ� (start,end) �������� ���������� �̵���Ű�鼭, 
			Permutation(k + 1, m);			// Ordering�� �����ϵ��� �Ѵ�.
			left(k, i);								// ���������� �̵���Ų ���� �ٽ� �������� �̵����� ������ array�� ����.
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