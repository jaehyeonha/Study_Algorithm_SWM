#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp(N + 1);

    dp[0] = -1;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
        }
    }

    cout << dp[N] << endl;

    while (N != 0)
    {
        cout << N << " ";
        if (dp[N] == dp[N - 1] + 1)
        {
            N -= 1;
        }
        else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
        {
            N /= 2;
        }
        else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
        {
            N /= 3;
        }
    }
}