#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> list[201];
int visit[201];

void bfs(int start, int color){
    queue<int> q;
    
    visit[start] = color;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<list[cur].size(); i++){
            int next = list[cur][i];
            if(visit[next]==0){
                visit[next] = color;
                q.push(next);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(computers[i][j]){
                list[i].push_back(j);
                list[j].push_back(i);
            }
        }
    }
    
    answer = 1;
    for(int i=0; i<n ; i++){
        if(visit[i]==0){
            bfs(i,answer);
            answer++;
        }
    }
    
    
    
    
    return answer-1;
}