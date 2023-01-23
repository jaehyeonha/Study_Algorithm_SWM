#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(1002, vector<int>(1002, 0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    char s1[1002], s2[1002];
    cin >> (s1 + 1) >> (s2 + 1);

    for (i = 1; s1[i]; i++)
        for (j = 1; s2[j]; j++)
            dp[i][j] = max({dp[i - 1][j],
                            dp[i][j - 1],
                            dp[i - 1][j - 1] + (s1[i] == s2[j])});

    cout << dp[i - 1][j - 1];

    return 0;
}