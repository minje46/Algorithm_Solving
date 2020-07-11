# Minimum Spanning Tree

- **MST는 edge(간선)의 weight(가중치)를 고려하여 최소 비용의 spanning tree(신장 트리)를 선택하는 것.**

## 1. Kruskal 

- **Kruskal algorithm은 greedy method를 이용하여 edge의 weight를 최소 비용으로 연결한다.**
  
  > **Algorithm**
  >
  > 1. **Gapth의 edge(간선)들을 cost기준으로 ascending sort.**
  >
  > 2. **Sorted edge list에서 순서대로 minimum cost의 edge를 선택한다.**
  >
  > 3. **선택한 edge가 cycle을 형성하는지 확인**
  >
  >    > disjoint-set을 이용하여 확인
  >
  > 4. **Cycle을 형성하지 않는 edge는 MST set에 추가한다.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   int kruskal(int N)
  >   {
  >       uf.init(kn+1);
  >       sort(e.begin(),e.end());
  >       int ret = 0;     // 간선 가중치의 합의 최솟값
  >       for(auto now: e)
  >       {
  >           if(!uf.same_set(now.v1,now.v2))	// 두 정점의 연결 여부 확인
  >           { 
  >               ret+=now.cost;       // 가중치를 ret에 더함
  >               uf.merge(now.v1,now.v2); // 두 정점 연결
  >           }
  >       }
  >       return ret;
  >   }
  >   ```
  
- **Features**

  > - **union-find algorithm을 이용하는 경우, kruskal algorithm의시간복잡도는 edge sorting에 결정된다.**


- **Time complexity.**

  > $$
  >O(elogE)
  > $$

