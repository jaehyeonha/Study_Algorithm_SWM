#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++){
        int N;
        cin >> N;
        vector <int> dp(N+1);
        if (N == 0)
            cout << 1 <<" "<< 0 << endl;
        else if (N == 1)
            cout << 0 <<" "<< 1 << endl;
        else{
            dp[0] = 0;
            dp[1] = 1;
            for(int i = 2; i <= N; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            cout << dp[N-1] <<" "<< dp[N] << endl;
        }
    }
    return 0;
}