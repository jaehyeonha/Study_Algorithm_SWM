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
        //i는 N만큼
        for(int j=1; j<=W; j++){
            //j는 무게
            if(j>=weight[i]) //j에 bag에 넣을 수 있는 무게일 때
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]); //앞서 넣은 bag 가치 || bag에 추가 후 가치 (앞에 있는 거 포함해서 넣을 수 있는지도 체크)
            else//앞서 넣은 bag 가치가 가장 높음  
                dp[i][j] = dp[i-1][j];   
        }
    }
    
    printf("%d", dp[N][W]);
    return 0;
}