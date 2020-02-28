#include<iostream>
#include<queue>

#define MAX 101

using namespace std;

int N;															// N = The size of string.
int str[MAX];												// str = The memory of input data.

int Greedy()					// To figure out the minimum time of string cat.
{
	priority_queue<int, vector<int>, greater<int>> que;						
	for (int i = 0; i < N; i++)
		que.push(str[i]);

	int cnt = 0;
	while (que.size() > 1)
	{															// To pick the shortest string every moment.
		int a = que.top();		que.pop();
		int b = que.top();		que.pop();

		que.push(a + b);
		cnt += (a + b);
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> str[i];

		int answer = Greedy();

		cout << answer << endl;
	}
}
