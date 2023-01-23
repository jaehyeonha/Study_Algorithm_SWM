#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v(10000 + 1);
vector<bool> visited;
vector<int> r;

void dfs(int node, int &cnt, int cur)
{
    visited[node] = true;

    if (!v[node].size())
        return;

    for (int i = 0; i < v[node].size(); i++)
        if (!visited[v[node][i]])
            dfs(v[node][i], ++cnt, node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int A, B;
    while (M--)
    {
        cin >> A >> B;
        v[B].emplace_back(A);
    }

    visited = vector<bool>(N + 1, false);
    r = vector<int>(N + 1, 0);

    int cnt, max = 0, tmp;
    for (int i = 1; i <= N; i++)
    {
        fill(visited.begin(), visited.end(), false);
        cnt = 0;
        if (v[i].size())
        {
            dfs(i, cnt, i);
            if (max < cnt)
                max = cnt;
            r[i] = cnt;
        }
    }

    for (int i = 1; i <= N; i++)
        if (r[i] == max)
            cout << i << " ";

    return 0;
}