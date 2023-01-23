#include<iostream>
#include<vector>
using namespace std;

vector<int> p;
vector<int> selected;

int main(){
  //n의 범위가 1000000000까지이므로 45까지 피보나치 미리 구해놓기
  p.push_back(0);
  p.push_back(1);
  for(int i=2; i<45; i++){
    p.push_back(p[i-1] + p[i-2]);
  }

  int T;
  cin >> T;
  for(int i=0; i<T; i++){
    //selected 초기화
    selected.clear();

    int n;
    cin >> n;
    int idx = 44;
    while(n > 0){
      if(p[idx] <= n){
        selected.push_back(idx);
        n -= p[idx];
      }
      idx--;
    }

    for(int i=selected.size()-1; i>=0; i--){
      cout << p[selected[i]] << " ";
    }
    cout << endl;

  }
  return 0;
}