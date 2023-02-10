#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int end, score;
};
bool operator <(Node a, Node b){
    return (a.score==b.score)?a.end>b.end:a.score>b.score;
}
int V, E;
vector<Node> list[10001];
priority_queue<Node> pq;

int main(){
    cin >> V >> E;
    for(int i=0; i<V; i++){
        int a,b,score;
        cin >> a>> b>> score;
        Node temp_node;
        temp_node.end = b;
        temp_node.score = score;
        list[a].push_back(temp_node);
        temp_node.end = a;
        list[b].push_back(temp_node);
    }
    
    pq.p
}
