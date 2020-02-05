#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
	int key;
	struct Node *lptr;
	struct Node *rptr;
};

struct Node *root = NULL;				// This is the root of tree.
queue<struct Node*> que;				// queue helps it is possible to read in bfs search.
vector<pair<int, bool>> visited;			// It controls whether node is visited or not. (pair.first = node->key, pair.second = true or false)
vector<int> result;							// For printing all value of tree.

void Print()
{
	for (int i = 0; i < result.size(); i++)
	{
		if (i == result.size() - 1)
		{
			cout << result[i] << endl;
			break;
		}
		cout << result[i] << "->";
	}
}

void queue_clear()					// In queue library, there is no clear all queue.
{										// This method is just pop every value in quee.
	while (!que.empty())
		que.pop();
}

struct Node *BFS()
{
	struct Node *ptr = root;					// Making temp pointer variable, that's because root is global variable.

	que.push(ptr);								// At first, push the root node in queue.
	while (!que.empty())						// If the queue is empty, there is no more node to read.
	{
		ptr = que.front();						// Read the node inside queue in regular sequence.

		if (ptr->lptr)								// Push the left node first.
			que.push(ptr->lptr);
		else
		{											// If left child node is null pointer, it is the location where the new node should be linked.
			queue_clear();						// queue is set as global variable, it should be cleared for the next search.
			return ptr;
		}

		if (ptr->rptr)
			que.push(ptr->rptr);
		else
		{
			queue_clear();
			return ptr;
		}
		que.pop();								// Pop the front node, adjacent nodes are already pushed in queue.
	}												// And this algorithm is based on queue which is controlling nodes to read.
}

void Insert(int value)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));			// Allocate new memory dynamically.
	new_node->key = value;

	struct Node *location = (struct Node*)malloc(sizeof(struct Node));				// location = store the parent node of Null pointer.

	visited.push_back({ new_node->key, false });
	if (!root)						// The first time to insert. (For setting root node)	
	{
		root = new_node;
		root->lptr = NULL;
		root->rptr = NULL;
	}
	else
	{
		location = BFS();							// Get the parent node of linking new node.
													// Because it is based on linked list, it is no use for knowing location of null pointer.
		if (location->lptr == NULL)					// Judging where null pointer is.
			location->lptr = new_node;
		else
			location->rptr = new_node;

		new_node->lptr = NULL;					// All conditions judge with null pointer so it should initialize as null pointer.
		new_node->rptr = NULL;
	}
}

void DFS(struct Node *ptr)
{
	if (!ptr)		// If ptr is null. (DFS function is based on recursive structure, so it should be finished at clear point.)
		return;
	else			// If ptr is not null.
	{
		for (int i = 0; i<visited.size(); i++)
		{
			if (visited[i].first == ptr->key)				// Finding ptr->key in visited vector which controls node is visited or not.
			{
				if (visited[i].second == true)			// After finding the ptr key's visited array, check it is already visited or not.
					return;
				else										// It is the case that the node is not visited yet.
				{
					visited[i].second = true;			// It's time to be changed.
					result.push_back(ptr->key);		// For printing to see the result.
					;					if (ptr->lptr)							// It is based on binary tree.
						DFS(ptr->lptr);					// Check left child and right child orderly.
					if (ptr->rptr)
						DFS(ptr->rptr);
				}
			}
		}
	}
}

int main(void)					// DFS search is executed after structured binary tree by bfs.
{
	std::ios_base::sync_with_stdio(false);

	int N, value;				// N = How many times do you get input.
	cin >> N;

	while (N-- > 0)
	{
		cin >> value;
		Insert(value);			// Insert value in correct location.
	}
	cout << "\n" << "Structure a tree based on BFS is finished." << "\n";

	DFS(root);				// Do dfs search.
	Print();						// Print the result of dfs search.
	cout << "\n" << "DFS search is finished.";
	free(root);
}