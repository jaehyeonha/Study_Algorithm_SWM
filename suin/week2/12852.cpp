#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[100000]; //dp[k][0] : X = k 일때의 최선의 값
int method[100000]; //, dp[k][1] : X = k 일때의 최선의 값을 만들기 위해 바로 지금 사용되어야 할 연산

int f(int X){
    if(dp[X] != -1){
        return dp[X];
    }
    
    int first = f(X-1);
    
    int second = 10001000;
    if(X%2 == 0){
        second = f(X /2);
    }

    int third = 10001000;
    if(X%3 == 0){
        third = f(X /3);
    }
    int result;
    if( first <= second && first <= third){
        result = first;
        method[X] = 1;
    }
    else if( second<=first && second <= third){
        result = second;
        method[X] = 2;
    }
    else {
        result = third;
        method[X] = 3;
    }

    dp[X] = result+1;
    return f(X);
}

int main(){
    int X;
    cin >> X;
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;

    cout << f(X) <<endl;

    while(1 < X ){
        cout << X << " ";
        if( method[X] == 1){
            X--;
        }
        else if( method[X] == 2){
            X/=2;
        }
        else{
            X/=3;
        }
    }
    cout << X ;

    return 0;
}