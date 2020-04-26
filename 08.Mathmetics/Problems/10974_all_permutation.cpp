#include<iostream>
#include<memory.h>
#include<string>

#define MAX 9

using namespace std;

int N;												// N = The number of permutation.
bool visit[MAX];								// visit = The memory of visited or not.

void DFS(string str, int cnt)		// To figure out permutation.
{
	if (cnt == N)				// Base case.
	{
		cout << str << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])				// Not visit yet.
		{
			visit[i] = true;
			str += to_string(i);	str += " ";
			DFS(str, cnt + 1);
			str.pop_back();		str.pop_back();
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;

	DFS("", 0);
}