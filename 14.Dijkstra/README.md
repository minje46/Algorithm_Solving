# Dijkstra

- **Dijkstra algorithm은 시작 vertex에서 모든 다른 vertex까지의 shortest path를 찾는다.**
  
  > **Algorithm**
  >
  > 1. **현재 vertex에서 adjacent node로 이동하는 비용을 저장**
  >
  > 2. **방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택**
  >
  > 3. **경유하는 비용을 비교하고, 갱신**
  >
  >    > dist[dst] > dist[cur]+cost(cur,dst)
  >
  > 4. **2~3번반복**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >   int dist[N];
  >   
  >   void Dijkstra(int dpt)
  >   {
  >       memset(dist, INF, sizeof(N));	dist[dpt] = 0;
  >       pq.push(make_pair(0, dpt));
  >        while(!pq.empty())
  >        {
  >            int cost = -pq.top().first;	// 경유하는 정점까지의 비용
  >            int cur = pq.top().second; 	// 경유하는 정점의 번호
  >            if(dist[here] < cost) 
  >                continue;
  >            for(int i = 0; i < adj[here].size(); i++)
  >            {
  >                int nxt = adj[cur][i].first; 
  >                int n_dist = cost + adj[cur][i].second; 
  >                if(dist[nxt] > n_dist)
  >                    dist[nxt] = n_dist;	pq.push(make_pair(-n_dist, nxt));
  >             }
  >        }
  >   }
  >   ```
  
- **Features**

  > - **negative cycle이 없어야 한다.**
  > - **negative value가 없어야 한다**


- **Time complexity.**

  > $$
  > O(ElogV)
  > $$
  >
  > **→ priority queue를 사용할 경우.**

