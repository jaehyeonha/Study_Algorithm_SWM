#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, C;
vector<int> list[101];
int visit[101];
int main(){

    cin >> N >> C;

    for(int i=0; i<C; i++){
        int a,b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    int cnt = 0;
    queue<int> q;
    visit[1]=1;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<list[cur].size(); i++){
            int next = list[cur][i];
            if(visit[next]!=0) continue;
            visit[next] = 1;
            q.push(next);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}