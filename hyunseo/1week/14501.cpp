#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int T, P;
    vector<int> T_i(16), P_i(16), DP(16);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> T_i[i] >> P_i[i];

    for (int i = N; i > 0; i--)
    {
        if (i + T_i[i] > N + 1)
            DP[i] = DP[i + 1];
        else
            DP[i] = max(DP[i + 1], DP[i + T_i[i]] + P_i[i]);
    }

    cout << DP[1] << endl;

    return 0;
}