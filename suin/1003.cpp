#include<iostream>

using namespace std;

int dp[41][2] = {0,}; // {0의 개수, 1의 개수}

int fibonacci(int n) {
    if (dp[n][0] != 0) {
        return dp[n][0];
    }
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 0;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacci_1(int n) {
    if (dp[n][1] != 0) {
        return dp[n][1];
    }
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_1(n - 1) + fibonacci_1(n - 2);
    }
}

int main(){


    for(int i = 0; i< 41; i++){
        dp[i][0] = fibonacci(i);
        dp[i][1] = fibonacci_1(i);
    }
    int T;
    cin >> T;
    for(int i = 0 ; i< T; i++){
        int cur;
        cin >> cur;
        cout << dp[cur][0] << " " <<  dp[cur][1]<<endl;
    }
    return 0;
}