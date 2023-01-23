#include <bits/stdc++.h>

using namespace std;

int N, r, g, b, color;

vector<vector<int>> house(1001, vector<int>(3, 0));
vector<vector<int>> dp(house);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> house[i][0] >> house[i][1] >> house[i][2];

    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }

    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));

    return 0;
}