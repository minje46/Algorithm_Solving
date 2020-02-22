# Algorithm



------

## Greedy algorithm

- **Greedy algorithm is choosing the best option in each step.**

  <br>

  (그리디 알고리즘은 각 단계에 있어서 가장 좋은 것을 선택하는 방식이다.) 

  > * Algorithm
  >
  >   1. Selection procedure : 지금 순간에, 가장 최적인 옵션을 선택한다.
  >   2. Feasibility check : 선택한 옵션이 적절한지 검사한다.
  >   3. Solution check : 선택한 옵션 집합(locally solution set)이 문제의 답(globally solution)이 않았다면, 위의 1~2를 반복.
  >
  > * Pseudo - code
  >
  >   ```c++
  >   void Greedy(s, m, input)		// s = local_set(array)
  >   {    							//m = global_set(array)				
  >   	if(s == m)
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
  >   
  >   ```
  >

- **Locally optimal choice will lead to a globally optimal solution.**

  <br>

  (부분적인 최적의 선택이 결과적으로는 최적의 방법이 될것이라는 개념.)

  > → Greedy algorithm은 항상 optimal solution이 될 수는 없다.
  >
  > [knapsack problem, couting coins 와 같은 반례의 경우가 존재.]
  >
  > * Greedy algorithm 적용.
  >
  > ![image](https://user-images.githubusercontent.com/23169707/48900150-ef2bdd80-ee94-11e8-8777-725effcd286e.png)
  >
  > * Real optimal rotue.
  >
  >   ![image](https://user-images.githubusercontent.com/23169707/48900185-0b2f7f00-ee95-11e8-9e6c-58aee26be7cf.png)


- **Time complexity.**

  > $$
  > O(N^2)
  > $$
  >

- **Feature.**

  >1. Each step에서 지금 당장 the best option을 선택한다.
  >2. Greedy algorithm이 real optimal solution을 찾지 못하는 경우가 많다.
  >3. Locally optimal solution을 기반으로 performance time이 훨씬 빠르기에 유용하다.
  >4. 시간이나, 공간의 제약으로 인해 완전한 optimal solution을 찾기 어려울 경우 대안이 될 수 있다.