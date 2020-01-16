------

# Graph Search

* **Graph search is searching every node** from start node to other nodes **in regular sequence.**

  <br>

  (그래프 탐색이란, 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문하는 것을 말한다.)

------

## BFS (Breadth-First-Search)

- **BFS is searching adjacent node from root node to neighbor nodes.**

  <br>

  (너비 우선 탐색이란, 루트노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법을 말한다.)

  > → Root node로부터 height가 작은 node부터 차례대로 방문하는 전체 탐색 방식이라 말할 수 있다.

  ![bfs dfs](https://user-images.githubusercontent.com/23169707/48314840-d01a8980-e612-11e8-9298-514d7405dd8b.gif)

  > * Algorithm
  >
  >   <img width="433" alt="bfs" src="https://user-images.githubusercontent.com/23169707/48314999-49ff4280-e614-11e8-9b4d-90e9af8f0505.png">
  >
  >   1. Queue의 front를 pop.
  >   2. Pop한 node에 인접한 모든 node들 중 아직 방문하지 않은 node들을 queue에 push.
  >   3. Queue가 비어있지 않으면, 1번부터 다시 실행.

- **Time complexity.**

  > → Adjacent array로 표현된 Graph.
  > $$
  > O(N^2)
  > $$
  > → Adjacent list로 표현된 Graph.
  > $$
  > O(N+E)
  > $$
  >

- **BFS feature.**

  > 1. **BFS is not recursive.**
  > 2. BFS는 **node의 방문 여부를 반드시 check**해야 한다. (무한 loop의 위험.)
  > 3. BFS는 방문한 node들을 차례로 저장한 후 꺼낼 수 있는 자료구조 **Queue를 기반**으로 한다. **(FIFO원칙.)**
  > 4. BFS는 start node에서 시작해서 거리에 따라 **단계별로 searching** 하는 것이기 때문에 **not intuitive(직관적)**이지 않다. (`Prim algorithm` 과 `Dijkstra algorithm` 유사.)
  >
  > `Ex) 두 node 사이의 최단 경로 or 임의의 경로를 찾을 때 사용한다.`
