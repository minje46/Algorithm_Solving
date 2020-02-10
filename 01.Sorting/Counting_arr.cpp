#include<iostream>
using namespace std;

#define Size 10001
int arr[Size] = { 0, };

void Sort()
{
	for (int i = 1; i <= Size; i++)		
	{
		while (arr[i] > 0)
		{
			cout << i << "\n";
			arr[i]--;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);

	int N, input;
	cin >> N;

	for (int i = 0; i < N; i++)	// Count the value which user sets.
	{
		cin >> input;
		arr[input]++;
	}
	
	Sort();
}