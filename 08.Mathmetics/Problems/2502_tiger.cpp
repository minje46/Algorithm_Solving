#include<iostream>

#define MAX 31

using namespace std;

int D, K;												// D = The number of days to spend.				K = The number of rice cake gave to tiger.
int fibo[MAX];										// fibo = The memory of fibonacci sequence.
int A = 0, B = 0;									// A,B = The start value as output.

void Simulation()				// To figure out the start fibonacci sequence values.
{
	fibo[1] = fibo[2] = 1;
	for (int i = 3; i < MAX - 1; i++)			// Basic state.
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	int num = 0;
	while (true)										// [Fibonnacci sequence pattern을 가지고 있기 때문에,
	{													//	a->b->a+b->a+2b->2a+3b...의 연산이 반복되고
		num++;										//  k=fibo[d-2]*a+fibo[d-1]*b 식을 구할 수 있다.]
		if ((K - (num*fibo[D - 2])) % fibo[D - 1])
			continue;								// [시작되는 정수 값을 찾는 것이기 때문에,	
														//  fibo[d-2]*a % fibo[d-1]*b = 0 이 되는 것이 답.]
		B = (K - (num*fibo[D - 2])) / fibo[D - 1];
		A = num;
		break;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> D >> K;

	Simulation();

	cout << A << endl << B << endl;
}