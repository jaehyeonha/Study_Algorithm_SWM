#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, edges, x, y;
    int cnt = 0;
    scanf("%d", &N);
    scanf("%d", &edges);
    vector<int> G[101];
    vector<int> check(N, 0);
    queue<int> que;

    for(int i=0; i<edges; i++){
        //연결시켜줌
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    //1이랑 연관된 애들 체크 할거여서
    que.push(1);
    //이미 방문한 애들은 패스하려고 만듦
    check[1] = 1;
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        cnt++;
        for(int i=0; i<G[tmp].size(); i++){
            int next = G[tmp][i];
            if(!check[next]){
                que.push(next);
                check[next] = 1;
            }
        }
    }
    //처음 cnt++해준거 다시 빼줌
    cnt--;
    
    printf("%d", cnt);
    return 0;
}