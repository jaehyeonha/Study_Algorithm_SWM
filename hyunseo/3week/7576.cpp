#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define max_size 1002

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int M, N, init_ripen_cnt;
vector<pii> ripen_pos_list;
vvi tomato(max_size, vi(max_size, -1));
vpii dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vvi check(max_size, vi(max_size, 0));
queue<pii> q;
int ans = -INF;

void bfs()
{
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dir[i].first, ny = cur.second + dir[i].second;

            if (nx < 1 || nx > N || ny < 1 || ny > M)
                continue;

            if (tomato[nx][ny] == -1 || check[nx][ny])
                continue;

            q.emplace(nx, ny);
            check[nx][ny] = check[cur.first][cur.second] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
            {
                q.emplace(i, j);
                check[i][j] = 1;
            }

            if (tomato[i][j] == -1)
                check[i][j] = -1;
        }

    init_ripen_cnt = ripen_pos_list.size();

    bfs();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (check[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
            if (ans < check[i][j])
                ans = check[i][j];
        }
    }

    cout << ans - 1;
    return 0;
}