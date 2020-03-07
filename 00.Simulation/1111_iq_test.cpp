#include<iostream>

#define MAX 51

using namespace std;

int N;												// N = The number of input data.	
int arr[MAX];									// arr = The memory of input data.

void Simulation()			// To figure out the rule of sequence.
{
	if (N == 1)									// Exception #1.
	{												// Every thing can be (a,b).			
		cout << "A" << endl;
		return;
	}
	
	else if (N == 2)							// Exception #2.
	{														
		if (arr[0] == arr[1])					// All sequence should have same value.
			cout << arr[0] << endl;
		else										// Same as Exception #1.
			cout << "A" << endl; 
		return; 
	}

	int a, b;
	if (arr[1] == arr[0])						// Avoid divide by zero.
		arr[0];
	else											// formula = num * a + b.
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);

	b = arr[1] - (arr[0] * a);				
	for (int k = 2; k < N; k++)
	{												// Wrong formula in a.
		if ((arr[k - 2] != arr[k - 1]) && (a != (arr[k] - arr[k - 1]) / (arr[k - 1] - arr[k - 2])))
		{
			cout << "B" << endl;
			return;
		}
		if (b != arr[k] - arr[k - 1] * a)
		{											// Wrong formula in b.
			cout << "B" << endl;
			return;
		}
	}

	cout << arr[N - 1] * a + b << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Simulation();
}