#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> list[20001];
    int visit[20001];
    queue<int> q;
    
    for(int i=0; i<edge.size() ; i++){
        int a = edge[i][0];
        int b = edge[i][1];
        list[a].push_back(b);
        list[b].push_back(a);
    }
    
    int start = 1;
    visit[start] = 1;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<list[cur].size(); i++){
            int next = list[cur][i];
            if(visit[next]==0){
                visit[next] = visit[cur]+1;
                q.push(next);
            }
        }
    }
    int maxa = 0;
    int result = 0;
    for(int i=1; i<=n; i++){
        if(visit[i] > maxa){
            maxa = visit[i];
            result = 1;
        }else if(visit[i]==maxa){
            result++;
        }
    }
    
    
    return result;
}