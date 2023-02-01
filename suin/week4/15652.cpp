#include<iostream>

using namespace std;


int N, M;
int a[9];

void select(int cur_index, int selected){
    a[selected] = cur_index;
    selected++;
    if(selected == M){
        for(int i=0; i<M; i++){
            cout << a[i]<< " ";
        } 
        cout << endl;
        return;
    }
    for(int i=cur_index; i<=N; i++){
        select(i,selected);
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i=1; i<=N;i++){

        select(i,0);
    }
}