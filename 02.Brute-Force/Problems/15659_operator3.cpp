#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

#define MAX 12
#define INF 1000000001

using namespace std;

int N;													// N = The number of candidate numbers.
int numbers[MAX];								// numbers = The memory of cadidate numbers.
int calculate[4];									// calculate = The memory of four fundamental arithmetic operations.
long long small = INF, big = -INF;			// small = The memory of smallest value.			big = The memory of biggest value.

long long Calculation(string str)				// To calculate the formula with priority operation.
{
	deque<string> deq;
	int idx = 0;										// idx = The index of operator string.
	for (int i = 0; i < N; i++)
	{													// High priority in calculation.
		if (!deq.empty() && (deq.back() == "*" || deq.back() == "/"))
		{												// Based on stack data structure.
			string op = deq.back();
			deq.pop_back();
			
			int res;
			if (op == "*")
				res = stoi(deq.back()) * numbers[i];
			else if (op == "/")
				res = stoi(deq.back()) / numbers[i];
			deq.pop_back();
			deq.push_back(to_string(res));
		}
		else
			deq.push_back(to_string(numbers[i]));
	
		if (idx < str.length())
			deq.push_back(string(1, str[idx++]));
	}

	long long ans = stoll(deq.front());
	deq.pop_front();
	while (!deq.empty())						// To calculate the formula from beginning to end.
	{
		string op = deq.front();
		deq.pop_front();

		if (op == "+")
			ans += stoll(deq.front());
		else if (op == "-")
			ans -= stoll(deq.front());
		deq.pop_front();
	}
	return ans;
}

void DFS(int idx, int op, string str)			// To do exhaustive search in all cases.
{
	if (idx == N)									// Base case. [Use the whole of number cards.]
	{
		long long ans = Calculation(str);
		small = min(small, ans);				// Compare smaller one.
		big = max(big, ans);					// Compare bigger one.
		return;
	}

	for (int i = 0; i < 4; i++)					// In four fundamental arithmetic operations.
	{													// [0 : '+'] [1 : '-'] [2 : '*'] [3 : '/']
		if (calculate[i] == 0)
			continue;

		calculate[i] -= 1;						// Using tthis operator.
		switch (i)
		{
		case 0:										// [0:'+']
			DFS(idx + 1, i, str + '+');
			break;
		case 1:										// [1 : '-']
			DFS(idx + 1, i, str + '-');
			break;
		case 2:										// [2 : '*']
			DFS(idx + 1, i, str + '*');
			break;
		case 3:										// [3 : '/']
			DFS(idx + 1, i, str + '/');
			break;
		default:
			break;
		}
		calculate[i] += 1;						// Return to previous one.
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	for (int i = 0; i < 4; i++)					// [0 : '+'] [1 : '-'] [2 : '*'] [3 : '/']
		cin >> calculate[i];

	DFS(1, 0, "");

	cout << big << endl << small << endl;
}