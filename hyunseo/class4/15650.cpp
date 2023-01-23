#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bool> check(9, false);
vector<int> v;

void dfs(int index, int count)
{
    if (count == M)
    {
        for (int i = 0; i < N; i++)
            if (check[i])
                cout << v[i] << " ";
        cout << endl;
    }

    for (int i = index; i < N; i++)
    {
        check[i] = true;
        dfs(i + 1, count + 1);
        check[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        v.emplace_back(i);

    dfs(0, 0);

    return 0;
}