#include<iostream>
#include<algorithm>

using namespace std;

int N;
int ar[10001001];

int main(){
    cin >> N;

    for(int i=0;i<N; i++){
        cin >> ar[i];
    }

    sort(ar,ar+N);
    for(int i=N-1; i>=2;i--){
        if(ar[i] < ar[i-1]+ar[i-2]){
            cout <<ar[i]+ar[i-1]+ar[i-2];
            return 0;
        }
    }
    cout << -1;
    return 0;
}