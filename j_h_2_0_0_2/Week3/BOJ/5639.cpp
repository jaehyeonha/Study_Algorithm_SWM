#include<iostream>
#include<vector>
using namespace std;

vector<int> tree;

void preorder(int start, int end){ 
	if (start > end)
        return;
    
    int root = tree[start];

	if (start == end)
	{
		cout << root << endl;
		return;
	}

    int idx = start + 1;

	while (idx <= end)
	{
		if (tree[idx] > root)
			break;
		idx++;
	}
	
	preorder(start + 1, idx - 1);
	preorder(idx, end);
	cout << root << endl;
}

int main()
{
	int x;
    while (cin >> x)
	{   
        tree.push_back(x);
	}

	preorder(0, tree.size()-1);
}