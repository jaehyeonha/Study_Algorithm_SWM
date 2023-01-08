#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, W;
    scanf("%d %d", &N, &W);
    
    vector<int> weight(N+1);
    vector<int> value(N+1);
    vector<vector<int>> dp(N+1, vector<int>(W+1));

    for(int i=1; i<=N; i++)
        scanf("%d %d", &weight[i], &value[i]);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            if(j>=weight[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else    
                dp[i][j] = dp[i-1][j];   
        }
    }
    
    printf("%d", dp[N][W]);
    return 0;
}