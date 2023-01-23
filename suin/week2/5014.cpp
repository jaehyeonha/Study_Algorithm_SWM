#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dp[1001000];
int F, S, G, U, D;
int bfs(int x){
    queue<int> q;
    q.push(x);
    dp[x] = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        int next = a - D;
        if(1 <= next && next <= F && dp[next] == -1){
            q.push(next);
            dp[next] = dp[a]+1;
        }
        next = a + U;
        if(1 <= next && next <= F && dp[next] == -1){
            q.push(next);
            dp[next] = dp[a]+1;
        }
    }   
    return 0; 
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> F >> S >> G >> U >> D;

    bfs(S);

    if( dp[G] == -1){
        cout << "use the stairs";
    }else{
        cout << dp[G];
    }
    return 0;
}