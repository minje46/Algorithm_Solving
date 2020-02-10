#include<iostream>
using namespace std;

void Count(int arr[], int N, int exp)
{
	int *output = (int *)malloc(sizeof(int)*N);	// Allocate the size of array using malloc.
	int count[10] = { 0, };

	for (int i = 0; i < N; i++)
		count[(arr[i] / exp) % 10]++;			// Count the digit of input value based on radix sort.

	for (int i = 1; i < 10; i++)						// Index should start at least 1 because of addition index (i-1). 
		count[i] += count[i - 1];					// Build the accumulative count array.

	for (int i = N-1; i >= 0; i--)					// Count sorting accesses from the last value of array to the first value.
	{													// And finding the location which the value is set in output array based of the number of count in count array.
		output[count[(arr[i] / exp) % 10]-1] = arr[i];	// The value of count array means the index where the value is set in output array.
		count[(arr[i] / exp) % 10]--;			// After setting the value in output array, the count should be decreased because it means index.
	}

	for (int i = 0; i < N; i++)
		arr[i] = output[i];
}

void Radix(int arr[], int N)
{
	int exp = 1, max = arr[0];

	for (int i = 0; i < N; i++)	// Search the max value in array for checking how many times loop should run.
	{
		if (max < arr[i])
			max = arr[i];
	}

	while ((max / exp) > 0)	// Loop runs up	 to the largest digit of max value.
	{
		Count(arr, N, exp);
		exp *= 10;
	}
}

void Print(int result[], int N)
{
	for (int i = 0; i < N; i++)
		cout << result[i] << "\n";
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int *input = new int[N];	// Allocate the memory of input array in dynamically.

	for (int i = 0; i < N; i++)
		cin >> input[i];
	
	Radix(input, N);
	Print(input, N);

	delete []input;
}