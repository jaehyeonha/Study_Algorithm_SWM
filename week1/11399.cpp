#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> T;

int main(){
  cin >> N;
  T.resize(N);
  for(int i = 0; i < N; i++){
    cin >> T[i];
  }
  //T 오름차순 정렬
  sort(T.begin(), T.end());

  int sum = 0;
  int result = 0;
  for(int i = 0; i < N; i++){
    sum += T[i];
    result += sum;
  }
  cout << result << "\n";

  return 0;

}