#include<iostream>

using namespace std;

int main(){
    int prior[101];
    int connect[101];
    
    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++){
        int N, x;
        cin >> N >> x;
        int cnt[10] = {0};
        for(int j = 0 ; j < N; j++){
            cin >> prior[j];
            connect[j] = (j + 1) % N;
            cnt[prior[j]]++;
        }

        
        // cout << "\n";
        bool flag = false;
        // 전체를 원처럼 연결 시켜 놓고 우선 순위 9부터 1까지 차례로 돌아가면서 뺌
        int before = N - 1;
        int cur = 0;
        int res = 0;
        for(int p = 9 ; p > 0; p--){
            // for(int h = 0; h< N;h++){
            //     cout << " ^ " << connect[h];
            // }
            // cout << "\n";
            while(cnt[p] != 0){
                if(prior[cur] == p){  
                    // cout << " prior[cur]: " << prior[cur] << " p: "<< p << " cur: " << cur << " x: "<< x << "\n";
                    // 현재 빼는 우선 순위에 해당한다 -> 뺀다 -> 연결고리를 스킵하도록 한다.>>
                    cnt[p]--;
                    res++;
                    if(cur == x){
                        flag = true;
                        break;
                    }
                    int temp = connect[cur];
                    connect[before] = connect[cur];
                    cur = temp;
                    continue;
                }
                
                before = cur;
                cur = connect[cur];
            }
            if(flag){
                break;
            }
        }

        cout << res << "\n";
    } 
    return 0;
}