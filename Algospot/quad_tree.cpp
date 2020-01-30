#include<iostream>
#include<string>

using namespace std;

string DFS(string::iterator &it)		// To figure out each compression in quad tree.
{
	char head = *it;						// head = The first character of current iterator.
	it++;										// [iterator의 주소값을 parameter로 활용하기 때문에, ++된 주소값이 추후의 it에도 적용.]	
	if (head == 'b' || head == 'w')	// Base case.	[기저사례 확인 전, first character는 확인 했다는 것을 표기하기 위해 it++을 먼저 수행.]
		return string(1, head);			

	string up_lf = DFS(it);				// Upper Left.
	string up_rt = DFS(it);				// Upper Right.
	string down_lf = DFS(it);			// Down Left.
	string down_rt = DFS(it);			// Down Right.

	return string("x") + down_lf + down_rt + up_lf + up_rt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	
		string str;												// str = The memory of input data.
		cin >> str;
		
		string::iterator it = str.begin();
		string answer = DFS(it);							// answer = The reversed result of quad tree compression as output.	

		cout << answer << endl;
	}
}