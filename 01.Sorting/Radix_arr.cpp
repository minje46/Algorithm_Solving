#include<iostream>
using namespace std;

#define Size 10000005
int arr[Size];

void Radix(int N, int div)
{
	int mod, k = 0;
	int **bucket = new int*[N];

	for (int i = 0; i < N; i++)		// Allocate memory dynamically.
	{
		bucket[i] = new int[10];
		memset(bucket[i], 0, sizeof(int) * 10);		// Initialize the value of bucket array with 0.
	}

	for (int i = 0; i < N; i++)		// Store the value depends on digit in bucket.
	{
		mod = (arr[i] / div) % 10;
		bucket[i][mod] = arr[i];
	}
	
	for (int i = 0; i < 10; i++)		// Search the smallest digit of value and swap the input array depends on digit.
	{
		for (int j = 0; j < N; j++)
		{
			if (bucket[j][i] != 0)
			{
				arr[k] = bucket[j][i];
				k++;
				bucket[j][i] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)		// Delete the dynamic memory of array.
		delete[] bucket[i];
	delete[] bucket;
}

void Sort(int N)
{
	int exp = 1, max = arr[0];

	for (int i = 0; i < N; i++)	// Search the max value in array for checking how many times loop should run.
	{
		if (max < arr[i])
			max = arr[i];	
	}

	while ((max / exp) > 0)	// Loop runs up	 to the largest digit of max value.
	{
		Radix(N, exp);
		exp *= 10;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);

	int N;						// Get the number of input.
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Sort(N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";
}