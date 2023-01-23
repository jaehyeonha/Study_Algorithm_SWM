#include <bits/stdc++.h>

using namespace std;
#define INF 2e9

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef queue<int> qi;

int N, M;
vpii rule;
vi check(101, -1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < N + M; i++)
    {
        cin >> a >> b;
        rule.emplace_back(a, b);
    }

    qi q;
    q.emplace(1);
    check[1] = 0;
    int nx;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            if ((nx = cur + i) > 100)
                continue;
            for (int j = 0; j < N + M; j++)
                if (rule[j].first == nx)
                    nx = rule[j].second;

            if (check[nx] == -1)
            {
                check[nx] = check[cur] + 1;
                q.emplace(nx);
            }
        }
    }

    cout << check[100];

    return 0;
}