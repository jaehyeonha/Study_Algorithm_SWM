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
       
        //i번째 즉 하루가 지나가면서 최대 이익은 max_pay인가 아님 기존의 d[i]인가
        dp[i] = max(max_pay, dp[i]);

        //t[i] + i 즉 그 일을 하고도 N을 다 못 채우면, 즉 상담을 더 할 수 있다면 
        if(t[i]+i <= N) //그 상담을 한 후에 최대 이익 = 그 일을 한 날 번째의 최대 이익 = t[i]+i
            dp[t[i]+i] = max(dp[t[i]+i], p[i] + dp[i]);
        
        //새로운 최대 이익이 나왔는가? 체크
        max_pay = max(max_pay, dp[i]);
    }    

    printf("%d", max_pay);
    

    return 0;
}

