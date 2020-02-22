# Greedy algorithm

- **Greedy algorithm은 각 단계에 있어서 가장 좋은 것을 선택하는 방식.**

  > **Algorithm**
>
  > 1. **`Selection procedure` : 지금 순간에, 가장 최적인 옵션을 선택한다.**
> 2. **`Feasibility check` : 선택한 옵션이 적절한지 검사한다.**
  > 3. **`Solution check` : 선택한 옵션 집합(locally solution set)이 문제의 답(globally solution)이 않았다면, 위의 1~2를 반복.**
  >
  > * **Pseudo - code**
  >
  >   ```c++
  >   void Greedy(s, m, input)		// EX.) Find shortest way
  >   {								// s = local_set(array)	
  >       if(s == m)					//m = global_set(array)		
  >           return 0;
  >       else
  >       {
  >       	for(i=0; i<input.length(); i++)
  >           {
  >               if(input[i] == shortest)	// Finding shortest way.           	
  >               {
  >               	s.push(input[i]);    
  >                   Greedy(s,m,input);
  >               }
  >           }
  >       }
  >   }
  >   ```
  > 


- **Feature.**

  > **Each step에서 best option(최선의 방법)을 선택.**
  > `pros` : Locally optimal solution을 기반으로 performance time이 훨씬 빠르기에 유용하다.
  >
  > `cons` : Real optimal solution을 찾지 못하는 경우가 많다.
  >
  > `example` : Prim algorithm / Kruskal algorithm / Dijkstra algorithm
  >
  > → **시간, 공간의 제약으로 인해 완전한 optimal solution을 찾기 어려울 경우 대안이 될 수 있다.**

- **Time complexity.**

  > $$
  > O(N^2)
  > $$
  >