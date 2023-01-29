#include<iostream>
#include<queue>

using namespace std;

int N, M;
int ar[101];
int visit[101];

int main(){

    cin >> N >> M ;
    for(int i = 0 ; i < (N+M); i++){
        int a,b;
        cin >> a >> b;
        ar[a] = b;
    }

    for( int i =1; i<101; i++){
        if(ar[i] == 0){
            ar[i] = i;
        }
    }

    //bfs
    queue<int> q;
    q.push(1);
    visit[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i =1; i<7 && (i+cur<=100); i++){
            if(visit[ar[cur+i]] == 0){
                q.push(ar[cur+i]);
                visit[ar[cur+i]] = visit[cur]+1;
            }
        }
    }

    // for(int i = 0; i< 101; i++){
    //     cout << visit[i] << " ";
    // }
    cout << visit[100];

    return 0;
}