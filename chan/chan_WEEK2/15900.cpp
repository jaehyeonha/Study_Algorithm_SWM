#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[500001];
bool check[500001];
int cnt = 0;

void dfs(int tmp, int level){
    //leaf노드 일 때
    if(tmp != 1 && graph[tmp].size() == 1){
        if(level%2 == 1) //깊이가 홀수일 때 cnt 증가
            cnt++;
        return;
    }

    for(int i=0; i<graph[tmp].size(); i++){
        if(check[tmp] == false){ //처음 가는 길이면
            check[tmp] = true; //현재 길에서는 다시 이 길 안가도록 설정...
            dfs(graph[tmp][i], level+1); //다음 길을 찾아
            check[tmp] = false; //리셋해야니깐....
        }
    }
}

int main(){
    scanf("%d", &N);

    for(int i=0; i<N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0);
    if(cnt%2 == 1) //cnt의 수가 홀수면 이길 수 있음 -> 짝수 상관 없이 홀수가 홀수 번 있으면 무조건 홀수임
        printf("Yes");
    else
        printf("No");
    return 0;
}