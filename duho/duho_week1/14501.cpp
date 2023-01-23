#include<iostream>

using namespace std;

int N;
int T[16];
int P[16];
int maxProfit = 0;

//N이 작으므로 브루트포스로 풀어도 된다.
void dfs(int day, int profit){
  if(day == N + 1){
    if(profit > maxProfit){
      maxProfit = profit;
    }
    return;
  }
  if(day > N + 1){
    return;
  }
  dfs(day + 1, profit);
  dfs(day + T[day], profit + P[day]);
}

int main(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> T[i] >> P[i];
  }
  dfs(1, 0);
  cout << maxProfit << endl;

  return 0;
}
