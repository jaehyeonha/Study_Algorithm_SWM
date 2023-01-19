#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v(10000 + 1);
vector<bool> visited;
vector<int> dp;

void dfs(int node)
{
    visited[node] = true;

    if (!v[node].size())
    {
        dp[node] = 0;
        return;
    }

    for (int i = 0; i < v[node].size(); i++)
    {
        int next_value = v[node][i];
        if (!dp[next_value])
            dfs(next_value);
        dp[node] = dp[next_value] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int A, B;
    cin >> N >> M;

    while (M--)
    {
        cin >> A >> B;
        v[B].emplace_back(A);
    }

    dp = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, 0);

    for (int i = 1; i <= N; i++)
        if (v[i].size() && !visited[i])
            dfs(i);

    // dp에서 가장 큰 값을 구한다.
    int max = *max_element(dp.begin(), dp.end());
    for (int i = 1; i <= N; i++)
        if (dp[i] == max)
            cout << i << " ";

    return 0;
}

/**
 * @brief 실패 code
 * dp 로 풀면 순환참조 문제를 해결하지 못함..
 */