# Range Query <추후 업데이트>

- **Range query는 주어진 범위 내에서 search를 하기 위한 방식을 말한다.**

  > `pros` : `O(N^2)` 보다 빠른 성능으로 search가 가능하다.
  >
  > `cons` : 
  >
  > **Examples** : `two-pointers` / `sliding-window` / `segment-tree`
------

## 1. Two-Pointers

- **Two pointers algorithm은 2개의 pointer를 control하여 정답이 되지 않는 경우는 skip하면서 search하는 방식.**

  > **Algorithm**
  >
  > 1. **`start` 와 `end`의 2개의 pointer를 준비.**
  > 2. **`start <= end`를 만족하며 search.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   while(lf <= rt && rt < N) 
  >   {
  >       if (sum < M) 
  >       {
  >           if (rt < N)
  >           {
  >               rt++;
  >             sum += arr[rt];
  >           }
  >     }
  >       else if (sum >= M) 
  >       {
  >           if (lf <= rt) 
  >           {
  >               sum -= arr[lf];
  >               lf++;
  >           }
  >       }
  >   }
  >   ```
  >   
  
- **Feature.**

  > 1. **모든 경우를 탐색해야 하는 `O(N^2)` search를 `O(N)`으로 search할 수 있다.**
  > 2. **Range(범위)를 연속적으로 search하는 경우에만 사용할 수 있다.**

- **Time complexity.**

  >$$
  >O(N)
  >$$