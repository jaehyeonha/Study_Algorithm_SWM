#include<iostream>

using namespace std;

int pre[1001001];
int post[1001001];
int siz = 0;
int i = 1;


void findroot(int start, int end){
    //cout << start << " : " << end <<endl;
    post[siz - i] = pre[start];
    i++;
    if(start+1==end){
        return;
    }
    int root = pre[start];
    int k;
    for(k=start+1; k<end; k++){
        if(root < pre[k]){
            break;
        }
    }
    if(k < end){
        findroot(k,end);
    }
    if(start+1 < k){
        findroot(start+1,k);
    }
}
int main(){
    while(1){
        cin >> pre[siz];
        if(cin.eof()){
            break;
        }
        siz++;
    }

    findroot(0,siz);

    for(int k=0; k<siz; k++){
        cout << post[k]<<endl;
    }

}