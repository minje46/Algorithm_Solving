#include<iostream>

using namespace std;

int Rascal_Triangle(int n, int m)					// To calculate rascal triangle's formula.
{
	return 1 + (n - m)*m;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case; 
	for (int t = 1; t <= test_case; t++)
	{
		int n, m;
		cin >> n >> m;

		cout << Rascal_Triangle(n,m) << endl;
	}
}