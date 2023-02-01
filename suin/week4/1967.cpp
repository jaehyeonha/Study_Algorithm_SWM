#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>


using namespace std;

int N;
int cost[10010];

struct Node{
    int end, score;
};
vector<Node> list[10010];

bool operator < (Node a, Node b){
    return (a.score == b.score)? a.end<b.end : a.score<b.score;
}
bool operator > (Node a, Node b){
    return (a.score == b.score)? a.end>b.end : a.score>b.score;
}

void dijkstra(int start){
    priority_queue<Node,vector<Node>,greater<Node> > heap;
    Node startnode;
    startnode.end = start;
    startnode.score = 0;
    cost[start]=0;
    heap.push(startnode);
    while(!heap.empty()){
        Node cur = heap.top();
        heap.pop();
        for(int i=0; i<list[cur.end].size(); i++){
            Node next = list[cur.end][i];
            next.score = cur.score + list[cur.end][i].score;
            if(cost[next.end] < next.score) continue;
            cost[next.end] = next.score;
            heap.push(next);
        }
    }
}

int main(){
    cin >> N;
    if(N==1){
        cout << 0;
        return 0;
    }
    for(int i=0;i<N-1;i++){
        int a, b, w;
        cin >> a >> b >> w;
        Node node;
        node.end = b;
        node.score = w;
        list[a].push_back(node);
        node.end = a;
        list[b].push_back(node);
    }

    memset(cost, 0, sizeof(cost));
    for(int i=1;i<=N;i++){
        cost[i] = +21e8;
    }
    dijkstra(1);

    Node result;
    result.score = -21e8;
    for(int i=1; i<=N; i++){
        //cout << cost[i] << " ";
        if(result.score < cost[i]){
            result.end = i;
            result.score = cost[i];
        }
    }
    // cout << " : ";

    
    memset(cost, 0, sizeof(cost));
    for(int i=1;i<=N;i++){
        cost[i] = +21e8;
    }
    dijkstra(result.end);

    result.score = -21e8;
    for(int i=1; i<=N; i++){
        //cout << cost[i] << " ";

        if(result.score < cost[i]){
            result.end = i;
            result.score = cost[i];
        }
    }
    //cout << endl;


    cout << result.score;

    return 0;
}