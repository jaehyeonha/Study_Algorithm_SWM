#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adjac_list(1e5 + 1);
vector<int> parent(1e5 + 1, 0);

void bfs()
{
    queue<int> q;

    q.emplace(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adjac_list[cur].size(); i++)
        {
            if (!parent[adjac_list[cur][i]])
            {
                parent[adjac_list[cur][i]] = cur;
                q.emplace(adjac_list[cur][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adjac_list[a].emplace_back(b);
        adjac_list[b].emplace_back(a);
    }

    bfs();

    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}