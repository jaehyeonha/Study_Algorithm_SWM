#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<vpii> graph(10001, vpii(0));
vector<bool> visited(10001, false);
vector<int> dist(10001, INF);

int V, E;

void Dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pii> pq;
    pq.emplace(start, 0);

    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if (dist[current] < distance)
            continue;

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int nextDistance = distance + graph[current][i].second;

            if (nextDistance < dist[next])
            {
                dist[next] = nextDistance;
                pq.emplace(next, -nextDistance);
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

    int a, b, c;
    for (int i = 1; i <= E; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    Dijkstra(1);

        return 0;
}