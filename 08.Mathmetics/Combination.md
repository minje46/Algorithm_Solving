# Combination(조합)

- **Combination은 서로 다른 n개 중에서 r개를 선택하는 것.**

  > **Algorithm**
  >
  > 1. **Combination의 공식을 활용하여 recursive.**
  >
  > 2. **Base case(기저사례)의 경우 return.**
  >
  >    > `n==r` 과 `r==0`의 경우까지 recursive를 반복하기 때문에 **duplication** 과 **low speed**.
  >
  > * **Pseudo - code**
  >
  >   ```c++
  >   int Combination(int n, int r)
  >   {
  >   	if (n == r || r == 0)
  >   		return 1;
  >   	
  >       // nCr = (n-1)C(r-1) + (n-1)C(r)
  >   	return Combination(n - 1, r - 1) + Combination(n - 1, r);
  >   }
  >   ```
  >
  >   ![comb1](https://user-images.githubusercontent.com/23169707/77447707-506e1300-6e33-11ea-9082-cbb1c548c4f5.png)
  >
  >   → `nCr = (n-1)C(r-1) + (n-1)C(r)`의 성립을 가시적으로 증명.
  
- **Features**

  > ![image](https://user-images.githubusercontent.com/23169707/48901461-eb9a5580-ee98-11e8-830d-112b6123d34e.png)
  >
  > → **Duplication**이 발생하기 때문에, **low speed algorithm**.

- **Formula.**

  > $$
  > n! / [(n-r)! * r!]
  > $$