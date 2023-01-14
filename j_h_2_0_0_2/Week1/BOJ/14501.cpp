#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> T(N+1);
    vector<int> P(N+1);
    vector<int> dp(N+2, 0);

    for(int i = 1; i<=N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i<=N+1; i++){
        for(int j = 1; j<=i; j++){
            if(i>=T[j]+j)
                dp[i] = max(dp[j]+P[j], dp[i]); 
        }
    }

    cout << dp[N+1] << endl;
    
    return 0;
}