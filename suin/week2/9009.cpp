#include<iostream>
#include<cstring>
#include<cmath>
#include<stack>

using namespace std;

int dp[45];
int fibo( int x){
    if(dp[x] == -1){
        dp[x] = fibo(x-2)+fibo(x-1);
    }
    return dp[x];
}
int main(){
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < 44; i++){
        fibo(i);
        //cout << fibo(i) << " ";
    }
    //cout << endl;

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int n;
        cin >> n;

        stack<int> s;
        for( int j = 43; j >= 1; j-- ){
            if( (n - dp[j]) >= 0 ){
                //cout << dp[j] << " ";
                n -= dp[j];
                s.push(dp[j]);
            }
            if(n == 0){
                break;
            }
        }

        while(!s.empty()){
            cout << s.top()<< " ";
            s.pop();
        }
        cout << endl;
    }

    return 0;
}