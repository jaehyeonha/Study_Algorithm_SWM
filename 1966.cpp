#include<iostream>
#include<queue>

using namespace std;

void main(){
    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++){
        int N, x;
        int ar[101] = { 0 };
        bool ch[10];
        memset(ch,false,10*sizeof(bool));
        cin >> N >> x;

        queue <int> q;
        for(int j = 0; j < N; j++){
            cin >> ar[j];
            if(ch[ar[j]]==false){
                ch[ar[j]] = true;
            }
            q.push(j);
        }
        
        bool conti = false;
        int res = 0;
        while(q.front() != x){
            conti = false;
            for(int j = (ar[q.front()]+1); j < 10; j++){
                if(ch[j] == true){
                    q.push(q.front());
                    q.pop();
                    conti = true;
                }
            }
            if(conti){
                continue;
            }
            q.pop();
            break;
        }
        res++;

        cout << res;

    } 

}