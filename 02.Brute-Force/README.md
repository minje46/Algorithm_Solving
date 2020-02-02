# Exhaustive Search

- **Exhaustive search is the way of checking all possibilities.**

  (완전탐색이란, 가능한 방법을 전부 확인해보는 방식을 말한다.)

  > `pros` : 항상 problem solving 가능.
  >
  > `cons` : 답을 찾는데 시간이 오래 걸린다.
  >
  > **Examples** : `Brute-force` / `Divide-conquer` / `Permutation` / `Back tracking` / `Bit mask`
------

## 1. Brute-Force

- **Brute-force algorithm은 문제를 해결하기 위해, 가능한 모든 경우를 탐색하는 방식.**

  > **Algorithm**
  >
  > 1. **문제를 선형 구조로 구조화.**
  > 2. **구조화된 문제를 `nested-loop`를 통해 모두 탐색.**
  > 3. **적절한 해를 찾는다.**
  >
  > * **Psuedo-code**
  >
  >   ```c++
  >   void Brute_Force(int n)	// Ex : 자연수n의 약수들 합
  >    {
  >       int sum = 0;
  >       for(int i=1; i<=n; i++)
  >           sum += i;
  >    }
  >   ```
  >
  >   → `loop(반복문)`을 통해 모든 경우 탐색
  >
  >   → `if(조건문)`을 통해 적절한 해 선택
- **Feature.**

  > 1. **모든 경우 탐색하는** 무식한 방법이지만, **구현 Easy**.
  > 2. 자원이 충분한 경우, **이론상 가장 강력한 algorithm**.
  > 3. **Base algorithm**으로, **비교하는 기준**이 될 수 있다.
  >    (정확도 : 100%, 시간 복잡도 : n^2)
  >
  > **Examples** : `password hacking`

- **Time complexity.**

  >$$
  >O(N^2)
  >$$