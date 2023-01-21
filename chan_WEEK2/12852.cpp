#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//밑에서부터 푸는 dp
int dp[1000001];
//길을 기록
int route[1000001];

int solve(int x)
{
    //시작은 0
	dp[1] = 0;
    route[1] = 0;
	for (int i = 2; i <= x; i++)
	{
		// 3번 연산: 1을 뺀다
		dp[i] = dp[i - 1] + 1;
		route[i] = i - 1;

		// 1번 연산: 3으로 나눈다
		if (i % 3 == 0){
            //3으로 나눈 위치의 dp에 1더한 값보다 크다면
			if (dp[i] > dp[i / 3] + 1){
				dp[i] = dp[i / 3] + 1;
				route[i] = i / 3;
			}
			
		}

		// 2번 연산: 2로 나눈다
		if (i % 2 == 0){
             //2로 나눈 위치의 dp에 1더한 값보다 크다면
			if (dp[i] > dp[i / 2] + 1){
				dp[i] = dp[i / 2] + 1;
				route[i] = i / 2;
			}
			
		}
	}

	return dp[x];
}

int main(){
    int X;
    scanf("%d", &X);
    printf("%d\n", solve(X));
    //길 출력
    while(X){
        printf("%d ", X);
        X = route[X];
    }
    return 0;
}