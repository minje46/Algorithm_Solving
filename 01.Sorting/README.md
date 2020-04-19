# Sorting

* **sorting algorithm의 성능은 `비교연산` 과 `데이터의 이동 횟수`를 근거로 판단한다.**

  > `비교연산` : data의 크기를 비교하는 연산 → **Big-O를 결정하는 기준**
  >
  > `데이터 이동` : data의 위치를 변경하기 위한 이동 → **세밀한 비교 가능**

* **elements 중에 같은 key 값을 가진 node가 여러개인 경우, element의 순서로 구분하는 경우가 존재할 수 있다.**

  > `stable` : elements의 순서가 sorting algorithm에 변경되지 않는다.
  >
  > `unstable` : elements의 순서가 sorting algorithm에 의해 변경된다. 

------

## 1. Bubble sort

* **Bubble sort는 인접한 두 개의 elements를 비교하며, 정렬하는 algorithm.**

  > ```c++
  > void Bubble_sort(int arr[], int n)		
  > {
  > 	int i, j;
  > 	for (i = 0; i < n - 1; i++)	// pick the biggest element at rotation.
  > 	{							// [가장 큰 값을 찾으며, 정렬]	
  > 		for (j = 0; j < n - i - 1; j++)		// from first to sorted i'th element.
  > 		{									// [sorted된 i'th 전까지 search]
  > 			if (arr[j] > arr[j + 1])		// compare adjacent data.
  > 				swap(arr[j], arr[j + 1]);
  > 		}
  > 	}
  > }
  > ```
  >
  > $$
  > O(N^2)
  > $$
  >
  > → **구현이 간단하고 stable sort이지만, `swap`의 overhead.**

## 2. Selection sort

* **Selection sort(선택 정렬)은 최솟값 element를 찾으며, 정렬하는 algorithm.**

  > ```c++
  > void Selection_sort(int arr[], int n)
  > {
  > 	int i, j;
  > 	for (i = 0; i < n - 1; i++)	// pick the smallest element in each rotation.
  > 	{							// [최솟값을 찾으며, 정렬]	
  > 		int idx = i;
  > 		for (j = i + 1; j < n; j++)			// from i'th to N'th.
  > 		{									// [sorted된 i'th 이후부터 search]
  > 			if (arr[idx] > arr[j])			// the smallest one.
  > 				idx = j;
  > 		}
  > 		swap(arr[i], arr[idx]);
  > 	}
  > }
  > ```
  >
  > $$
  > O(N^2)
  > $$
  >
  > → **최솟값을 찾으면 되기 때문에, 데이터 이동 횟수가 미리 결정되지만, unstable sort**

## 3. Insertion sort

* **Insertion sort(삽입 정렬)은 차례대로 정렬된 elements과 비교하여, 자신의 위치를 찾아서 삽입하며 정렬하는 algorithm.**

  > ```c++
  > void Insertion_sort(int arr[], int n)
  > {
  > 	int i, j;
  > 	for (i = 1; i < n; i++)	// find the proper location in each element.
  > 	{						// [sorted된 elements 사이에서, 자신의 위치를 찾으며 정렬]
  > 		int cur = arr[i];
  > 		for (j = i - 1; j >= 0; j--)	// [sorted된 i'th 부터 search]		
  > 		{											
  > 			if (arr[j] > cur)			// [current보다 큰 element는 right shift.]
  > 				arr[j + 1] = arr[j];
  > 			else
  > 				break;
  > 		}
  > 		arr[j + 1] = cur;				// proper location. 
  > 	}
  > }
  > ```
  >
  > $$
  > O(N^2)
  > $$
  >
  > → **stable sort이지만, input data가 얼마나 정렬되어 있는지에 따라 성능 차이가 심하다.**

## 4. Heap sort

* **Heap sort는 자료구조 heap의 root node를 이용하여 정렬하는 algorithm.**

  > ```c++
  > void Heap_sort(int arr[], int n)	// Descending sort.
  > {
  > 	heap hp;						// Max heap.
  > 	
  > 	Init();										
  > 	for (int i = 0; i < n; i++)
  > 		Insert(arr[i]);
  > 
  > 	for (int i = 0; i < n; i++)		// [Heap에서 delete하는 순서 -> sorting]		
  > 		arr[i] = Delete();			// Pop the root node from max heap.
  > }
  > ```
  >
  > $$
  > O(N log N)
  > $$
  >
  > → **input data의 전체 정렬이 아닌, 정렬된 부분 data가 필요할 때 유용하지만, unstable sort.**

## 5. Merge sort

* **Merge sort(병합 정렬)은 두 개의 균등한 크기로 분할하고, 분할된 부분 data를 정렬하는 divide and conquer 방식의 algorithm.**

  > ```c++
  > void Merge(int arr[], int lf, int mid, int rt)		// Merge splited data.
  > {
  > 	int lf_idx = lf, rt_idx = mid + 1;
  > 	
  > 	int *tmp = (int *)malloc(sizeof(int)*(rt + 1));	// Need extra memory.
  > 	int idx = lf;
  > 	while (lf_idx <= mid && rt_idx <= rt)			// Compare data.
  > 	{	// [Splited left와 right의 elements 중에서, 작은 값을 찾으며 정렬.]
  > 		if (arr[lf_idx] <= arr[rt_idx])
  > 			tmp[idx++] = arr[lf_idx++];
  > 		else
  > 			tmp[idx++] = arr[rt_idx++];
  > 	}
  > 
  > 	if (lf_idx > mid)		// Reminder of right side.
  > 	{	// [compare 이후, 남겨진 right side element copy.]
  > 		for (int k = rt_idx; k <= rt; k++)			
  > 			tmp[idx++] = arr[k];
  > 	}
  > 	else					// Reminder of left side.
  > 	{
  > 		for (int k = lf_idx; k <= mid; k++)
  > 			tmp[idx++] = arr[k];
  > 	}
  > 
  > 	for (int i = lf; i <= rt; i++)			
  > 		arr[i] = tmp[i];	// Sorted data.
  > 	free(tmp);
  > }
  > 
  > void Merge_sort(int arr[], int lf, int rt)		// Split input data.
  > {
  > 	if (lf < rt)
  > 	{
  > 		int mid = (lf + rt) / 2;
  > 
  > 		Merge_sort(arr, lf, mid);				// Left side.
  > 		Merge_sort(arr, mid + 1, rt);			// Right side.
  > 
  > 		Merge(arr, lf, mid, rt);				// Merge splited data.
  > 	}
  > }
  > ```
  >
  > $$
  > O(NlogN)
  > $$
  >
  > → **추가적인 memory가 요구되지만, stable sort.**

## 6. Quick sort

* **Quick sort는 pivot을 기준으로 data를 비균등하게 divide and conquer하며 정렬하는 algorithm.**

  > ```c++
  > int Partition(int arr[], int lf, int rt)	// To figure out sorted pivot.
  > {
  > 	int pivot = arr[lf];			// [pivot을 가장 왼쪽 값으로 지정.]
  > 	int low = lf + 1, high = rt;	// [pivot+1의 index 와 right index.]
  > 
  > 	while (low<=high)				// [두 개의 index가 교차하기 전까지 반복.]
  > 	{
  > 		while (pivot >= arr[low] && low <= rt)			
  > 			low++;		// [pivot보다 큰 값을 right전까지 search]
  > 		while (pivot <= arr[high] && high >= lf + 1)		
  > 			high--;		// [pivot보다 작은 값을 pivot 이전의 left까지 search]
  > 	// [pivot 값을 기준으로, smaller는 left side, bigger는 right side에 위치시키기]
  > 		if (low <= high)
  > 			swap(arr[low], arr[high]);
  > 	}
  > 	swap(arr[lf], arr[high]);		//	[low 와 high가 교차한 지점을 pivot과 swap.]
  > 	return high;
  > }
  > 
  > void Quick_sort(int arr[], int lf, int rt)		// Split input data.
  > {
  > 	if (lf <= rt)					// [sorted complete 기준.]
  > 	{
  > 		int pivot = Partition(arr, lf, rt);		// [split 기점]
  > 		Quick_sort(arr, lf, pivot - 1);			// Left side.
  > 		Quick_sort(arr, pivot + 1, rt);			// Right side.
  > 	}
  > }
  > ```
  >
  > $$
  > O(NlogN)
  > $$
  >
  > → **추가적인 메모리를 필요로 하지않으며, 평균적으로 가장 빠른 성능을 보장하지만, unstable sort이며 최악의 경우 성능은 `O(N^2)`이다.**

## 7. Counting sort

* **Counting sort(계수 정렬)는 elements의 등장 횟수를 count하고 누적 값을 이용하여 정렬하는 algorithm.**

  > ```c++
  > void Counting_sort(int arr[], int n)	// The maximum value is main point.
  > {
  > 	int max_value = arr[0];	// max_value = The biggest value in input data.
  > 	for (int i = 0; i < n; i++)
  > 		max_value = max(max_value, arr[i]);
  > 
  > 	int tmp[101];			// tmp = The memory of counting.
  > 	memset(tmp, 0, sizeof(int)*(max_value + 1));
  > 	for (int i = 0; i < n; i++)			
  > 		tmp[arr[i]]++;		// [element 갯수 counting.]
  > 	
  > 	int acc_cnt = -1;		
  > 	for (int i = 0; i <= max_value; i++)
  > 	{
  > 		if (tmp[i] != 0)	// [누적합 갱신]
  > 		{
  > 			tmp[i] += acc_cnt;
  > 			acc_cnt = tmp[i];
  > 		}
  > 	}
  > 
  >     int res[101];	// res = The memory of sorted element.
  > 	for (int i = n - 1; i >= 0; i--)		// Sorting.
  > 		res[tmp[arr[i]]--] = arr[i];
  > 
  > 	for (int i = 0; i < n; i++)				// Copy the sorted data.
  > 		arr[i] = res[i];
  > }
  > ```
  >
  > $$
  > O(N+K)
  > $$
  >
  > → **element의 크기를 비교하는 과정 없이,`element 개수+max_element`의 빠른 성능과 stable sort을 제공하지만, 성능과 메모리가 max_element에 종속적이다.**

## 8. Radix sort

* **Radix sort(기수 정렬)는 data를 구성하는 기본 요소인 radix(기수)를 비교하며 정렬하는 algorithm.** 

  > ```c++
  > void Radix_sort(int arr[], int n, int len)		// maximum value's length 필요.
  > {
  > 	queue<int> que[10];		// [Each digit 종류 만큼 bucket 필요 -> 10진수라서 10개]
  > 	int ndiv = 1;			// ndiv = division value.
  > 
  > 	for (int k = 0; k < len; k++)
  > 	{						// [maximum value's length 만큼 반복]
  > 		for (int i = 0; i < n; i++)
  > 		{					// [Each digit을 구하고, 해당 digit의 bucket에 저장.]
  > 			int radix = (arr[i] / ndiv) % 10;
  > 			que[radix].push(arr[i]);
  > 		}
  > 
  > 		int idx = 0;
  > 		for (int i = 0; i < 10; i++)
  > 		{					// [Each digit's bucket에서 꺼내면서, 정렬.]
  > 			while (!que[i].empty())
  > 			{		
  > 				arr[idx++] = que[i].front();
  > 				que[i].pop();
  > 			}
  > 		}
  > 
  > 		ndiv *= 10;			// For next digit.
  > 	}
  > }
  > ```
  >
  > $$
  > O(ln)
  > $$
  >
  > → **element의 크기를 비교하는 과정 없이,`element의 최대길이*element 개수`의 빠른 성능과 stable sort을 제공하지만, radix를 활용할 수 있는 제한적인 상황에서만 사용할 수 있으며 sorting 중간에 판단할 수 없다.**

## 9. Shell sort

* **Shell sort는 divide and conquer를 통해 insertion sort를 보완한 algorightm.**

  > ```c++
  > void Shell(int arr[], int lf, int rt, int gap)	// Complemented insertion sort.
  > {
  > 	int i, j;											
  > 	for (i = lf + gap; i <= rt; i += gap)
  > 	{	// [splited된 array에서, insertion 위치 찾으며, 정렬.]
  > 		int cur = arr[i];
  > 		for (j = i - gap; j >= lf; j -= gap)	// [sorted된 i'th 부터 search]	
  > 		{												
  > 			if (arr[j] > cur)		// [current보다 큰 element는 right shift.]
  > 				arr[j + gap] = arr[j];
  > 			else
  > 				break;
  > 		}
  > 		arr[j + gap] = cur;			// proper location. 
  > 	}
  > }
  > 
  > void Shell_sort(int arr[], int n)
  > {
  > 	int gap = n;		// [split 하기 위한 조건.]		
  > 	while ((gap /= 2) > 0)
  > 	{
  > 		if (gap % 2 == 0)
  > 			gap++;		// [gap은 홀수가 적합.]	
  > 
  > 		for (int i = 0; i < gap; i++)
  > 			Shell(arr, i, n - 1, gap);		// [splited array를 insertion sort.]
  > 	}
  > }
  > ```
  >
  > $$
  > O(N^2)
  > $$
  >
  > → **평균적인 성능은 insertion sort보다 빠르지만, 최악의 성능은 `O(N^2)`이며, gap만큼 이동하게되면서 unstable sort.**

## 10. Topological sort

* **Topological sort(위상 정렬)는 **

  > ```c++
  > ㄴ
  > ```
  >
  > s
  >
  > → **ㄴ ㄴㄴ**
