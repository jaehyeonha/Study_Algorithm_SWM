// 그리디로 하면 안되는 문제<틀린 코드>
// 그리디로 했을 때 못보는 경우의 수가 생김. 예를 들어
// 2 1
// 2 60
// 30 98
// 65 25
// 인 경우, 2 60의 사다리를 타면 30 98의 사다리의 이득이 더 좋은 것을 모르고 넘어가게 됨.

#include<iostream>
#include<stack>

using namespace std;
int ar[101];
int ar2[101];
stack<int> s;

int main() {
    int N, M;

    cin >> N >> M;


    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        ar[a] = b;
    }
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ar[a] = b;
    }

    for(int i = 1; i<100;i++){

        if(ar2[i]!=0) {continue;}

        if(ar[i]==0){
            ar2[i] = i;
        }else{
            int t = i;
            s.push(t);
            while(ar2[t] == 0 && ar[t] != 0){
                t = ar[t];
                s.push(t);
            }
            while(!s.empty()){
                int a = s.top();
                s.pop();
                ar2[a] = t;
            }
        }
    }

    // for(int i= 0; i< 100; i++){
    //     cout << ar2[i]<< " ";
    // }

    int cnt = 0;
    for(int i = 1; i< 100;){
        cnt++;
        int max = 0;
        for(int j = 1; j < 7; j++){
            if(i+j >= 100){
                max = 100;
                break;
            }
            if( max < ar2[i+j]){
                max = ar2[i+j];
            }
        }
        i = max;
        // cout <<" : "<< i;
    }
    // cout << endl;
    cout << cnt;

    return 0;
}