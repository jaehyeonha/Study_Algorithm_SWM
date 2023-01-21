#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int R, C;
int total_sheep = 0;
int total_wolves = 0;
char RC[251][251];
int visited[251][251] = {0};
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input(){
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; i++){
        for(int j=0; j<=C; j++)
            scanf("%c", &RC[i][j]);
    }
          
}

void BFS(int a, int b){
    int cur_sheep = 0;
    int cur_wolves = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(a, b));
    visited[a][b] = 1;

    if(RC[a][b] == 'k')
        cur_sheep++;
    if(RC[a][b] == 'v')
        cur_wolves++;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<R && ny<C){
                if (!visited[nx][ny]){
                    if (RC[nx][ny] == '.'){
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                    }
                    else if (RC[nx][ny] == 'v'){
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                        cur_wolves++;
                    }
                    else if (RC[nx][ny] == 'o'){
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                        cur_sheep++;
                    }
                }
            }
        }
    }
    if(cur_sheep>cur_wolves)
        total_sheep += cur_sheep;
    else
        total_wolves += cur_wolves;
}

void solve(){
    for(int i=0; i<R; i++){
        for(int j=0; j<=C; j++){
            if(RC[i][j] == '#')
                continue;
            if(!visited[i][j])
                BFS(i, j);
        }
    }
}
int main(){
    input();
    solve();
    printf("%d %d", total_sheep, total_wolves);
    return 0;
}