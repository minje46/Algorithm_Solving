# Permutation(순열)

- **Permutation은 서로 다른 n개 중에 r개를 선택하여, 순서있게 배열하는 것. **

  > **Algorithm**
  >
  > 1. r개 중에 각 자리에서 한 개씩 선택하는 것.
  > 2. start와 end point를 선택해서 swap. (처음에는 A가 start point 이자 end point.)
  > 3. 다음 자리로 넘어간다.
  > 4. 위의 1~3을 반복. (더 이상 자리에서 선택할 것이 없을 때가 경우의 수.)
  >
  > - **Pseudo - code**
  >
  >   ```c++
  >   void Permutation(n, r)
  >   {
  >    	if(r == 0)
  >           return;
  >       for(i=n-1; i>=0; i--)
  >       {
  >           swap(arr[i], arr[n-1]);	//순차적으로 자리를 바꾸는 것.
  >           permutation(n-1, r-1);
  >           swap(arr[i], arr[n-1]);
  >       }
  >   }
  >   ```

* **Features**

  > ![img](https://t1.daumcdn.net/cfile/tistory/215AFC35562B178E37)

- **Formula.**

  > $$
  > n! / (n-r)!
  > $$
  >
