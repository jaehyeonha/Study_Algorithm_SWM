#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int N,M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;
int result = 987654321;

void chicken_distance(){
  int sum = 0;
  for(int i=0; i<house.size(); i++){
    int min_distance = 987654321;
    for(int j=0; j<selected.size(); j++){
      int distance = abs(house[i].first - selected[j].first) + abs(house[i].second - selected[j].second);
      min_distance = min(min_distance,distance);
    }
    sum += min_distance;
  }
  result = min(result,sum);
}

void backtracking(int start,int cnt){
  if(cnt == M){
    chicken_distance();
    return;
  }
  for(int i=start; i<chicken.size(); i++){
    selected.push_back(chicken[i]);
    backtracking(i+1,cnt+1);
    selected.pop_back();
  }
}

int main(){
  cin >> N >> M;
  int input;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cin >> input;
      if(input == 1)
        house.push_back({i,j});
      else if(input == 2)
        chicken.push_back({i,j});
    }
  }

  backtracking(0,0);
  cout << result;

  return 0;
}