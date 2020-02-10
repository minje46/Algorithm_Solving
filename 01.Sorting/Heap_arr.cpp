#include<iostream>
#define Size 1000005

using namespace std;
int arr[Size];

void Heap(int N, int i)
{
	int max = i;				// Initialize largest as root.
	int left = 2 * i + 1;		// left node.
	int right = 2 * i + 2;		// right node.

	// If left child is larger than root.
	if (left < N && arr[left] > arr[max])
		max = left;

	// If right child is larger than root.
	if (right < N && arr[right] > arr[max])
		max = right;

	// If largest value is not root node. It should be swapped.
	if (max != i)
	{
		swap(arr[i], arr[max]);

		// Recursively checking the sub tree of node which has largest value.
		Heap(N, max);		
	}
}

void Sort(int N)
{
	// Build max heap first.
	// (It is not perfect max heap. Just pick the biggest value in root node.)
	for (int i = N / 2 - 1; i >= 0; i--)	// i = N/2-1 means binary access.. i guess.
		Heap(N, i);

	// Swap the first node which is the biggest value and last node.
	// Build max heap again with reduced array. (The biggest value is located in tail of array.)
	// (Reduced array means from zero to last -1.)
	for (int i = N - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		Heap(i, 0);		// Compare with root node(index = 0) because of swapping right befroe.
	}
}

void Print(int N)
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	
	Sort(N);

	Print(N);
}