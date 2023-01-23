#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

#define INF 2e9

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

vi tree(10000);

void postOrder(int start, int end)
{

    if (start >= end)
        return;

    int target = start + 1;
    while (target < end && tree[start] > tree[target])
        target++;

    postOrder(start + 1, target);

    // 같으면 출력하게 해서는 안됨
    postOrder(target, end);

    cpout(tree[start]);
}

int main()
{
    fastio;

    int N;
    int i = 0;
    while (cin >> N)
        tree[i++] = N;

    postOrder(0, i);

    return 0;
}