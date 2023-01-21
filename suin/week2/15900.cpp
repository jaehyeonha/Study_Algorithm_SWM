#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int tr[500004] = {0,};
    bool isLeaf[500004] = {0,};
    vector< vector<int> > link;
    int N;
    cin >> N;

    // 이중 벡터 초기화, 자식 노드 확인 배열 초기화
    for(int i = 0;i<(N+1); i++){
        vector<int> v;
        link.push_back(v);
        if( 1 <= i && i <= N){
            isLeaf[i] = true;
        }else{
            isLeaf[i] = false;
        }
    }

    // 간선 기록 
    for(int i = 1 ; i < N; i++){
        int a,b;
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    // 1번 노드 부터 bfs 탐색
    queue<int> a;
    a.push(1);
    tr[1] = 1;
    while(!a.empty()){
        int i = a.front();
        a.pop();
        for(int j = 0; j< link[i].size(); j++){
            if(tr[link[i][j]] == 0){
                tr[link[i][j]] = tr[i]+1;
                isLeaf[i] = false;
                a.push(link[i][j]);
            }
        }

    }

    // 자식 노드 일 경우, 1번 노드로부터의 거리 더하기
    int result = 0;
    int max = 0;
    for(int i = 1; i<= N; i++){
        if( isLeaf[i]){
            result += tr[i]-1;
        }
    }
    if(result % 2 == 0){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
    return 0;
}