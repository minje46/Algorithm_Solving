# Exhaustive Search

* **Exhaustive search is the way of checking all possibilities.**
  (완전탐색이란, 가능한 방법을 전부 확인해보는 방식을 말한다.)

  > `pros` : 항상 problem solving 가능.
  >
  > `cons` : 답을 찾는데 시간이 오래 걸린다.
  >
  > **Examples** : `Brute-force` / `Divide-conquer` / `Back tracking` / `Bit mask`

------

## 2. Divide & Conquer

- **Divide and conquer algorithm은 문제를 나눌 수 없을 때 까지 나누어서 각각을 풀면서 다시 합병하여 문제의 답을 얻는 방식.**

  > **Algorithm**
  >
  > 1. **Divide : 문제를 2개 이상의 문제로 나눈다.**
  >
  >    > 문제의 단위가 나누어지지 않을때 까지.
  >
  > 2. **Conquer : 가장 작은 단위의 문제를 해결한다.**
  >
  > 3. **Combine : Conquer한 문제들을 통합하며, 문제의 답을 구한다.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   // Array should be sorted in ascending order.
  >   void binary_search(int left, int right, int key)	// O(log N)
  >   {	
  >       int mid = (left+right) / 2;
  >       if(arr[mid] == key)		// Base case
  >           return;				// Search the key in array.	
  >       
  >       if(left >= right)		// Exception
  >           return;
  >       
  >       if(arr[mid] > key)		// Bigger than target key	
  >           binary_search(left, mid, key);
  >       else					// Smaller than target key
  >           binary_search(mid+1, right, key);
  >   }
  >   ```
  >
  >   → `binary_search`는 `divide-conquer`의 대표적인 algorithm.
- **Feature.**

  > <img width="391" alt="da" src="https://user-images.githubusercontent.com/23169707/73603823-0010cc80-45cb-11ea-90c0-fe4a196f4faa.png">
  >
  > `pros` : **Problem divide**를 통해, **어려운 문제를 해결**할 수 있다.
  >
  > `cons` : 반복되는 **Recursion** 때문에, **overhead**. 
  >
  > → **문제의 답이 중복으로 사용되지 않는 다는 점이 DP와의 차이점.**
  >
  > **Examples** : `binary-search` / `merge-sort` / `quick-sort`

