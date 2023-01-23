#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

typedef pair<int, int> pii;

vector<vector<int>> graph(10001, vector<int>(10001, INF));
vector<bool> visited(10001, false);
vector<int> dist(10001, INF);

int V, E;

int getSmallIndex()
{
    int min = INF, index = 0;
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] < min && !visited[i])
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int start)
{
    for (int i = 1; i <= V; i++)
        dist[i] = graph[start][i];

    visited[start] = true;

    for (int i = 1; i <= V - 2; i++)
    {
        int cur = getSmallIndex();
        visited[cur] = true;
        for (int j = 1; j <= V; j++)
            if (!visited[j])
            {
                if (dist[cur] + graph[cur][j] < dist[j])
                    dist[j] = dist[cur] + graph[cur][j];
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    int a, b, c;

    for (int i = 1; i <= E; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c, graph[b][a] = c;
    }

    Dijkstra(1);

    dist[1] = 0;
    cout << *max_element(dist.begin() + 1, dist.begin() + 1 + V);
    return 0;
}