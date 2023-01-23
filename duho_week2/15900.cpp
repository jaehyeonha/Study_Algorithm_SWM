#include<iostream>
#include<vector>

using namespace std;

int n;  //노드의 개수 n
vector<int> tree[500001];
bool visited[500001] = {false,};
int height_sum = 0;

void DFS(int node, int depth){
  //리프노드일 경우, 연결된 노드가 부모노드 하나
  if(tree[node].size() == 1 && node != 1){
    height_sum += depth;
    return;
  }

  for(int i=0; i<tree[node].size(); i++){
    int next = tree[node][i];
    //방문하지 않은 노드일 경우
    if(!visited[next]){
      visited[next] = true;
      DFS(next, depth+1);
      visited[next] = false;
    }
  }
}

int main(){
  cin >> n;
  
  int a,b;
  for(int i=0; i<n-1;i++){
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  visited[1] = true;
  //루트노드(1)에서 DFS
  DFS(1,0);

  if(height_sum % 2 == 0){
    cout << "No";
  }
  else{
    cout << "Yes";
  }

  return 0;
}