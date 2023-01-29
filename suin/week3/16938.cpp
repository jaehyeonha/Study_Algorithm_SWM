#include<iostream>

using namespace std;

int N, L, R, X;
int a[16];
int select11[16];
int mina, maxa, sum;
int cnt = 0;
void f(int cur){
    if(cur == N){
        mina = 21e8;
        maxa = -21e8;
        sum = 0;
        for(int i=0; i<N; i++){
            if(select11[i]==1){
                if(mina > a[i]){
                    mina = a[i];
                }
                if(maxa < a[i]){
                    maxa = a[i];
                }
                sum += a[i];
            }
        }
        if(L <= sum && sum <= R && X <= (maxa-mina)){
            cnt++;
        }
        return;
    }
    select11[cur] = 1;
    f(cur+1);
    select11[cur] = 0;
    f(cur+1);
}

int main(){

    cin >> N >> L >> R >> X;

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    f(0);
    
    cout << cnt;

    return 0;
}