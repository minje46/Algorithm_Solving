#include<iostream>
#include<algorithm>
#include<string>

#define MAX 101

using namespace std;

int len, N;										// len = The length of input data.				N = The number of input data to compare.
string origin = "", conv = "";				// origin = The memory of input data.		conv = The reverse string of original input data.
int cnt = 0;										// cnt = The number of answer.		
string answer[MAX];						// answer = The polygons to make same figure with original one.

bool Simulation(string str)					// To figure out they have same figure or not.
{
	string tmp = str;
	for (int i = 0; i < len; i++)
	{												// [Original model 과 Reversed model과 동일한 수열을 가지면, 같은 모양.]
		if (tmp == origin || tmp == conv)
			return true;							
		tmp = tmp.substr(1, tmp.length()) + tmp[0];
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> len;
	for (int i = 0; i < len; i++) 
	{
		char ch;
		cin >> ch;
		
		origin += ch;
		conv += (ch + 1) % 4 + 1 + '0';
	}
	reverse(conv.begin(), conv.end());

	cin >> N;
	while (N--)
	{
		string str = "";
		for (int i = 0; i < len; i++)
		{
			char ch;
			cin >> ch;

			str += ch;
		}

		if (Simulation(str))
			answer[cnt++] = str;
	}

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) 
	{
		for (int j = 0; j < len; j++)
			cout << answer[i][j] << " ";
		cout << endl;
	}
}