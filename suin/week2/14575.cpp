#include<iostream>

using namespace std;
int L[1001];
int R[1001];
int main(){
    int N, T;
    cin >> N >> T;

    for(int i=0; i<N; i++){
        cin >> L[i] >> R[i];
    }
    
    int maxL = 0;
    int maxR = 0;
    int summin = 0;
    for(int i=0; i<N; i++){
        if(maxL < L[i]){
            maxL = L[i];
        }
        if(maxR < R[i]){
            maxR = R[i];
        }
        summin += L[i];
    }
    if(summin > T){
        cout << -1;
        return 0;
    }

    for(int i = maxL; i<=maxR; i++){
        int sum = 0;
        for(int j = 0; j<N; j++){
            if(R[j] < i){
                sum += R[j];
            }
            else{
                sum += i;
            }
        }
        if( sum >= T){
            cout << i;
            return 0 ;
        }
    }
    cout << -1;
    return 0 ;

}