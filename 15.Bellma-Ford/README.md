# Bellman-Ford

- **Bellman-ford algorithm은 시작 vertex에서 모든 다른 vertex까지의 shortest path를 찾는다.**
  
  > **Algorithm**
  >
  > 1. **Relaxation을 V-1번 반복**
  >
  >    > vertex에서 이동 가능한 모든 path를 확인하며, cost 갱신하는 작업.
  >
  > 2. **Relaxation 이후, shortest path가 변경된다면 negative cycle 존재.**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  >    void Bellman_Ford()
  >   {
  >      // Init Single source.
  >       for(int i=1; i<=V; i++)
  >       {
  >           for(int j=1; j<=V; j++)
  >           {
  >               for(auto idx : graph[j])
  >               {	// RELAX Process.	
  >               	if(dist[idx.first] > idx.second + dist[j])
  >                   {
  >                       dist[idx.first] = idx.second + dist[j];
  >   					if (i == N)	// Shouldn't be updated.				
  >   						cycle = true;		
  >                   }
  >               }
  >           }
  >       }
  >   }
  >   ```
  
- **Features**

  > - **negative cycle이 없어야 한다.**
  > - **negative value가 있어도 가능하다**


- **Time complexity.**

  > $$
  > O(VE)
  > $$
  >

