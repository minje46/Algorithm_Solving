#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include "Max_Heap.h"
#include "sorting.h"

using namespace std;

void Bubble_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)				// pick the biggest element at rotation.
	{												// [���� ū ���� ã����, ����]	
		for (j = 0; j < n - i - 1; j++)		// from first to sorted i'th element.
		{											// [sorted�� i'th ������ search]
			if (arr[j] > arr[j + 1])			// compare adjacent data.
				swap(arr[j], arr[j + 1]);
		}
	}
}

void Selection_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)				// pick the smallest element in each rotation.
	{												// [�ּڰ��� ã����, ����]	
		int idx = i;
		for (j = i + 1; j < n; j++)		// from i'th to N'th.
		{											// [sorted�� i'th ���ĺ��� search]
			if (arr[idx] > arr[j])				// the smallest one.
				idx = j;
		}
		swap(arr[i], arr[idx]);
	}
}

void Insertion_sort(int arr[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)						// find the proper location in each element.
	{												// [sorted�� elements ���̿���, �ڽ��� ��ġ�� ã���� ����]
		int cur = arr[i];
		for (j = i - 1; j >= 0; j--)			// [sorted�� i'th ���� search]		
		{											
			if (arr[j] > cur)					// [current���� ū element�� right shift.]
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = cur;						// proper location. 
	}
}

void Shell(int arr[], int lf, int rt, int gap)			// Complemented insertion sort.
{
	int i, j;											
	for (i = lf + gap; i <= rt; i += gap)		// find the proper location in each element.
	{													// [splited�� array����, insertion ��ġ ã����, ����.]
		int cur = arr[i];
		for (j = i - gap; j >= lf; j -= gap)	// [sorted�� i'th ���� search]	
		{												
			if (arr[j] > cur)						// [current���� ū element�� right shift.]
				arr[j + gap] = arr[j];
			else
				break;
		}
		arr[j + gap] = cur;						// proper location. 
	}
}

void Shell_sort(int arr[], int n)
{
	int gap = n;		// [split �ϱ� ���� ����.]		
	while ((gap /= 2) > 0)
	{
		if (gap % 2 == 0)
			gap++;		// [gap�� Ȧ���� ����.]	

		for (int i = 0; i < gap; i++)
			Shell(arr, i, n - 1, gap);		// [splited array�� insertion sort.]
	}
}

void Heap_sort(int arr[], int n)			// Descending sort.
{
	heap hp;									// Max heap.
	
	Init();										
	for (int i = 0; i < n; i++)
		Insert(arr[i]);

	for (int i = 0; i < n; i++)					// [Heap���� delete�ϴ� ���� -> sorting]	
		arr[i] = Delete();						// Pop the root node from max heap.
}

void Merge(int arr[], int lf, int mid, int rt)		// Merge splited data.
{
	int lf_idx = lf, rt_idx = mid + 1;
	
	int *tmp = (int *)malloc(sizeof(int)*(rt + 1));			// Need extra memory.
	int idx = lf;
	while (lf_idx <= mid && rt_idx <= rt)		// Compare data.
	{														// [Splited left�� right�� elements �߿���, ���� ���� ã���� ����.]
		if (arr[lf_idx] <= arr[rt_idx])
			tmp[idx++] = arr[lf_idx++];
		else
			tmp[idx++] = arr[rt_idx++];
	}

	if (lf_idx > mid)			// Reminder of right side.
	{
		for (int k = rt_idx; k <= rt; k++)			// [compare ����, ������ right side element copy.]
			tmp[idx++] = arr[k];
	}
	else							// Reminder of left side.
	{
		for (int k = lf_idx; k <= mid; k++)
			tmp[idx++] = arr[k];
	}

	for (int i = lf; i <= rt; i++)			
		arr[i] = tmp[i];		// Sorted data.
	free(tmp);
}

void Merge_sort(int arr[], int lf, int rt)			// Split input data.
{
	if (lf < rt)
	{
		int mid = (lf + rt) / 2;

		Merge_sort(arr, lf, mid);					// Left side.
		Merge_sort(arr, mid + 1, rt);				// Right side.

		Merge(arr, lf, mid, rt);						// Merge splited data.
	}
}

int Partition(int arr[], int lf, int rt)		// To figure out sorted pivot.
{
	int pivot = arr[lf];					// [pivot�� ���� ���� ������ ����.]
	int low = lf + 1, high = rt;			// [pivot+1�� index �� right index.]

	while (low<=high)			// [�� ���� index�� �����ϱ� ������ �ݺ�.]
	{
		while (pivot >= arr[low] && low <= rt)			// [pivot���� ū ���� right������ search]
			low++;														
		while (pivot <= arr[high] && high >= lf + 1)		// [pivot���� ���� ���� pivot ������ left���� search]
			high--;

		if (low <= high)				// [pivot ���� ��������, smaller�� left side, bigger�� right side�� ��ġ��Ű��]
			swap(arr[low], arr[high]);
	}
	swap(arr[lf], arr[high]);		//	[low �� high�� ������ ������ pivot�� swap.]
	return high;
}

void Quick_sort(int arr[], int lf, int rt)		// Split input data.
{
	if (lf <= rt)			// [sorted complete ����.]
	{
		int pivot = Partition(arr, lf, rt);		// [split ����]
		Quick_sort(arr, lf, pivot - 1);			// Left side.
		Quick_sort(arr, pivot + 1, rt);			// Right side.
	}
}

void Counting_sort(int arr[], int n)			// The maximum value is main point.
{
	int max_value = arr[0];			// max_value = The biggest value in input data.
	for (int i = 0; i < n; i++)
		max_value = max(max_value, arr[i]);

	int tmp[101], res[101];			// tmp = The memory of counting.		res = The memory of sorted element.
	memset(tmp, 0, sizeof(int)*(max_value + 1));
	for (int i = 0; i < n; i++)				// Counting each element.	
		tmp[arr[i]]++;					// [element ���� counting.]
	
	int acc_cnt = -1;						// Set accumulative sum of counted element.
	for (int i = 0; i <= max_value; i++)
	{
		if (tmp[i] != 0)					// [������ ����]
		{
			tmp[i] += acc_cnt;
			acc_cnt = tmp[i];
		}
	}

	for (int i = n - 1; i >= 0; i--)		// Sorting based on accumulative index.
		res[tmp[arr[i]]--] = arr[i];

	for (int i = 0; i < n; i++)				// Copy the sorted data.
		arr[i] = res[i];
}

void Radix_sort(int arr[], int n, int len)		// The maximum value's length is essential.
{
	queue<int> que[10];				// [Each digit ���� ��ŭ bucket �ʿ� -> 10������ 10��]
	int ndiv = 1;							// ndiv = division value.

	for (int k = 0; k < len; k++)		// [maximum value's length ��ŭ �ݺ�]
	{
		for (int i = 0; i < n; i++)
		{										// [Each digit�� ���ϰ�, �ش� digit�� bucket�� ����.]
			int radix = (arr[i] / ndiv) % 10;
			que[radix].push(arr[i]);
		}

		int idx = 0;
		for (int i = 0; i < 10; i++)
		{										// [Each digit's bucket���� �����鼭, ����.]
			while (!que[i].empty())
			{		
				arr[idx++] = que[i].front();
				que[i].pop();
			}
		}

		ndiv *= 10;							// For next digit.
	}
}
