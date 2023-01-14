#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    int ar[1001];
    for( int i = 0;i<N; i++){
        cin >> ar[i];
    }

    sort(ar, ar+N,greater<int>());
    int sum = 0;
    for(int i = 0 ; i< N; i++){
        sum += ar[i]* (i+1);
    }

    cout << sum;
    return 0;
}
