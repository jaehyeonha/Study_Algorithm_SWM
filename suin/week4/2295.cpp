#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> ar;
map<int,int> mplus;
map<int,int> mminus;

int main(){
    int temp;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        ar.push_back(temp);
    }

    sort(ar.begin(),ar.end());

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp = ar[i]+ar[j];
            if(mplus.find(temp)==mplus.end()){
                mplus.insert(make_pair(temp,0));
            }
        }
    }

    for(int i=0; i<N; i++){ // 만드는 수 
        for(int j=0; j<i; j++){
            temp = ar[i]-ar[j];
            if(mminus.find(temp)==mminus.end()){
                mminus.insert(make_pair(temp,ar[i]));
            }else{
                mminus[temp] = ar[i];
            }
        }
    }

    map<int,int>::iterator it=mminus.end();

    map<int,int> result;
    for(int i=0; i<mminus.size(); i++){
        it--;
        if(mplus.find(it->first)!=mplus.end()){
            if(result.find(it->second)==result.end()){
                result.insert(make_pair(it->second,0));
            }
        }
    }
    it=result.end();
    it--;
    cout << it->first;
    return 0;

}