# Dynamic programming

- **Dynamic programming is soving the problem with dividing from big to small.**

  <br>(다이나믹 프로그래밍은 큰 문제를 작은 문제로 나눠서 푸는 알고리즘이다.)

  > → 큰 문제를 작은 문제로 나눈다는 측면에서 Divide and Conquer (분할정복) algorithm과 비슷할 수 있지만, 차이점은 존재한다.
  >
  > <img width="436" alt="dp dac" src="https://user-images.githubusercontent.com/23169707/50848453-2c570c80-1329-11e9-95eb-8159b38d46df.png">

- **Overlapping Subproblem. [겹치는 부분 문제]**

  > * Large problem and small problem are realtive. 
  >
  >   [큰 문제와 작은 문제는 상대적이다.]
  >
  > * Problems are able to be divided in small scale.
  >
  >   [문제를 작은 문제로 쪼갤 수 있다.]

- **Optimal Substructure. [최적 부분 구조]**

  > * If it fits optimal structure, problem's solution is steady all the times.
  >
  >   [Optimal structure를 만족한다면, 문제의 크기에 상관없이 어떤 한 문제의 정답은 일정하다.]
  >
  > * Solution is inferred from small problem.
  >
  >   [문제의 정갑을 작은 문제의 정답에서 구할 수 있다.]

- **Memoization.**

  > → Memo the solution after solved. [정답을 한 번 구한 뒤에 메모를 한다.]
  >
  > * **Dynamic programming should be solved once. **
  >
  >   [DP에서 각 문제는 한 번만 풀어야 한다.]
  >
  >   → Optimal structure를 만족하기 때문이다.
  >
  > OR.
  >
  > → **Cashing** : Load the value when it is needed. [필요한 경우, 계산없이 값을 호출한다.]
  >
  > ![image](https://user-images.githubusercontent.com/23169707/50849391-bef8ab00-132b-11e9-9dfd-4f5d60699d8d.png)

- *Ex) Fibonnaci(N)*

<img width="596" alt="fibonacci" src="https://user-images.githubusercontent.com/23169707/50849167-0c284d00-132b-11e9-8d68-8da70d5e2dce.png">

> Problem.)  f(3) 과 f(2)처럼 겹치는 호출이 발생한다.
>
> ​		→ 한 번 답을 구할 때, 어딘가에 메모를 해놓고 중복 호출일때 메모해놓은 값을 리턴한다.



- **Top - Down**

  > 1. 문제를 작은 문제로 나눈다.
  > 2. 작은 문제를 푼다.
  > 3. 작은 문제들의 답으로 전체 문제를 푼다.
  >
  > → **Using Recursive method.**
  >
  >
  >
  > Ex) Q. Fibonacci(N)
  >
  > 1. Fibonacci(N-1) 과 Fibonacci(N-2)로 문제를 나눈다.
  > 2. Fibonacci(N-1)과 Fibonacci(N-2)를 호출해 문제를 푼다.
  > 3. Fibonacci(N-1)의 값과 Fibonacci(N-2)의 값을 더해 문제를 푼다.

- **Bottom - UP**

  > 1. 가장 작은 문제부터 푼다.
  > 2. 문제의 크기를 점점 크게 만들면서 문제를 푼다.
  > 3. 작은 문제를 풀면서 왔기 때문에, 전체 문제를 풀 수 있다.
  >
  >
  >
  > ![image](https://user-images.githubusercontent.com/23169707/50849432-e0f22d80-132b-11e9-8a77-98791e1f2256.png)
  >
  >
  >
  > Ex) Q. Fibonacci(N)
  >
  > 1. for(int i=2; i<=N; i++) 가장 작은 문제부터.
  > 2. for(int i=2; i<=N; i++) 문제의 크기를 증가.
  > 3. d[i]=d[i-1]+d[i-2]; 작은 문제를 푼다.
  > 4. d[n] 전체 문제를 풀 수 있다.
  >
  > ![image](https://user-images.githubusercontent.com/23169707/50849492-0da64500-132c-11e9-8374-5a29d8b84e8a.png)



