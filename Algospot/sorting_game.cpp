#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>

using namespace std;

int N;													// N = The size of input data.
vector<int> arr;									// arr = The memory of input data.
map<vector<int>, int> dist;					// dist = The memory of graph's depth.

void BFS(int n)		// To figure out array order.
{							// [Unsorted array�� sorted�Ǵ� minimum change Ƚ���� bfs�� depth�� ����.]
	vector<int> vc(n);							// vc = The memory of input array. [From 0 to n]
	for (int i = 0; i < n; i++)
		vc[i] = i;									

	queue<vector<int>> que;
	que.push(vc);
	dist[vc] = 0;		// [vc�� sorted�� ���·� ����Ǿ��ֱ� ������, depth 0 ����.]

	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		int depth = dist[cur];					// Current depth.
		for (int i = 0; i < n; i++)
		{												// Current array.
			for (int j = i + 2; j <= n; j++)
			{											// Change array's order from 2 to N.	
				reverse(cur.begin() + i, cur.begin() + j);
				if (dist.count(cur) == 0)		// [reverse�� dpt~dst �� ���� order reverse.]
				{										// [dst�� index�� ������.]
					dist[cur] = depth + 1;		// [���� depth���� �� ���� change�� �߰������� �Ͼ ���̱� ������ +1]		
					que.push(cur);
				}										// Return to original.
				reverse(cur.begin() + i, cur.begin() + j);
			}
		}
	}
}

int solve()		// To figure out array's order without real value.
{					// [Array�� ������ �˸� �ȴ�.]	
	vector<int> vc;
	for (int i = 0; i < arr.size(); i++)
	{
		int sm = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] < arr[i])
				sm++;
		}
		vc.push_back(sm);		
	}										// [Ư�� order�� ���� array�� sorted�Ǵ� depth��
	return dist[vc];					// sorted array���� Ư�� order�� array�� ���ϴ� depth�� ����.]
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	for (int i = 1; i <= 8; i++)
		BFS(i);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{
		arr.clear();

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			arr.push_back(num);
		}

		int answer = solve();
		cout << answer << endl;
	}
}