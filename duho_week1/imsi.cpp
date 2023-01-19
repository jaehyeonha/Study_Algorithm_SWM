#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int DP[101][100001];  //물건, 무게
int W[101];
int V[101];

int main(){
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		cin >> W[i] >> V[i];  //무게, 가치
  }
  //DP[i][j] = i번째 물건까지 고려했을 때, 무게가 j일 때의 최대 가치
  //바텀업 방식
  for (int i = 1; i <= N; i++){
		for (int j = 1; j <= K; j++){
			 if (j - W[i] >= 0){
        DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
       }
       else{ 
        DP[i][j] = DP[i - 1][j];
       }
    }
	}

	cout << DP[N][K];

  return 0;
}