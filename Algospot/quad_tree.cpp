#include<iostream>
#include<string>

using namespace std;

string DFS(string::iterator &it)		// To figure out each compression in quad tree.
{
	char head = *it;						// head = The first character of current iterator.
	it++;										// [iterator�� �ּҰ��� parameter�� Ȱ���ϱ� ������, ++�� �ּҰ��� ������ it���� ����.]	
	if (head == 'b' || head == 'w')	// Base case.	[������� Ȯ�� ��, first character�� Ȯ�� �ߴٴ� ���� ǥ���ϱ� ���� it++�� ���� ����.]
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