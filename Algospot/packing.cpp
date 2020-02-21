#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
#include<vector>

#define MAX_N 101
#define MAX_W 1001

using namespace std;


int N, W;											// N = The number of items.								W = The total capacity could take it.
string name[MAX_N];							// name = The memory of item's name.							
int volume[MAX_N], need[MAX_N];		// volume = The memory of item's volume.		need = The memory of item's wish point.
int cache[MAX_W][MAX_N];					// cache = The memory of memoization.

int pack(int capacity, int item)				// To figure out the maximum capacity taken it.
{
	if (item == N)			// Base case.[The whole of items.]
		return 0;

	int &result = cache[capacity][item];
	if (result != -1)
		return result;

	result = pack(capacity, item + 1);		// Not pick.[Pass this item.]

	if (capacity >= volume[item])			// Pick this item.
		result = max(result, pack(capacity - volume[item], item + 1) + need[item]);
	return result;
}

void reconstruct(int capacity, int item, vector<string> &vc)			// To backtrack the items could take it.
{
	if (item == N)			// Base case.[The whole of items.]
		return;

	if (pack(capacity, item) == pack(capacity, item + 1))				// If both have same capacity.
		reconstruct(capacity, item + 1, vc);

	else
	{
		vc.push_back(name[item]);	
		reconstruct(capacity - volume[item], item + 1, vc);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		memset(cache, -1, sizeof(cache));
		cin >> N >> W;
		for (int j = 0; j < N; j++)
			cin >> name[j] >> volume[j] >> need[j];
		
		vector<string> answer;
		reconstruct(W, 0, answer);

		cout << pack(W, 0) << " " << answer.size() << endl;
		for (int j = 0; j < answer.size(); j++)
			cout << answer[j] << endl;
	}
}