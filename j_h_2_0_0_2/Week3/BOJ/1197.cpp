#include <iostream>
#include <vector>
using namespace std;

#define INF 2147483647
#define MINF -2147483648
typedef pair<int, int> edge_t;
vector<vector<edge_t>> map;
int answer = 0;

void prim(int n) {
    int vnear, min;
    vector<int> nearest(n + 1, -1), distance(n + 1, INF);

    for (edge_t e : map[1]) {
        nearest[e.first] = 1;
        distance[e.first] = e.second;
    }

    for (int k = 0; k < n-1; k++) {
        min = INF;

        for (int i = 2; i <= n; i++) {
            if (MINF<distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        }

        if(min != INF){
            answer += min;
        }

        distance[vnear] = MINF;

        for (edge_t e : map[vnear]) {
            if (distance[e.first] > e.second) {
                distance[e.first] = e.second;
                nearest[e.first] = vnear;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    map.resize(N+1);

    for (int i = 0; i < M; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        map[u].push_back(make_pair(v,k));
        map[v].push_back(make_pair(u,k));
    }

    prim(N);
    cout << answer << endl;

    return 0;
}