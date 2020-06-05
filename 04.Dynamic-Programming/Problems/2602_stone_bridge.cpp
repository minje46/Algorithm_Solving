#include<iostream>
#include<memory.h>
#include<string>

#define MAX 101

using namespace std;

string str;													// str = The memory of target string.
string map[2];											// map = The memory of input data.	
int cache[2][MAX][22];								// cache = The memory of memoization.		
int answer = 0;											// answer = The total number of ways to make target strings.

int DP(int y, int x, int idx)		// To figure out whether it makes target strings or not.
{
	if (idx == str.length())				// Base case.
		return 1;

	int &res = cache[y][x][idx];
	if (res != -1)							// Memoization.
		return res;

	res = 0;
	for (int j = x; j < map[0].length(); j++)
	{
		if (map[y][j] == str[idx])		// Target character.
			res += DP(1 - y, j + 1, idx + 1);
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> str >> map[0] >> map[1];

	memset(cache, -1, sizeof(cache));
	for (int k = 0; k < 2; k++)
		answer += DP(k, 0, 0);

	cout << answer << endl;
}