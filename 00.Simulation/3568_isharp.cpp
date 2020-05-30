#include<iostream>
#include<deque>
#include<string>

using namespace std;

string str;									// str = The memory of input string.

void Simulation()			// To figure out data type and variable names.
{
	string prim = "";						// prim = The primitive data type.	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')		// Split condition.
			break;
		prim += str[i];
	}
	
	deque<char>deq;
	for (int i = prim.length() + 1; i < str.length(); i++)
	{
		if (str[i] == ',' || str[i] == ';')		// Variable condition.
		{
			string tmp = prim;
			while (!deq.empty())
			{											// variable name.		
				if (deq.back() != '['  && deq.back() != ']'&&deq.back() != '*' && deq.back() != '&')
					break;					
				else if (deq.back() == ']')		// array type.
					tmp += '[', tmp += ']', deq.pop_back(), deq.pop_back();
				else									// others.
					tmp += deq.back(), deq.pop_back();
			}
			tmp += ' ';
			while (!deq.empty())
			{
				tmp += deq.front();
				deq.pop_front();
			}
			tmp += ';';

			cout << tmp << endl;
			i++;
			continue;
		}
		deq.push_back(str[i]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	getline(cin, str);

	Simulation();
}