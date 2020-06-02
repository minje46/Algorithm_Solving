#include <iostream>

using namespace std;

int Calculation(int n)		// To firgure out the number of cases.
{
	int a = 3, b = 6, res = 0;
	for (int i = 0; i < n; i++)
	{
		res += a;
		a += b, b += 3;
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int answer = Calculation(n);
	
	cout << answer << endl;
}