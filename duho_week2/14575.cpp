#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, T;
vector <pair<int,int>> person;

int binary_search(int low, int high){
  int mid;
  while (low < high){
    int sum = 0;
    mid = (low + high) / 2;
    for (int i = 0; i < person.size(); i++) {
      if (person[i].first > mid) {
        sum = 0;
        break;
      }
      sum += min(mid, person[i].second);
    }
    if(sum < T){
      low = mid + 1;
    }
    else{
      high = mid;
    }
  }
  return high;
}

int main()
{
  cin >> N >> T;

  int min = 0, max = 0;

  for(int i = 0; i < N ; i++){
    int L, R;
    cin >> L >> R;
    person.push_back({L,R});
    min += L;
    max += R;
  }
  if(min > T || max < T){
    cout << -1 << endl;
  }
  else{   
    cout << binary_search(0,1000000) << "\n";
  }

  return 0;
}