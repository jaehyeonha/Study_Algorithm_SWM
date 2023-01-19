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
            for(int j = 2; j <= N; j++){
                dp[j] = dp[j-1] + dp[j-2];
            }
            cout << dp[N-1] <<" "<< dp[N] << endl;
        }
    }
    return 0;
}