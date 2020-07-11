# Data Structure

# Minimum Spanning Tree

- **MST는 edge(간선)의 weight(가중치)를 고려하여 최소 비용의 spanning tree(신장 트리)를 선택하는 것.**

## 2. Prim 

- **Prim's algorithm은 시작 vertex(정점)에서 단계적으로 확장해나가며 MST를 만든다.**
  
  > **Algorithm**
  >
  > 1. **시작 vertex를 MST set에 추가한다.**
  > 2. **adjacent node 중에서 minimum cost를 가진 edge를 선택한다.**
  > 3. **N-1개의 edge까지 반복한다.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   int prim(int N)
  >   {
  >       int ret = 0;
  >       pq.push(make_pair(0,1));	// <cost : vertex>
  >       for(int i=1; i<=N; i++)
  >       {
  >           int now=-1, min_dist = INF;
  >           while(!pq.empty())
  >           {
  >               now = pq.top().second;
  >               if(!selected[now])
  >                   min_dist = pq.top().first;	break;
  >               pq.pop();
  >           }
  >           if(min_dist==INF) 
  >               return INF; // 연결 그래프가 아님
  >           
  >           ret+=min_dist;  selected[now] = true;   add_edge(now);
  >       }
  >       return ret;
  >   }
  >   ```
  
- **Features**

  > - **priority queue를 사용하여 성능을 높일 수 있다.**


- **Time complexity.**

  > $$
  >O(ElogV)
  > $$

