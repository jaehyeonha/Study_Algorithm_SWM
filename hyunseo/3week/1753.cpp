#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<vpii> graph(20001, vpii(0));
vector<bool> visited(30001, false);
vector<int> dist(20001, INF);

int V, E, start;

void Dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty())
    {
        auto current = pq.top();

        pq.pop();

        int st = current.second;
        int distance = current.first;

        if (visited[st])
            continue;

        if (dist[st] < distance)
            continue;

        visited[st] = true;
        for (int i = 0; i < graph[st].size(); i++)
        {
            int nextDistance = distance + graph[st][i].first;
            int next = graph[st][i].second;

            if (nextDistance < dist[next])
            {
                dist[next] = nextDistance;
                pq.emplace(nextDistance, next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> start;

    int a, b, c;
    for (int i = 1; i <= E; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    Dijkstra(start);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}