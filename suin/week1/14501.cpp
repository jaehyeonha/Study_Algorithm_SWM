#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;


struct Appointment{
    int start;
    int end;
    int value;
};

int main(){

    int N;
    cin >> N;

    Appointment ap[16];
    int dp[16] = {0};

    for(int i = 0 ; i < N; i++){
        ap[i].start = i;
        cin >> ap[i].end >> ap[i].value;
        ap[i].end += i;
    }
    // 1. 뒤에서 부터 dp를 채운다.
    // 2. dp[k]에는 k부터 N-1번째 날 동안 약속을 잡을 때, 가장 최적의 약속이 매꾸어진 상태의 값이다. 
    // 3. dp에는 해당 날을 시작하는 친구를 포함 했을 때, 가장 최적의 값을 나타낸다. 
// 7
// 3 10
// 5 20
// 1 10
// 1 20
// 2 15
// 4 40
// 2 200
    for(int i = N-1; i >= 0 ; i--){
        int max = 0;
        for(int j = ap[i].end; j <= N; j++ ){
            if(max < dp[j]+ap[i].value){
                max = dp[j]+ap[i].value;
            }
        }
        dp[i] = max;
    }

    int max = 0;
    for(int i = 0 ; i<N ; i++){
        cout << dp[i] << " ";
        if(max < dp[i]){
            max = dp[i];
        }
    }
    cout <<"\n" <<max;
    return 0;
}