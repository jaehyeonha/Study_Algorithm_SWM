#include <bits/stdc++.h>

#define INF 1e9

using namespace std;
int N, ans = INF, start, link, dif;

vector<vector<int>> S(20, vector<int>(20, 0));
vector<bool> visited(20, false); // 초깃값은 false

// true -> start팀, false -> link팀으로 가정하겠음
void dfs(int idx, int cnt)
{
    start = 0, link = 0;
    if (cnt == N / 2)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (visited[i] && visited[j])
                    start += S[i][j];
                if (!visited[i] && !visited[j])
                    link += S[i][j];
            }

        if (ans > (dif = abs(start - link)))
            ans = dif;

        return;
    }

    for (int i = idx; i < N; i++)
    {
        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    dfs(0, 0);

    cout << ans;

    return 0;
}