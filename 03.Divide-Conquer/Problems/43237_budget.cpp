#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int solution(vector<int> budgets, int M)			// To figure out the maximum budget.
{																// budgets = Each city's budget.
	sort(budgets.begin(), budgets.end());		// M = The total money to use.
	int tot = M, cnt = budgets.size();
	for (int i = 0; i < cnt; i++)
		tot -= budgets[i];								// [+�����ϸ�, �ð��ʰ�;;]
	if (tot >= 0)												// If total money is enough to distribute,
		return budgets[cnt - 1];

	int lf = M / cnt, rt = budgets[cnt - 1];		
	while (lf <= rt)											// Binary search.
	{
		tot = M;
		int mid = (lf + rt) / 2;
		for (int i = 0; i < cnt; i++)
		{
			if (mid >= budgets[i])						// [��û budget�� �� ���� ���,	
				tot -= budgets[i];						// ������ budget�� avg ��꿡 ����.]
			else												
				tot -= mid;
		}
		if (tot >= 0)
			lf = mid + 1;
		else
			rt = mid - 1;
	}
	return rt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	vector<int> vc = { 120, 110, 140, 150 };
	cout << solution(vc, 485) << endl;
}