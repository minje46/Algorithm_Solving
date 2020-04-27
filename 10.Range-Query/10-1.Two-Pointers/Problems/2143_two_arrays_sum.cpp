#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1001

using namespace std;

int N, M, T; 								// N, M = The number of input data.				T = The target sum value.
int A[MAX], B[MAX];					// A, B = The memory of input data.
vector<int> sum_A, sum_B;			// sum_A, B = The memory of partial sum of A and B array.
long long answer = 0; 					// answer = The number of target value cases.

void Partial_sum()			// To calculate partial sum in A and B array.
{
	for (int i = 0; i < N; i++)
	{
		int sum = A[i];
		sum_A.push_back(sum);			// Partial sum of A array.
		for (int j = i + 1; j < N; j++)
		{
			sum += A[j];
			sum_A.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int sum = B[i];
		sum_B.push_back(sum);			// Partial sum of B array.
		for (int j = i + 1; j < M; j++)
		{
			sum += B[j];	
			sum_B.push_back(sum);		
		}
	}

	sort(sum_A.begin(), sum_A.end());
	sort(sum_B.begin(), sum_B.end());
}

void Simulation()			// To do range search based on two pointers algoritm.
{
	int lf = 0, rt = sum_B.size() - 1;
	while (true)
	{												// [�κ� ���� ��� ���ؼ� sum_A�� sum_B�� ������� two pointers algorithm]
		if (sum_A[lf] + sum_B[rt] == T)
		{	
			long long ca = 1, cb = 1;		// [T�� �� �� �ִ� sum_A�� �κ����� �� * sum_B�� �κ��� ���� ���Ѵ�]
			while (lf + 1 <= sum_A.size() - 1 && sum_A[lf] == sum_A[lf + 1])
			{										// [same sum value�� �����ϴ� ��� ���� count.]
				lf++;
				ca++;
			}

			while (rt - 1 >= 0 && sum_B[rt] == sum_B[rt - 1])
			{										// [same sum value�� �����ϴ� ��� ���� count.]
				rt--;
				cb++;
			}
			answer += (ca * cb);			// [�κ��� A�� ���� B���� ����� ���� �߻��� �� �ֱ� ������, multiplication]
			lf++;
		}

		if (lf <= sum_A.size() - 1 && rt >= 0 && sum_A[lf] + sum_B[rt] < T)			// Control left pointer.
			lf++;
		if (lf <= sum_A.size() - 1 && rt >= 0 && sum_A[lf] + sum_B[rt] > T)			// Control right pointer.
			rt--;
		if (lf > sum_A.size() - 1 || rt < 0)															// End condition.
			break;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;
	for (int j = 0; j < M; j++)
		cin >> B[j];

	Partial_sum();
	Simulation();

	cout << answer << endl;
}