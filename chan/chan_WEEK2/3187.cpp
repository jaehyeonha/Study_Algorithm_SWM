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
    //초기 a, b가 양이나 늑대면 증가
    if(RC[a][b] == 'k')
        cur_sheep++;
    if(RC[a][b] == 'v')
        cur_wolves++;
    
    //큐가 빌 때까지 반복 -> 길 다 찾을 때까지!!
    while(!que.empty()){
        //x, y는 기준점
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i=0; i<4; i++){
            //nx, ny는 기준점에서 갈 수 있는 모든 곳
            int nx = x + dx[i]; 
            int ny = y + dy[i];
            //조건에 성립하면 nx, ny 체크
            if(nx>=0 && ny>=0 && nx<R && ny<C){
                if (!visited[nx][ny]){
                    //그냥 빈 공간이면 큐에만 추가
                    if (RC[nx][ny] == '.'){
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                    }
                    //늑대가 있다면 증가 및 큐에 추가
                    else if (RC[nx][ny] == 'v'){
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                        cur_wolves++;
                    }
                    //양이 있다면 증가 및 큐에 추가
                    else if (RC[nx][ny] == 'k'){
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                        cur_sheep++;
                    }
                }
            }
        }
    }
    //양이 더 많은 경우
    if(cur_sheep>cur_wolves)
        total_sheep += cur_sheep;
    else //수가 같거나 늑대가 더 많은 경우
        total_wolves += cur_wolves;
}

void solve(){
    for(int i=0; i<R; i++){
        for(int j=0; j<=C; j++){
            //#이면 그냥 무시
            if(RC[i][j] == '#')
                continue;
            //다음 빈 공간을 체크 -> 탐색 안 한 곳만 체크
            if(!visited[i][j])
                BFS(i, j);
        }
    }
}
int main(){
    //입력
    input();
    //문제 해결
    solve();
    //결과 출력
    printf("%d %d", total_sheep, total_wolves);
    return 0;
}