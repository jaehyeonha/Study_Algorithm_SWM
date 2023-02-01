#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> v;
vector<int> dp;
int main(){

    cin >> N;
    for(int i=0; i<N; i++){
        int t;
        cin >> t;
        v.push_back(t);
        if(i==0){
            dp.push_back(t);
        }
        else{
            dp.push_back(max(t,dp[i-1]+t));
        }
    }
    int maxa=-21e8;

    for(int i=0; i<N; i++){
        maxa = max(maxa,dp[i]);
    }

    cout << maxa;
    return 0;
}