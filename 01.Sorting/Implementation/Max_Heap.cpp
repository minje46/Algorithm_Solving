#include<iostream>
#include<algorithm>
#include "Max_Heap.h"

#define INF 987654321

using namespace std;

heap hp;

void Init()										// To do initialize the heap.
{
	hp.arr[0] = INF;							// Do not use index 0.
	hp.size = 0;
}

void Insert(int key)							// Insert the key value in heap.
{
	hp.size++;

	int idx = hp.size;							// #1. Insert the new node at last location.
	hp.arr[idx] = key;

	while (idx != 1)							// #2. Compare the key value with parent node until root node.
	{
		if (hp.arr[idx] > hp.arr[idx / 2])
		{
			swap(hp.arr[idx], hp.arr[idx / 2]);
			idx /= 2;								// The index of parent node.
		}
		else
			break;
	}
}

int Delete()									// Delete the key value in heap.
{
	int max_value = hp.arr[1];			// The maximum value to return.
	hp.arr[1] = 0;								// #1. Delete the root node at first.

	int idx = 1;
	hp.arr[idx] = hp.arr[hp.size];		// #2. Move the last node to root node.
	hp.size--;

	while (idx * 2 <= hp.size)				// #3. Compare the key value with children node until leaf node.
	{
		int big;									// Find the bigger one between left and right child node.
		if (hp.arr[idx * 2] > hp.arr[idx * 2 + 1])
			big = idx * 2;						// The index of left child.	
		else
			big = idx * 2 + 1;					// The index of right child.

		if (hp.arr[big] > hp.arr[idx])
		{
			swap(hp.arr[big], hp.arr[idx]);
			idx = big;
		}
		else
			break;
	}
	return max_value;
}