# Dynamic Programming

- **Dynamic programming은 처음 문제를 더 작은 문제들로 나눈뒤 각 조각의 답을 계산하고, 이를 활용하여 원래 문제에 대한 답을 얻는 방식.**

------

## 1. LIS (Longest Increasing Subsequence)

- **LIS는  주어진 수열 내에서 가장 긴 부분 수열을 찾아내는 algorithm.**

  > **Algorithm**
  >
  > 1. **`lis[]` array가 empty라면, 수열의 첫 번째 값 저장.**
  > 2. **`lis[]` array의 가장 큰 값(마지막 index)보다 큰 수열의 값을 `lis[]`에 추가.**
  > 3. **`lis[]` array의 가장 큰 값보다 작은 수열의 값은, `lower_bound()`를 통해 저장.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   int lower_bound(int start, int end, int *arr, int target)	// Binary search
  >   {
  >       int mid;
  >       while(end-start>0)		
  >       {
  >           mid = (start+end)/2;
  >           if(arr[mid]<target)		// Go right.
  >               start = mid+1;		
  >           else 					// Go left.
  >               end = mid;
  >       }
  >       return end+1;
  >   }
  >   
  >   void LIS()
  >   {
  >       int idx = 0;
  >       for(int i=0; i<N; i++)
  >       {
  >           if(i==0)					// #1. lis array is empty.
  >               lis[idx++] = arr[i];
  >           	
  >           if(lis[idx] < arr[i])		// #2. Input data is bigger than lis.
  >               lis[idx++] = arr[i];
  >           else 						// #3. Compare the lis array.
  >           {
  >               int pos = lower_bound(0, idx, lis, arr[i]);
  >               lis[pos-1] = arr[i];
  >           }
  >       }
  >   }
  >   ```
  >
  >   

- **Feature**

  ><img width="302" alt="lis" src="https://user-images.githubusercontent.com/23169707/74341769-9b841780-4deb-11ea-82b1-d5ba3e650999.png">
  >
  >→ **`lis[]` array에 작은 값을 저장하기 위해 `binary_search`를 활용.**
  >
  >* **Time complexity**
  >
  >$$
  >O(N log N)
  >$$
  >
  >

