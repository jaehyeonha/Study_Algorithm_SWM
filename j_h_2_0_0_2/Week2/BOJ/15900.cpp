#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;
matrix_t tree;
vector<int> visited;

int num = 0;

void dfs(int x, int depth)
{

	bool isLeaf = true;

	for (int i = 0; i < tree[x].size(); i++)
	{
		if (visited[tree[x][i]] == 0)
		{
			isLeaf = false;
			visited[tree[x][i]] = 1;

			dfs(tree[x][i], depth + 1);

		}
	}

	if (isLeaf)
	{
		num += depth;
	}
}

int main()
{
	int N;
	cin >> N;

	tree.resize(N + 1);
	visited.resize(N + 1);

	int count = 0;

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	visited[1] = 1;
	dfs(1, 0);

	if (num % 2 == 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}