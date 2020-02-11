#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

#define MAX 20

using namespace std;

int N;															// N = The length of formula.
string str;													// str = The memory of formula.
bool visit[MAX];											// visit = The memory of visited or not.
long long answer = -98876543212;				// answer = The biggest result as output.

long long Caluclation()			// To calculate the formula.
{
	deque<string> deq;									
	for (int i = 0; i < N; i++)							// #1. Pre process the parentheses.	
	{
		deq.push_back(string(1, str[i]));

		if (visit[i])											// If the "()" exists,
		{
			deq.pop_back();
			deq.pop_back();
			int a = str[i - 1] - '0';
			int b = str[i + 1] - '0';
			
			if (str[i] == '+')								// calculate first.
				deq.push_back(to_string(a + b));
			else if (str[i] == '-')
				deq.push_back(to_string(a - b));
			else if (str[i] == '*')
				deq.push_back(to_string(a*b));

			i++;
		}
	}

	deque<string>tmp = deq;
	deq.clear();
	while (!tmp.empty())								// #2. Calculate multiplication.
	{
		auto cur = tmp.front();
		tmp.pop_front();

		if (cur == "*")
		{
			int a = stoi(deq.back());
			deq.pop_back();
			int b = stoi(tmp.front());
			tmp.pop_front();
			deq.push_back(to_string(a*b));
		}
		else
			deq.push_back(cur);
	}

	long long res = stoll(deq.front());
	deq.pop_front();
	while (!deq.empty())								// #3. Calculate remainders in formula.
	{
		auto cur = deq.front();
		deq.pop_front();

		if (cur == "+")
			res += stoll(deq.front());
		else if (cur == "-")
			res -= stoll(deq.front());
		deq.pop_front();
	}
	return res;
}

void DFS(int idx)				// To make combination set.
{									// ["()" 사용하는 경우의 수.]
	answer = max(answer, Caluclation());

	for (int i = idx; i < N; i += 2)
	{															// Check only operator index.		
		if (!visit[i])
		{
			if (i == 1)										// Underflow.
			{
				visit[i] = true;
				DFS(i + 2);
				visit[i] = false;
			}
			else if (i > 1 && !visit[i - 2])				// Avoid using parentheses in a sequence.
			 {
				visit[i] = true;
				DFS(i + 2);
				visit[i] = false;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> str;

	DFS(1);

	cout << answer << endl;
}