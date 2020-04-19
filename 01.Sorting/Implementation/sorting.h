#ifndef _Sorting_H			// if "_name.h" file is not defined,
#define _Sorting_H			// define "_name.h" file.	Then, do compile below code.

// O(N^2)
void Bubble_sort(int[], int);
void Selection_sort(int[], int);
void Insertion_sort(int [], int);
void Shell(int[], int, int, int);
void Shell_sort(int[], int);

// O(N log N)
void Heap_sort(int[], int);
void Merge(int[], int, int, int);
void Merge_sort(int[], int, int);
int Partition(int[], int, int);
void Quick_sort(int[], int, int);

// O(N) 
void Counting_sort(int[], int);
void Radix_sort(int[], int, int);

#else							// if not, do compile below code.

#endif