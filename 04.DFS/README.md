# Graph Search

- **Graph search is searching every node** from start node to other nodes **in regular sequence.**

  <br>

  (그래프 탐색이란, 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문하는 것을 말한다.)

------

## 2. DFS (Depth-First-Search)

- **DFS is searching all depth of node in branch from root node.**

  <br>

  (깊이 우선 탐색이란, 루트 노드에서 시작해서 다음 분기(branch)로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법.)

  > → Root node로부터 left의 depth의 순서로 방문하는 전체 탐색 방식이라 말할 수 있다.

  ![bfs dfs](https://user-images.githubusercontent.com/23169707/48314840-d01a8980-e612-11e8-9298-514d7405dd8b.gif)

  > * Algorithm
  >
  >   <img width="373" alt="dfs" src="https://user-images.githubusercontent.com/23169707/48315541-01975300-e61b-11e8-8d46-3cc1a6b37a01.png">
  >
  >   1. Node v를 방문한다.
  >   2. Node v의 방문 여부를 확인한다. (true → skip / false → Node v를 방문)
  >   3. Node v에 인접한 node들 중 방문하지 않은 node가 있다면, v를 stack에 push.
  >   4. 인접한 node를 기준으로 recursive하게 1~3를 반복.
  >   5. 방문하지 않은 node가 없다면, Stack의 top을 pop.

- **Time complexity.**

  > `Number of Node(정점의 수) : N`
  >
  > `Number of Branch(간선의 수) : E`
  >
  > → Adjacent array로 표현된 Graph.
  > $$
  > O(N^2)
  > $$
  > → Adjacent list로 표현된 Graph.
  > $$
  > O(N+E)
  > $$
  >

- **DFS features.**

  > 1. **DFS is recursive algorithm.**
  > 2. DFS는 **node의 방문 여부를 반드시 check**해야 한다. (무한 loop의 위험.)
  > 3. Pre-Order Traversals을 포함한 다른 형태의 tree 순회는 모두 DFS의 종류이다.
  >
  > `Ex) 모든 node를 방문 하고자 할 때, 사용한다.`



------

## 2-1. Backtracking algorithm

- **Backtracking algorithm is a kind of exhaustive search though**, it has **pruning progress** to judge whether it is correct way or not.

  It is able to **improve the performance** depends on how **good pruning** is.

  <br>(백트래킹 알고리즘은 가지치기를 통해 가도되지 않는 루트는 고려하지 않고 탐색하는 완전 탐색 기법이다. 

  가지치기를 얼마나 잘하느냐에 따라서 효율이 극대화 될 수 있다.)

  <br>

  (백트래킹 알고리즘은 기본적으로 "가능한 모든 방법을 탐색한다"라는 것이 베이스가 된다.

  DFS와 같이 현재 지점에서 방문해야 하는 모든 곳을 재귀 호출을 통해 이동해야 하는 경우, 목표 지점이 있지 않은 경로로 빠지는 비효율적인 결과를 초래하게 된다.
  이렇게 비효율적인 경로를 차단하고 성능을 높이기 위함이 백트래킹 알고리즘이다.)

  >* Algorithm
  >
  >  <img width="360" alt="backtracking" src="https://user-images.githubusercontent.com/23169707/50479821-d080af80-0a1b-11e9-9eac-57c0a88582e6.png">
  >
  >  1. DFS : DFS 방식을 통해 node를 search한다.
  >
  >  2. Promising : Node에 대해 검사한다.
  >     → Visited node 인지 판단한다.
  >     → Promised node 인지 판단한다. (Search를 하는데 올바른 node.)
  >
  >  3. 
  >     → DFS : Promised node라고 판단 되었을 경우, DFS를 recursive하게 수행한다.
  >
  >     → Backtracking : Visited node를 pruning(가지치기)하고 상위 node로 backtracking 한다.