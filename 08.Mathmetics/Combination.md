# Mathemetics

## 2. Combination(조합)

- 조합은 n개 중에서 r개를 선택할 수 있는 경우의 수.  (중복을 허용하지 않는다.)

  > ![image](https://user-images.githubusercontent.com/23169707/48901461-eb9a5580-ee98-11e8-830d-112b6123d34e.png)
  >
  > - Algorithm
  >
  >   → 공식에 기반하여 recursive function으로 구현.
  >
  >   → Recursive로 구현할 경우, 시간이 오래걸린다는 단점.
  >
  > - Pseudo - code
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



- **Formula.**

  > 1. First formula.
  >    $$
  >    n! / [(n-r)! * r!]
  >    $$
  >
  > 2. Second formula.
  >    $$
  >    nCr = n-1Cr-1 + n-1Cr
  >    $$
  >