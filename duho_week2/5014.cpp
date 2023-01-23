#include<iostream>
#include<queue>
#define MAX 987654321
using namespace std;

int F, S, G, U, D;
int min_count = MAX;

void bfs(int start){
  queue<pair<int, int>> q;
  bool visited[1000001] = {false,};
  q.push(make_pair(start, 0));
  visited[start] = true;

  while(!q.empty()){
    int cur = q.front().first;
    int count = q.front().second;
    q.pop();

    if(cur == G){
      if(min_count > count){
        min_count = count;
      }
      return;
    }

    if(cur + U <= F && !visited[cur + U]){
      q.push(make_pair(cur + U, count + 1));
      visited[cur + U] = true;
    }
    if(cur - D >= 1 && !visited[cur - D]){
      q.push(make_pair(cur - D, count + 1));
      visited[cur - D] = true;
    }
  }
}

int main(){
  cin >> F >> S >> G >> U >> D;

  bfs(S);
  if(min_count == MAX){
    cout << "use the stairs" << endl;
  }
  else{
    cout << min_count << endl;
  }

  return 0;
}