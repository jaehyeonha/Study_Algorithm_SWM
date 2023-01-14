#include<iostream>
#include<algorithm>

using namespace std;
int bag [101][101000] = {0,}; 
// bag[a][b] : a번째 물건까지 살펴 보았을 때, b무게 일때의 최대 가치값
// 

int main(){

    int N, K;
    cin >> N >> K;

    int W[101];
    int V[101];
    for(int i=1 ; i<N; i++){
        cin >> W[i] >> V[i];
    }

    for(int i = 1; i< N; i++){
        for(int j = 1; j <= K; j++){
            if( j-W[i] < 0 ){
                bag[i][j] = max(bag[i-1][j], 0);
                continue;
            }
            bag[i][j] = max(bag[i-1][j], bag[i-1][j-W[i]]+V[i]);
        }
    }
    
    cout << bag[N-1][K];

    return 0;
}