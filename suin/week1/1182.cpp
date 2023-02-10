#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N, target;
vector<int> ar;
map<int, int> m;

void check(int last, int s){
    if(last == N) {
        if(m.find(s)==m.end()){
            m.insert(make_pair(s,1));
        }else{
            m[s]++;
        }
        return;
    }
    check(last+1,s+ar[last]);
    check(last+1,s);

}
int main(){
    cin >> N >> target ;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        ar.push_back(temp);
    }

    check(1,ar[0]);
    check(1,0);

    // map<int, int> ::iterator iter;
    // for(iter = m.begin(); iter != m.end(); iter++){
    //     cout <<iter->first<<" : "<<iter->second<<endl;
    // }

    if(m.find(target)==m.end()){
        cout << 0;
    }else{
        if(target == 0){
            cout<< m[target]-1;
        }
        else{
            cout << m[target];
        }
    }

    return 0;
}