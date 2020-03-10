# Convex Hull

- **The convex hull includes all sorts of points in minimum size of polygon.**

  <br>

  (컨벡스 헐이란, 여러 개의 점이 주어졌을 경우 모든 점들을 포함하는 최소 크기의 볼록 다각형을 말한다.)

  > → 2차원 평면상에 여러개의 점이 있을 때, 그 점 중에서 일부를 이용하여 convex hull을 만들되 convex hull 내부에 모든 점을 포함시키는 것.

  ![image](https://user-images.githubusercontent.com/23169707/54602418-fd75b900-4a84-11e9-8e96-45e70ecbc585.png)

------

## 1. Graham Scan

- **The graham scan algorithm makes convex hull which includes all of points itself.**

  <br>

  (Graham scan이란 유한개의 점 중 다른 점을 가둘수 있는 외곽점을 찾는 알고리즘 중 하나이다.)

- > - Algorithm
  >
  >   1. y 좌표가 가장 작은 점을 찾아서 pivot(P0)으로 설정한다.
  >
  >      > → y좌표가 같은 점이 존재할 경우, x좌표를 함께 비교해서 가장 작은 점을 선택한다.
  >
  >   2. pivot을 제외한 모든 점에 대하여 x축을 기준으로 오름차순`angle sort`를 한다. 
  >
  >      > → P[] 배열에 sorted points가 저장된다.
  >
  >   3. Stack에 pivot(P0)와 P[1]을 push.
  >
  >      > → Stack의 원소들은 CCW(Counter Clock Wise)으로 Convex한 성질을 유지한다.
  >
  >   4. Stack에 P[i]를 push. `[i~N까지]`
  >
  >      > a) Convex hull의 마지막 직선에서 P[i] 점이 왼쪽에 있으면 pop.
  >      > b) Convex hull의 마지막 직선에서 P[i] 점이 오른쪽에 있으면 push.
  >
  > - Psuedo-code
  >
  >   ```c++
  >   int N;	// Number of points.
  >   int points[N];	// The array of points.
  >   
  >   void Graham_Scan()
  >   {
  >       stack<int> stk;
  >   	Angle_sort(points[N]);	// Sort points by CCW.
  >       int pivot = Find_pivot(points[N]);	// Find the lowest y_coordinate.
  >       swap(points[0], points[pivot]);	// Make pivot points as p0.
  >           
  >       stk.push(p[0]);	stk.push(p[1]);	// First convex hull.
  >       for(int i=2; i<=N; i++)
  >       {
  >          while(stk.size() >= 2)
  >          {
  >              auto first = stk.top();	
  >              stk.pop();
  >              auto second = stk.top();
  >              if(!CCW(second, first, p[i]))	// point is located on right way
  >              {
  >                  stk.push(first);
  >                  break;
  >              }
  >          }
  >          stk.push(p[i]);
  >       }
  >   }
  >   ```

- **Time complexity.**

  > $$
  > O(NlogN)
  > $$
  >
  > → Pivot을 search : O(N)
  >
  > → Angle sort : O(NlogN)
  >
  > → Stack : O(N)



------

## Cross product [외적]

![image](https://user-images.githubusercontent.com/23169707/54603273-3dd63680-4a87-11e9-975c-a75f513e6ef2.png)