# Exhaustive Search

- **Exhaustive search is the way of checking all possibilities.**

  <br>

  (완전탐색이란, 가능한 방법을 전부 확인해보는 방식을 말한다.)

  > * Various exhaustive search
  >   1. ***Brute force***
  >   2. Divide & conquer
  >   3. Permutation (time complexity : O(N!))
  >   4. Optimization Problems [TSP]
  >   5. BFS / DFS[Backtracking]Bit mask

------

## 1. Brute-Force

- **Brute force is algorithm checking all possibilities to solve the problem.**

  <br>

  (브루트포스 알고리즘은 문제를 해결하기 위해, 가능한 모든 경우를 직접 해보는 방식이다.)

- Check the whether pattern exists in text or not.

  <br>

  (길이가 n인 텍스트 T에서 길이가 m인 패턴 P를 찾는 간단한 방법.)

  >* Algorithm
  >
  >  1. Pattern P를 Text T에서 sequential search.
  >  2. 일치하는 pattern이 나오면 T의 연속된 다음 text를 P의 다음 pattern과 비교.
  >  3. 일치하는 pattern이 나오지 않는다면, T의 연속된 다음 text와 P의 첫 번째 pattern을 비교.
  >  4. 위의 2번과 3번을 반복한다.
  >
  >* Psuedo-code
  >
  >  ```c++
  >  void Brute_Force(T, P)
  >  {
  >  	for(i=0; i<T.length(); i++)
  >  	{
  >  		for(j=0; j<P.length(); j++)
  >  		{
  >  			if(T[i] != P[j])
  >  				return 0;
  >  		}
  >  	}
  >  
  >  }
  >  ```

- **Time complexity.**

  > $$
  > O(N^2)
  > $$
  >

- **Feature.**

  > 1. 모든 경우를 직접 확인하는 무식한 방법이지만, 구현이 쉽다.
  > 2. 자원이 충부한 경우에는, 이론상 최강의 알고리즘.
  > 3. 다른 algorithm의 비교 algorithm이 될 수 있다.
  >    (정확도 : 100%, 시간 복잡도 : n^2)