#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int end, cost;
};
bool operator < (Node a, Node b){
    if(a.cost == b.cost){
        return a.end < b.end;
    }
    return a.cost < b.cost;
}

int N, M;
vector<Node> adj_list[1010];
int shortest[1010][1010];

void dijkstra (int start){
    for(int i=0; i<=N; i++){
        shortest[start][i] = 21e8;
    }
    priority_queue<Node> q;
    Node startnode;
    startnode.end = start;
    startnode.cost = 0;
    q.push(startnode);
    while(!q.empty()){
        Node cur = q.top();
        q.pop();
        for(int i=0; i<adj_list[cur.end].size(); i++){
            int next_cost = cur.cost + adj_list[cur.end][i].cost;
            if(shortest[start][adj_list[cur.end][i].end] > next_cost){
                shortest[start][adj_list[cur.end][i].end] = next_cost;
                Node nextnode;
                nextnode.end = adj_list[cur.end][i].end;
                nextnode.cost = next_cost;
                q.push(nextnode);
            }
        }
    }
}

int main(){

    cin >> N >> M;
    for(int i=0;i<N-1;i++){

        int a, b, cost;
        cin >> a >> b >> cost;
        Node temp;

        temp.end = b;
        temp.cost = cost;
        adj_list[a].push_back(temp);

        temp.end = a;
        temp.cost = cost;
        adj_list[b].push_back(temp);

    }

    for(int i=1; i<(N+1); i++){
        dijkstra(i);
    }

    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        cout << shortest[x][y] << endl;
    }

    return 0;
}