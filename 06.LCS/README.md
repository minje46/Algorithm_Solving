# Dynamic Programming 

* **Dynamic programming은 처음 문제를 더 작은 문제들로 나눈뒤 각 조각의 답을 계산하고, 이를 활용하여 원래 문제에 대한 답을 얻는 방식.**

------

## 2. LCS (Longest Common Subsequence)

- **LCS는 최장 공통 부분 문자열을 찾는 algorithm.**

  > `substring` : 연속된 부분 문자열.
  >
  > `subsequence` : 연속적이지 않은 부분 문자열.
  >
  > **Algorithm**
  >
  > 1. **`string str1`과 `string str2`를 비교하기 위해 `"0"`을 `insert`**.
  > 2. **두 개의 `string`을 비교하면서, 같은 문자일 경우, 최장 길이를 증가**.
  > 3. **두 개의 `string`이 다른 문자일 경우, `cache[][]`의 왼쪽과 위쪽의 값 중에서 큰 값을 저장**.
  >
  > - **Pseudo-code**
  >
  >   ```c++
  >   int cache[MAX][MAX];
  >   string s1="ACAYKP", s2="CAPCAK";
  >   int LCS(int i, int j)
  >   {
  >       memset(cache,0,sizeof(cache));
  >       string str1="0"+s1, str2="0"+s2;		// #1. Initialization
  >       for(int i=0; i<str1.length(); i++)
  >       {
  >           for(int j=0; j<str2.length(); j++)
  >           {
  >               if(i==0 || j==0)			
  >                   continue;
  >               
  >               if(str1[i] == str2[j])			// #2. Increase lcs
  >                   cache[i][j] = cache[i-1][j-1]+1;
  >               else							// #3. Load previous data.
  >                   cache[i][j] = max(cache[i-1][j],cache[i][j-1]);
  >           }
  >       }
  >   }
  >   ```
* **Feature**

  > ![image](https://user-images.githubusercontent.com/23169707/75038349-8ac55700-54f9-11ea-9ada-c22589ff7eff.png)
  >
  > → **`lcs`의 단어를 추출하기 위해 backtracking을 진행.**
  >
  > ```c++
  > stack<int> stk;
  > int i = str1.length()-1, j=str2.length()-1;
  > while(cache[i][j]!=0)		// From end ponit to start point
  > {
  >  if(cache[i][j]==cache[i][j-1])		// #1. Check left value	
  >      j--;
  >  else if(cache[i][j]==cache[i-1][j])	// #2. Check upper value
  >      i--;
  >  else if(cache[i][j]-1==cache[i-1][j-1])		// #3. Figure out lcs word
  >  {
  >      stk.push(i);
  >      i--;	j--;
  >  }
  > }
  > 
  > while(!stk.empty())
  > {
  >  cout << str1[stk.top()];
  >  stk.pop();
  > }
  > ```
  
* **Time complexity**

  > $$
  >O(NM)
  > $$