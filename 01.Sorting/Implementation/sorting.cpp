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
	{												// [가장 큰 값을 찾으며, 정렬]	
		for (j = 0; j < n - i - 1; j++)		// from first to sorted i'th element.
		{											// [sorted된 i'th 전까지 search]
			if (arr[j] > arr[j + 1])			// compare adjacent data.
				swap(arr[j], arr[j + 1]);
		}
	}
}

void Selection_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)				// pick the smallest element in each rotation.
	{												// [최솟값을 찾으며, 정렬]	
		int idx = i;
		for (j = i + 1; j < n; j++)		// from i'th to N'th.
		{											// [sorted된 i'th 이후부터 search]
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
	{												// [sorted된 elements 사이에서, 자신의 위치를 찾으며 정렬]
		int cur = arr[i];
		for (j = i - 1; j >= 0; j--)			// [sorted된 i'th 부터 search]		
		{											
			if (arr[j] > cur)					// [current보다 큰 element는 right shift.]
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
	{													// [splited된 array에서, insertion 위치 찾으며, 정렬.]
		int cur = arr[i];
		for (j = i - gap; j >= lf; j -= gap)	// [sorted된 i'th 부터 search]	
		{												
			if (arr[j] > cur)						// [current보다 큰 element는 right shift.]
				arr[j + gap] = arr[j];
			else
				break;
		}
		arr[j + gap] = cur;						// proper location. 
	}
}

void Shell_sort(int arr[], int n)
{
	int gap = n;		// [split 하기 위한 조건.]		
	while ((gap /= 2) > 0)
	{
		if (gap % 2 == 0)
			gap++;		// [gap은 홀수가 적합.]	

		for (int i = 0; i < gap; i++)
			Shell(arr, i, n - 1, gap);		// [splited array를 insertion sort.]
	}
}

void Heap_sort(int arr[], int n)			// Descending sort.
{
	heap hp;									// Max heap.
	
	Init();										
	for (int i = 0; i < n; i++)
		Insert(arr[i]);

	for (int i = 0; i < n; i++)					// [Heap에서 delete하는 순서 -> sorting]	
		arr[i] = Delete();						// Pop the root node from max heap.
}

void Merge(int arr[], int lf, int mid, int rt)		// Merge splited data.
{
	int lf_idx = lf, rt_idx = mid + 1;
	
	int *tmp = (int *)malloc(sizeof(int)*(rt + 1));			// Need extra memory.
	int idx = lf;
	while (lf_idx <= mid && rt_idx <= rt)		// Compare data.
	{														// [Splited left와 right의 elements 중에서, 작은 값을 찾으며 정렬.]
		if (arr[lf_idx] <= arr[rt_idx])
			tmp[idx++] = arr[lf_idx++];
		else
			tmp[idx++] = arr[rt_idx++];
	}

	if (lf_idx > mid)			// Reminder of right side.
	{
		for (int k = rt_idx; k <= rt; k++)			// [compare 이후, 남겨진 right side element copy.]
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
	int pivot = arr[lf];					// [pivot을 가장 왼쪽 값으로 지정.]
	int low = lf + 1, high = rt;			// [pivot+1의 index 와 right index.]

	while (low<=high)			// [두 개의 index가 교차하기 전까지 반복.]
	{
		while (pivot >= arr[low] && low <= rt)			// [pivot보다 큰 값을 right전까지 search]
			low++;														
		while (pivot <= arr[high] && high >= lf + 1)		// [pivot보다 작은 값을 pivot 이전의 left까지 search]
			high--;

		if (low <= high)				// [pivot 값을 기준으로, smaller는 left side, bigger는 right side에 위치시키기]
			swap(arr[low], arr[high]);
	}
	swap(arr[lf], arr[high]);		//	[low 와 high가 교차한 지점을 pivot과 swap.]
	return high;
}

void Quick_sort(int arr[], int lf, int rt)		// Split input data.
{
	if (lf <= rt)			// [sorted complete 기준.]
	{
		int pivot = Partition(arr, lf, rt);		// [split 기점]
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
		tmp[arr[i]]++;					// [element 갯수 counting.]
	
	int acc_cnt = -1;						// Set accumulative sum of counted element.
	for (int i = 0; i <= max_value; i++)
	{
		if (tmp[i] != 0)					// [누적합 갱신]
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
	queue<int> que[10];				// [Each digit 종류 만큼 bucket 필요 -> 10진수라서 10개]
	int ndiv = 1;							// ndiv = division value.

	for (int k = 0; k < len; k++)		// [maximum value's length 만큼 반복]
	{
		for (int i = 0; i < n; i++)
		{										// [Each digit을 구하고, 해당 digit의 bucket에 저장.]
			int radix = (arr[i] / ndiv) % 10;
			que[radix].push(arr[i]);
		}

		int idx = 0;
		for (int i = 0; i < 10; i++)
		{										// [Each digit's bucket에서 꺼내면서, 정렬.]
			while (!que[i].empty())
			{		
				arr[idx++] = que[i].front();
				que[i].pop();
			}
		}

		ndiv *= 10;							// For next digit.
	}
}
