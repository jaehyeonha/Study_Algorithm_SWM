#include<iostream>
#include<vector>

using namespace std;

int parent[10001];
struct edge{
    int first, end, cost;
};
edge e[100010];

bool comp (edge a, edge b){
    return a.cost < b.cost;
}
int get_parent(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = get_parent(parent[node]);
}



int main(){
    int V, E;
    cin >> V >> E;

    for(int i=0; i<E; i++){
        cin >> e[i].first >> e[i].end >> e[i].cost;
    }
    sort(e, e + E, comp);

    for(int i=0; i<V; i++){
        parent[i] = i; 
    }

    int sum = 0;
    for(int i=0; i<E; i++){
        int first = e[i].first;
        int end = e[i].end;
        int cost = e[i].cost;
        
        int p1 = get_parent(first);
        int p2 = get_parent(end);
        if(p1 == p2){
            continue;
        }

        parent[p1] = p2;

        sum += cost; 
    }

    cout << sum;
    return 0;
}
