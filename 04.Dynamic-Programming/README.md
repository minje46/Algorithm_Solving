# Dynamic programming

- **Dynamic programming은 처음 문제를 더 작은 문제들로 나눈뒤 각 조각의 답을 계산하고, 이를 활용하여 원래 문제에 대한 답을 얻는 방식.**

  > **Algorithm**
  >
  > 1. **Memoization을 초기화한다.**
  >
  >    > `memset(cache, -1, sizeof(cache))`
  >
  > 2. **Base case(기저 사례)를 처리한다.**
  >
  > 3. **reference(참조형) 변수를 활용하여 memoization.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   // To figure out destination. 
  >   int cache[MAX][MAX];	// memory of memoization	
  >   
  >   int DFS(int y, int x)
  >   {
  >       if(y==N && x==N)	// Base case.
  >           return 1;
  >       if(y>N || x>N)		// Base case.
  >           return 0;
  >       
  >       int &ref = cache[y][x];
  >       if(ref != -1)
  >           return ret;
  >       
  >       return ret = (DFS(y+map[y][x],x) || DFS(y,x+map[y][x]));
  >   }
  >   ```

- **Feature.**

  > <img width="354" alt="s" src="https://user-images.githubusercontent.com/23169707/74040517-36a17980-4a07-11ea-895a-1fecef17ae9a.png">
  >
  > `memoization` : 한 번 계산한 값을 저장해 뒀다, 재활용하는 최적화 기법.
  >
  > `overlapping problem` : 두 번 이상 계산되는 부분 문제를 뜻한다.
  >
  > → **Memoization(계산 결과를 재활용)하여, Overlapping subproblem(중복되는 부분문제)를 해결하는 방식.**

* **vs. `Divide and Conquer`**

  > **Similarity** : `Dynamic programming` 과 `Divide and conquer`는 큰 문제를 작은 문제로 나눈뒤 각각의 문제를 해결하여 처음 주어진 문제의 답을 구한다는 동일한 접근 방식.
  >
  > **Difference** :  `Dynamic programming` 과 `Divide and conquer`는 문제를 나누는 방식에서 차이 발생.
  >
  > >  **`Dynamic programming`은 문제의 답을 여러 번 계산하지 않고, 계산 결과를 재활용한다.**
  > >
  > > <img width="436" alt="dp dac" src="https://user-images.githubusercontent.com/23169707/50848453-2c570c80-1329-11e9-95eb-8159b38d46df.png">





