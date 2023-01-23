#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<char> vc;

int R, C, ans = 0;

vector<vc> board(21, vc(21));
vpii dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<bool> visited(26, false);

bool is_in_board(int x, int y)
{
    return (x >= 1 && x <= R && y >= 1 && y <= C);
}

void dfs(pii pos, int depth)
{
    ans = max(ans, depth);
    int x = pos.first, y = pos.second;
    visited[board[x][y] - 'A'] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first, ny = y + dir[i].second;
        if (!is_in_board(nx, ny) || visited[board[nx][ny] - 'A'])
            continue;
        visited[board[nx][ny] - 'A'] = true;
        dfs({nx, ny}, depth + 1);
        visited[board[nx][ny] - 'A'] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    int v;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> board[i][j];

    dfs({1, 1}, 1);

    cout << ans;

    return 0;
}