#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 100005
#define INF 987654321

using namespace std;

bool visit[MAX];		// The memory of visit.
int result = INF;		// The memory of answer.

void BFS(int start, int end)		// To figure out the route to chase.
{											// start = The departure point.(A location.)		end = The destination point.(B location.)
	queue<pair<int,int>>que;		// first = The location.		second = The level.
	que.push({ start, 0 });
	while (!que.empty())			// Until there is no more node to move.
	{
		auto cur = que.front();		// The current(present) position.
		que.pop();

		if (cur.first == end)			// To figure out the minimum time to chase. (time = cost)
			result = min(result, cur.second);
		

		if (visit[cur.first])				// Checking visited node is no use.
			continue;					// [�̹� �湮�� ��ǥ���� ������ �� �ִ� �̵� �Ÿ��� ��� �Ǿ��� ��.]
		visit[cur.first] = true;		// Treat the current node as visited.

		for (int i = 0; i < 3; i++)
		{
			int next = cur.first;
			switch (i)
			{
			case 0:				// The first case of A's movement.
				next += 1;
				break;
			case 1:				// The second case of A's movement.
				next -= 1;
				break;
			case 2:				// The third case of A's movement.
				next *= 2;
				break;
			default:
				break;
			}

			if (next >= MAX || next < 0)		// The overflow area.
				continue;

			if (!visit[next] && cur.second+1 <= result)		// The next node shouldn't be visited yet. And If the time will be later than current node, it doesn't need to check.
				que.push({ next, cur.second+1 });			// [�湮���� ���� ����̸鼭, ���� �� �ҿ� �ð����� ���� �ð��� �����Ӹ� Ȯ���ϸ� �ȴ�.]
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int N, K;			// N = The location of A who can move.		K = The location of B who stuck.		
	cin >> N >> K;

	BFS(N, K);		// To figure out the route to chase.

	cout << result << endl;		// The total count of A chases B.
}