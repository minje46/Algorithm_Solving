# Floyd-warshall	

- **Floyd warshall algorithm은 graph의 모든 vertex 사이의 shortest path를 구한다.**
  
  > **Algorithm**
  >
  > 1. **출발지에서 도착지까지의 path와 경유지를 거친 path와 비교한다.**
  >
  >    > **`min(dist[i][j], dist[i][k]+dist[k][j])`**
  >
  > * **Pseudo-code**
  >
  >   ```c++
  > void Floyd_warshall()
  >   {
  >       for (k = 1; k <= V; k++)		// k = 경유하는 Node.
  >       {	
  >           for (i = 1; i <= V; i++)	// i = Departure node.
  >           {
  >               for (j = 1; j <= V; j++)	// j = Destination node.
  >               {
  >                   if (dist[i][k] + dist[k][j] < dist[i][j])
  >                       dist[i][j] = dist[i][k] + dist[k][j];
  >               }
  >          }
  >       }
  >   }
  >   ```
  
- **Features**

  > - **negative cycle이 없어야 한다.**
  > - **negative value가 있어도 가능하다**


- **Time complexity.**

  > $$
  > O(V^3)
  > $$
  >

