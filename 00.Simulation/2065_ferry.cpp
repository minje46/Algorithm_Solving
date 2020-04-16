#include<iostream>
#include<queue>
#include<string>

#define MAX 10001
#define INF 987654321

using namespace std;

int M, T, N;												// M = The maximum number to take.		T = Time to move.		N = The number of people.
queue<pair<int, int>> que[2];					// que[0] : Left.		que[1] : Right.
bool dir = false;										// dir = The direction of boat.
int answer[MAX];									// answer = The destination time.

int Board(int cur_time)			// To board passengers who are waiting.
{
	int cnt = 0;							
	while (cur_time >= que[dir].front().second && cnt < M)			// To pick up passengers within limit.
	{
		answer[que[dir].front().first] = cur_time + T;			
		que[dir].pop();
		cnt++;													

		if (que[dir].empty())														// Exception.
			break;
	}
	return cnt;
}

void Simulation()
{
	int time = 0;
	while (!que[0].empty() || !que[1].empty())
	{
		int cnt = 0;
		if (!que[dir].empty())
		{
			cnt = Board(time);
			if (cnt != 0)						// Take some passengers.	
			{										
				time += T;					// Moving time.
				dir = !dir;					// Opposite direction.	
			}
		}
		if (cnt == 0)						// No one to pick up on the time.
		{
			int nxt = (que[!dir].empty() == true ? INF : que[!dir].front().second);
			if (time >= nxt)				// If there is anyone who arrived at opposite direction.
			{
				time += T;
				dir = !dir;
			}
			else								// Just wait.		
				time++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> M >> T >> N;
	for (int i = 0; i < N; i++)
	{
		int v;
		string str;
		cin >> v >> str;
		if (str == "left")
			que[0].push(make_pair(i, v));
		else
			que[1].push(make_pair(i, v));
	}

	Simulation();

	for (int i = 0; i < N; i++)
		cout << answer[i] << endl;
}