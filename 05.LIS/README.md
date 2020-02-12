# Dynamic Programming

- **Dynamic programming is soving the problem with dividing from big to small.**

  <br>(다이나믹 프로그래밍은 큰 문제를 작은 문제로 나눠서 푸는 알고리즘이다.)

------

## 1. LIS (Longest Increasing Subsequence)

- **LIS is algorithm to find longest increasing subsequence.**

  <br>(LIS는 부분적으로 증가하는 수열 중 가장 긴 수열을 찾는 알고리즘이다.)

  > - Double loop : Easy way to implement LIS.
  >
  > - Lower bound : Efficient way to implement LIS.
  >
  >   > → Value가 insert 될 수 있는 위치들 중 가장 작은 index의 값을 찾아내는 방식이다. 

- Ex) 수열에서 Longest Increasing Subsequence를 구하기.

  ><img width="260" alt="lis" src="https://user-images.githubusercontent.com/23169707/51529665-02541e80-1dee-11e9-85fe-baae0f5508fb.png">

- Ex) LIS Source code.

  > - Code
  >
  > ```c++
  > int L[1001], len, N;
  > int main() 
  > {
  >     ios_base::sync_with_stdio(false);
  >     cin >> N;
  >     for(int i = 1; i <= N; ++i) 
  >     {
  >         int here;
  >         cin >> here;
  >         auto pos = lower_bound(L + 1, L + len + 1, here);
  >         *pos = here;
  >         if(pos == L + len + 1)
  >             len++;
  >     }
  >     cout << len;
  > }
  > ```



* Time complexity

  > $$
  > O(N^2) : Loop
  > $$
  >
  > $$
  > O(NlogN) : Loop, Binary search
  > $$
  >
  >