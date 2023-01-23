#include <bits/stdc++.h>

using namespace std;
#define INF 2e9

int N, L, R, X;
vector<int> prob(15);
vector<int> tmp;
int ans = 0;

void dfs(int index)
{
    if (index == N)
    {
        int sum = 0;
        int max = 0, min = INF;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (max < tmp[i])
                max = tmp[i];
            if (min > tmp[i])
                min = tmp[i];
            sum += tmp[i];
        }
        if (sum >= L && sum <= R && max - min >= X)
            ans++;

        return;
    }

    tmp.emplace_back(prob[index]);
    dfs(index + 1);
    tmp.pop_back();
    dfs(index + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R >> X;

    for (int i = 0; i < N; i++)
        cin >> prob[i];

    dfs(0);
    cout << ans;

    return 0;
}