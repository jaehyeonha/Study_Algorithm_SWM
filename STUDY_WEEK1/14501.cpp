#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    vector<int> t(N+1);
    vector<int> p(N+1);
    vector<int> dp(N+1, 0);
    int max_pay = 0;

    for(int i=0; i<N; i++)
        scanf("%d %d", &t[i], &p[i]);

    for(int i=0; i<=N; i++){
       
        dp[i] = max(max_pay, dp[i]);

        if(t[i]+i <= N) 
            dp[t[i]+i] = max(dp[t[i]+i], p[i] + dp[i]);
          
        
            
        
        max_pay = max(max_pay, dp[i]);
        
    }    

    printf("%d", max_pay);
    

    return 0;
}

