#include <iostream>
using namespace std;

#define Size 1000005
int input[Size];
int output[Size];

void Merge_Sort(int front, int mid, int end) 
{
	int i = front, j = mid + 1, k = front;

	while (i <=mid && j <=end)		// Compare the index of each array.
	{
		if (input[i] < input[j])
		{
			output[k] = input[i];
			i++;
			k++;
		}

		else if (input[i] > input[j])
		{
			output[k] = input[j];
			j++;
			k++;
		}
	}

	while (i <= mid)				// The rest of array after comparing two arrays. 
	{
		output[k] = input[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		output[k] = input[j];
		j++;
		k++;
	}

	for (int i = front; i <= end; i++)
		input[i] = output[i];
}
// Split the array by binary.
void Split(int front, int end)		
{
	int mid = (front + end) / 2;

	if (front != end)
	{
		Split(front, mid);
		Split(mid + 1, end);
		Merge_Sort(front, mid, end);
	}
}

int main() 
{
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> input[i];

	
	Split(0, N-1);

	for (int i = 0; i < N; i++)
		cout << input[i] << "\n";
}