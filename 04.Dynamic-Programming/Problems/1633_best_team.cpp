#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

const int inf = 1000000000;

int N = 0;												// N = The number of input data.
int white[1001], black[1001];					// white, black = The memory of input data.
int cache[1002][16][16];						// cache = The memory of memoization.

int DFS(int idx, int w, int b)		// To figure out all cases with memoization.
{
	if (w == 15 && b == 15)
		return 0;
	
	if (idx == N) 
		return -inf;
	
	int&ret = cache[idx][w][b];
	if (ret != -1)
		return ret;

	ret = DFS(idx + 1, w, b);
	if (w < 15) 
		ret = max(ret, DFS(idx + 1, w + 1, b) + white[idx]);
	if (b < 15)
		ret = max(ret, DFS(idx + 1, w, b + 1) + black[idx]);
	return ret;
}

int main()
{
	while (scanf("%d%d", &white[N], &black[N]) == 2)
		++N;

	memset(cache, -1, sizeof(cache));

	cout << DFS(0, 0, 0) << endl;
}