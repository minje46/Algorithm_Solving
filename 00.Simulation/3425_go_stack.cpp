#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
#include<stack>
#include<vector>

using namespace std;

vector<string>vc;											// vc = The memory of program instructions.
stack<long long>stk;									// stk = The memory of stack to do Go Stack.

int Simulation(long long val)    // To do Go_Stack program with instructions.
{
	while (!stk.empty())
		stk.pop();

	stk.push(val);
	for (int i = 0; i < vc.size(); i++)
	{
		if (vc[i] == "POP")
		{
			if (stk.empty())
				return -1;
			stk.pop();
		}
		else if (vc[i] == "INV")
		{
			if (stk.empty())
				return -1;
			long long cur = stk.top();	stk.pop();	stk.push(cur*-1);
		}
		else if (vc[i] == "DUP")
		{
			if (stk.empty())
				return -1;
			stk.push(stk.top());
		}
		else if (vc[i] == "SWP")
		{
			if (stk.size() < 2)
				return -1;
			long long a = stk.top();	stk.pop();
			long long b = stk.top();	stk.pop();
			stk.push(a);	stk.push(b);
		}
		else if (vc[i] == "ADD")
		{
			if (stk.size() < 2)
				return -1;
			long long a = stk.top();	stk.pop();
			long long b = stk.top();	stk.pop();
			stk.push(a + b);
		}
		else if (vc[i] == "SUB")
		{
			if (stk.size() < 2)
				return -1;
			long long a = stk.top();	stk.pop();
			long long b = stk.top();	stk.pop();
			stk.push(b - a);
		}
		else if (vc[i] == "MUL")
		{
			if (stk.size() < 2)
				return -1;
			long a = stk.top();	stk.pop();
			long b = stk.top();	stk.pop();
			long long res = a * b;
			stk.push(res);
		}
		else if (vc[i] == "DIV")
		{
			if (stk.size() < 2)
				return -1;
			long long a = stk.top();	stk.pop();
			long long b = stk.top();	stk.pop();
			if (a == 0)
				return -1;
			stk.push(b / a);
		}
		else if (vc[i] == "MOD")
		{
			if (stk.size() < 2)
				return -1;
			long long a = stk.top();	stk.pop();
			long long b = stk.top();	stk.pop();
			if (a == 0)
				return -1;
			stk.push(b%a);
		}
		else
		{
			string tmp = "";
			for (int j = 4; j < vc[i].length(); j++)
				tmp += vc[i][j];
			stk.push(stoll(tmp));
		}
	}
	if (stk.size() != 1 || abs(stk.top()) > 1e9)
		return -1;
	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	while (true)
	{
		string str;
		getline(cin, str);
		if (str == "")
			continue;

		if (str == "QUIT")
			break;
		else if (str == "END")
		{
			int n;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				long long val;		cin >> val;
				if (Simulation(val) == -1)
					cout << "ERROR" << endl;
				else
					cout << stk.top() << endl;
			}
			cout << endl;
			vc.clear();
		}
		else
			vc.push_back(str);
	}
}