#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[10000001] = {0, };

void bfs(){
    queue <int> que;
    //시작 위치 큐에 푸쉬
    que.push(S);
    visited[S] = 1;

    while(!que.empty()){
        int tmp = que.front();
        que.pop();

        //목표 지점이면 
        if(tmp == G){
            //초기값 1 빼줘서 프린트
            printf("%d", visited[tmp]-1);
            return;
        }

        //다음거 +U
        int nxt = tmp + U;
        if(nxt<=F){ //segfault오류로 인해 방문 공간 체크 전 F보다 작은지 먼저 확인
            if(!visited[nxt] && nxt<=F){ //방문 안 한 곳 + F보다 작아야함
                que.push(nxt);
                visited[nxt] = visited[tmp] + 1; //방문 배열을 통해서 횟수 기록
            }
        }

        //다음거 -D
        nxt = tmp - D;
        if(nxt>0){ //sefault 오류 또 발생 -> 위의 이유로 사전 검사
            if(!visited[nxt] && nxt>0){ //방문 안 한 곳 + 0보다는 커야함
                que.push(nxt);
                visited[nxt] = visited[tmp] + 1;
            }
        }   
    }
    printf("use the stairs");
}

int main(){
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    bfs();
    return 0;
}