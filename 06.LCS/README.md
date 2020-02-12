# Dynamic Programming

* **Dynamic programming is soving the problem with dividing from big to small.**

  <br>(다이나믹 프로그래밍은 큰 문제를 작은 문제로 나눠서 푸는 알고리즘이다.)

------

## 1. LCS (Longest Common Subsequence)

- **LCS is algorithm to find longest common subsequence.**

  <br>(LCS는 최장 공통 부분 문자열을 찾는 알고리즘이다.)

  > * Subsequence
  >
  >   → 연속적이지 않은 부분 문자열.
  >
  > * Substring
  >
  >   → 연속된 부분 문자열.



- Ex) "ACAYKP" 와 "CAPCAK" 의 LCS 구하기.

  > 1. "ACAYKP"를 기준 string으로 설정하고 "CAPCAK"를 비교 string을 선택. (+ Initialization.)
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/50851045-83141480-1330-11e9-89f6-6f4496ce1801.png)
  >
  > 2. "ACAYKP"를 기준으로 "C" string의 LCS 값을 구한다.
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/50851123-b9ea2a80-1330-11e9-978a-5969c7a7c7f5.png)
  >
  > 3. "ACAYKP"를 기준으로 "CAP" string의 LCS 값을 구한다.
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/50851162-d7b78f80-1330-11e9-94a7-dde8354e3b84.png)
  >
  > 4. "ACAYKP"를 기준으로 "CAPCAK" string의 final LCS 값을 구한다.
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/50851205-f9b11200-1330-11e9-9ad6-3794371aacf5.png)
  >
  > 5. Memoization의 table을 참조해서 LCS 길이 구하기.
  >
  >    ![image](https://user-images.githubusercontent.com/23169707/50850948-3e887900-1330-11e9-8a4c-62aa8427865c.png)

- Ex) LCS Source code.

  > * Code
  >
  > ```c++
  > int main() 
  > {
  >     int LCS_length = 0, max;	//LCS length.
  >     int **table; 				//LCS saved in this table.
  >     string str1, str2;
  >  
  >     //set String.
  >     cin >> str1;
  >     cin >> str2;
  >     
  >     // For comparing on table.
  >     str1 = "0" + str1;
  >     str2 = "0" + str2;
  >  
  >     //set Table.
  >     int len1, len2;
  >     len1 = str1.length();
  >     len2 = str2.length();
  >  
  >     table = new int*[len2];
  >     for (int i = 0; i < len2; i++) 
  >         table[i] = new int[len1];
  >     
  >  
  >     for (int i = 0; i < len1; i++) 
  >         table[0][i] = 0;
  >     
  >  
  >     //Memoization Table Index and LCS Length
  >     for (int i = 1; i < len2; i++) 
  >     {
  >         max = 0;
  >         table[i][0] = 0;
  >         for (int j = 1;j < len1; j++) 
  >         {
  >             if (str2[i]== str1[j])
  >             {
  >                 max = table[i-1][j-1] + 1;
  >                 table[i][j] = max;
  >             }
  >             else 
  >             {
  >                 if(table[i][j-1] > table[i-1][j])
  >                     table[i][j] = table[i][j-1];
  >                 else
  >                     table[i][j] = table[i-1][j];
  >             }
  >         }
  >         if (LCS_length < max)
  >             LCS_length = max;
  >     }
  >     cout << LCS_length;			// The longest length.
  >  
  >     int temp0, temp1, for_j;
  >     temp1 = LCS_length;
  >     temp0 = temp1 - 1;
  >     for_j = len1 - 1;
  >     string LCS = "";
  >  
  >     //Calculation LCS 
  >     for (int i = len2-1; i >0; i--)
  >     {
  >         for (int j = for_j; j > 0; j--) 
  >         {	//[i][j] is destination coordinate.
  >             if (table[i][j] == temp1 && table[i][j - 1] == temp0 && table[i - 1][j - 1] == temp0 && table[i - 1][j] == temp0)
  >             {
  >                 temp0--;
  >                 temp1--;
  >                 LCS = str2[i] + LCS;
  >                 for_j = j;
  >                 break;
  >             }
  >         }
  >     }
  >  
  >     cout << LCS << endl;		// The subsequence of LCS.
  > }
  > ```