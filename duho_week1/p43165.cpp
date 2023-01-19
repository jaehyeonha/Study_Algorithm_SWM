#include <string>
#include <vector>

using namespace std;

vector<int> number_v;
int targ;
int cnt =0;

void dfs(int sum, int idx){
  if(idx == number_v.size()){
    if(sum == targ){
      cnt++;
    }
  }
  else{
    dfs(sum + number_v[idx], idx + 1);
    dfs(sum - number_v[idx], idx + 1);
  }
}

int solution(vector<int> numbers, int target) {
    number_v = numbers;
    targ = target;
    dfs(0,0);
    return cnt;
}

