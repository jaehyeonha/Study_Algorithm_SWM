#include<iostream>
#include<queue>

using namespace std;

int n;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int N, M;
    cin >> N >> M;
    queue<pair<int, int>> q; // <value, index>
    priority_queue<int> pq; // max heap
    for(int j = 0; j < N; j++){
      int input;
      cin >> input;
      q.push(make_pair(input, j));
      pq.push(input);
    }
    int cnt = 0;
    while(!q.empty()){
      if(q.front().first == pq.top()){
        cnt++;
        if(q.front().second == M){
          cout << cnt << endl;
          break;
        }
        else{
          q.pop();
          pq.pop();
        }
      }
      else{
        q.push(q.front());
        q.pop();
      }
    }
  }

  return 0;
}