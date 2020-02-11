#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
#include<vector>

#define MAX 101

using namespace std;

string wild_card, word;							// wild_card, word = The memory of string word as input data.
int cache[MAX][MAX];						// cache = The memory of memoization.
vector<string>answer;							// answer = The memory of matched word with wild card as output.

bool DFS(int w, int s)			// To figure out the word is matched with wild card or not.
{
	int &ret = cache[w][s];					// Memoization.
	if (ret != -1)
		return ret;

	while (w < wild_card.length() && s < word.length() && (wild_card[w] == word[s] || wild_card[w] == '?'))
		return ret = DFS(w + 1, s + 1);		// [wild_card�� word�� ���� �� ���� ��, matching �Ǵ� ���.]
	
	if (w == wild_card.length() && s == word.length())
		return ret = 1;								// [wild_card�� word�� ���ÿ� Ž�� �Ϸ�� ����, matching�Ǿ��ٴ� ��.]

	if (wild_card[w] == '*')					// [wild_card�� '*'�� word�� �� ���ڰ� �����Ǵ��� Ȯ��.]
	{
		if (DFS(w + 1, s) || (s < word.length() && DFS(w, s + 1)))
			return ret = 1;							// [0���� ���� || word�� �� �ڼ� ������Ű�� Ȯ��.]
	}
	return ret = 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test_case, N;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++)
	{	// Initialization.
		answer.clear();

		cin >> wild_card;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> word;
			
			memset(cache, -1, sizeof(cache));
			if (DFS(0, 0))
				answer.push_back(word);
		}	

		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	}
}