#include<iostream>
#include<memory.h>
#include<vector>

#define MAX 51

using namespace std;

int N, M;														// N = The number of people.			M = The number of party.
bool fact[MAX];											// fact = The memory of who knows true story.			
vector<int> party[MAX];								// party = The memory of who take in a party.
bool map[MAX][MAX];								// map = The connection of people.
bool visit[MAX][MAX];									// visit = The memory of visited or not.
int answer;													// answer = The number of lie's party.

void Make_map()			// To set the map.
{
	for (int k = 1; k <= M; k++)						// Party index.
	{
		for (int i = 0; i < party[k].size(); i++)		
		{
			int dpt = party[k][i];
			for (int j = 0; j < party[k].size(); j++)
			{
				int dst = party[k][j];
				if (dpt != dst)
					map[dpt][dst] = true;				// Connected each other.
			}
		}
	}
}

void DFS(int dpt)				// To figure out netwrok who knows true story.
{
	fact[dpt] = true;										
			
	for (int dst = 1; dst <= N; dst++)				
	{
		if (map[dpt][dst] && !visit[dpt][dst])
		{
			visit[dpt][dst] = true;
			DFS(dst);
		}
	}
}

void Simulation()				// To figure out the number of lie's party.
{
	for (int i = 1; i <= M; i++)
	{
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++)
		{
			if (fact[party[i][j]])							//	Some one who knows true story.
			{
				flag = false;
				break;
			}
		}
		if (flag)												// There is no one knows true story, 
			answer++;										// count lie's party.
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	memset(fact, false, sizeof(fact));

	cin >> N >> M;
	int true_man, n;											// true_man = The number of people who know true story.
	cin >> true_man;											// n = The number of people who take in party.				
	for (int i = 0; i < true_man; i++)
	{
		cin >> n;
		fact[n] = true;
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int val;
			cin >> val;
			party[i].push_back(val);
		}
	}

	Make_map();
	for (int i = 1; i <= N; i++)
	{
		if (fact[i])
			DFS(i);
	}
	answer = 0;
	Simulation();

	cout << answer << endl;
}