#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> v;
vector<int> tmp(8);
vector<bool> check(8, false);

void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << tmp[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            tmp[depth] = v[i];
            dfs(depth + 1);
            check[i] = false;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v.emplace_back(n);
    }

    sort(v.begin(), v.end());

    dfs(0);

    return 0;
}