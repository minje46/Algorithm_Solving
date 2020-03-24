# Permutation(순열)

- **Permutation은 서로 다른 n개 중에 r개를 선택하여, 순서있게 배열하는 것.**

  > **Algorithm**
  >
  > 1. **1부터 N까지 swap.**
  >
  >    > 시작되는 index 내부의 `for()`에서 1~N을 탐색하는 것.
  > 2. **N개가 되었을 때, 순열 출력.**
  >
  > - **Pseudo - code**
  >
  >   ```c++
  >   void Permutation(k, n)			// 중복 순열은 불가능.	
  >   {	// N개 중에서 N개를 나열하는 순열의 경우, `n!`의 경우의 수를 가진다.
  >    	if(k == n)					// Base case
  >           return;
  >       for(i=k; i<=n; i++)
  >       {
  >           swap(arr[k], arr[i]);	//순차적으로 자리를 바꾸는 것.
  >           permutation(k+1, n);
  >           swap(arr[k], arr[i]);
  >       }
  >   }
  >   ```
  >   
  >   ![perm_2 png](https://user-images.githubusercontent.com/23169707/77441118-67f5cd80-6e2c-11ea-8a84-1106919c48b7.jpg)
  >   
  >   → `for()`을 통해 순차적으로 증가하기 때문에, 중복된 수가 재사용되는 **중복순열**은 표현이 불가능.

* **Features**

  > ![per1](https://user-images.githubusercontent.com/23169707/77436645-1565e280-6e27-11ea-9f2b-b31066388bf8.png)

- **Formula.**

  > $$
  > n! / (n-r)!
  > $$
  >
