#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;
int V, E;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<pair<int, pii>> vertex;
vector<int> parent(10001, 0);

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

bool SameParent(int x, int y)
{
    return (find(x) == find(y));
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y)
        parent[y] = x;
}

int main()
{
    fastio;
    cin >> V >> E;

    int V1, V2, Cost;
    for (int i = 0; i < E; i++)
    {
        cin >> V1 >> V2 >> Cost;
        vertex.emplace_back(Cost, make_pair(V1, V2));
    }

    sort(vertex.begin(), vertex.end());

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    int ans = 0;
    for (int i = 0; i < E; i++)
    {
        if (!SameParent(vertex[i].second.first, vertex[i].second.second))
        {
            Union(vertex[i].second.first, vertex[i].second.second);
            ans += vertex[i].first;
        }
    }

    cout << ans;

    return 0;
}