# Convex Hull

- **The convex hull includes all sorts of points in minimum size of polygon.**

  <br>

  (컨벡스 헐이란, 여러 개의 점이 주어졌을 경우 모든 점들을 포함하는 최소 크기의 볼록 다각형을 말한다.)

  > → 2차원 평면상에 여러개의 점이 있을 때, 그 점 중에서 일부를 이용하여 convex hull을 만들되 convex hull 내부에 모든 점을 포함시키는 것.

  ![image](https://user-images.githubusercontent.com/23169707/54602418-fd75b900-4a84-11e9-8e96-45e70ecbc585.png)

------

## 2. Jarvis March

- **The jarvis march algorithm makes convex hull which includes all of points itself.**

  <br>

  (Jarvis march란 유한개의 점 중 다른 점을 가둘수 있는 외곽점을 찾는 알고리즘 중 하나이다.)

- > - Algorithm
  >
  >   1. Pivot을 설정한다. 
  >
  >      > → 오른쪽 제일 아래의 점.
  >
  >   2. Cross product(외적)을 이용하여 가장 각도가 작은 점을 구한다.
  >
  >      > → 모든 점을 다 찾아본다는 것이 point. 
  >      >
  >      > * March up : [y값이 양수이거나 0인 값만 고려한다.]
  >      > * March down : [y값이 음수이거나 0인 값만 고려한다.]
  >
  >   3. 2번 과정을 반복한다.
  >
  > - Psuedo-code
  >
  >   ```c++
  >   int jarvis(P)
  >   {
  >     i = 0
  >     p[0] = leftmost point of P
  >     do
  >       p[i+1] = point such that all other points in P are to the 
  >                                    right of the line p[i]p[i+1]
  >       i = i + 1
  >     while p[i] != p[0]
  >     
  >         return p
  >   }
  >   ```

- **Time complexity.**

  > $$
  > O(Nh)
  > $$
  >
  > → The number of points : O(h)
  >
  > → Find the next points : O(N)



------

## Cross product [외적]

![image](https://user-images.githubusercontent.com/23169707/54603273-3dd63680-4a87-11e9-975c-a75f513e6ef2.png)