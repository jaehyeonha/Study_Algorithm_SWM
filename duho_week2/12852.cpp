#include<iostream>
#include<vector>
using namespace std;

int n;
int dp[1000001] = {0,};

int solve(int n){
  if(n == 1){
    return 0;
  }
  if(dp[n] > 0){
    return dp[n];
  }
  dp[n] = solve(n-1) + 1;
  if(n % 2 == 0){
    int temp = solve(n/2) + 1;
    if(dp[n] > temp){
      dp[n] = temp;
    }
  }
  if(n % 3 == 0){
    int temp = solve(n/3) + 1;
    if(dp[n] > temp){
      dp[n] = temp;
    }
  }
  return dp[n];
}


int main(){
  cin >> n;

  cout << solve(n) << endl;

  while(n != 1){
    cout << n << " ";
    if(dp[n-1] == dp[n] - 1){
      n = n-1;
    }
    else if(n % 2 == 0 && (dp[n/2] == dp[n] - 1)){
      n = n/2;
    }
    else if(n % 3 == 0 && (dp[n/3] == dp[n] - 1)){
      n = n/3;
    }
  }
  cout << 1 << endl;

  return 0;


}