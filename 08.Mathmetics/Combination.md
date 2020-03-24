# Combination(조합)

- **Combination은 서로 다른 n개 중에서 r개를 선택하는 것.**

  > **Algorithm**
  >
  > 1. s
  >
  > 2. s→ 공식에 기반하여 recursive function으로 구현.
  >
  >    → Recursive로 구현할 경우, 시간이 오래걸린다는 단점.
  >
  > * **Pseudo - code**
  >
  >   ```c++
  >   int Combination(int n, int r)
  >   {
  >   	if (n == r || r == 0)
  >   		return 1;
  >   
  >   	// nCr = (n-1)C(r-1) + (n-1)C(r)
  >   	return Combination(n - 1, r - 1) + Combination(n - 1, r);
  >   }
  >   ```
  >
  >   
  >
  > 
  
- **Features**

  > ![image](https://user-images.githubusercontent.com/23169707/48901461-eb9a5580-ee98-11e8-830d-112b6123d34e.png)

- **Formula.**

  > $$
  > n! / [(n-r)! * r!]
  > $$