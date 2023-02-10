#include<iostream>
#include<map>

using namespace std;
int N, M;
map<int,int> m;
int main(){

    cin.tie(0);
    cin >> N;
    for(int i=0;i<N; i++){
        int num ;
        cin >> num ;
        if(m.find(num)==m.end()){
            m.insert(make_pair(num,1));
        }
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int test;
        cin>>test;
        if(m.find(test)==m.end()) cout << 0;
        else cout << 1;
        cout << " ";
    }
    return 0;
}