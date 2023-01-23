#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vpii> vvpii;
typedef vector<bool> vb;

int n;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

// 인접 리스트 + cost를 포함
vvpii adjac_list(10001);

vb visited(10001, false);

int radius_point = 0;
int max_dist = 0;

void dfs(int cur, int cost)
{
    if (visited[cur])
        return;

    if (adjac_list[cur].size() == 1 && max_dist < cost)
    {
        max_dist = cost;
        radius_point = cur;
    }

    visited[cur] = true;
    for (int i = 0; i < adjac_list[cur].size(); i++)
        dfs(adjac_list[cur][i].first, cost + adjac_list[cur][i].second);
}

int find_radius(int cur)
{
    dfs(cur, 0);
    max_dist = 0;
    fill(visited.begin(), visited.end(), false);
    dfs(radius_point, 0);
    return max_dist;
}

int main()
{
    fastio;
    cin >> n;
    int u, v, c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> c;
        adjac_list[u].emplace_back(v, c);
        adjac_list[v].emplace_back(u, c);
    }

    cout << find_radius(1);

    return 0;
}