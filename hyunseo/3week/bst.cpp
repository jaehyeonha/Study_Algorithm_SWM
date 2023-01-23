#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

template <typename T>
struct Node
{
    Node *left;
    Node *right;
    T value;
};

template <typename T>
class BST
{
public:
    Node<T> *root;
    BST() : root(nullptr){};
    ~BST() { delete root; }

    void postOrder(Node<T> *cur)
    {
        if (cur == nullptr)
            return;
        postOrder(cur->left);
        postOrder(cur->right);
        cout << cur->value << '\n';
    }
    void addNode(T _value);
};

template <typename T>
void BST<T>::addNode(T _value)
{
    Node<T> *node = new Node<T>();
    Node<T> *tmp = nullptr;

    node->value = _value;

    if (root == nullptr)
        root = node;
    else
    {
        Node<T> *ptr = root;
        while (ptr != nullptr)
        {
            tmp = ptr;
            if (_value < ptr->value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        if (node->value < tmp->value)
            tmp->left = node;
        else
            tmp->right = node;
    }
}

int main()
{
    fastio;
    BST<int> *bst = new BST<int>();
    int v;
    int size = 9;
    while (size--)
    {
        cin >> v;
        bst->addNode(v);
    }

    bst->postOrder(bst->root);

    return 0;
}