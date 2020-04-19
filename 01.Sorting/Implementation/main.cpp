#include<iostream>
#include<cstdlib>
#include<ctime>
#include "sorting.h"

#define MAX 50

using namespace std;

int arr[MAX];										// The array memory which has unordered number.

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int a[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 100;
		a[i] = arr[i];
	}
	cout << "BEFROE SORTING" << endl;
	for (int i = 0; i < MAX; i++)
		cout << arr[i] << " ";
	cout << endl;

	// Baisc sort -> O(N^2)
	//Bubble_sort(arr, MAX);
	//Selection_sort(arr, MAX);
	//Insertion_sort(arr, MAX);
	//Shell_sort(arr, MAX);

	// Upper sort -> O(N logN)
	//Heap_sort(arr, MAX);			// Max heap -> Descending sort.
	//Merge_sort(arr, 0, MAX - 1);
	//Quick_sort(arr, 0, MAX - 1);

	// Special case sort -> O(N)
	//Counting_sort(arr, MAX);
	//Radix_sort(arr, MAX, 2);

	cout << "AFTER SORTING" << endl;
	for (int i = 0; i < MAX; i++)
		cout << arr[i] << " ";
	cout << endl;
}