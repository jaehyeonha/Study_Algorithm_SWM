#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binsearch(int x, vector<int>& S){
    int low, high, mid;
    low = 0; high = S.size()-1;
    int location = 0;
    while (low <= high && location == 0) {
        mid = (low + high) / 2;
        if (x == S[mid]){
            location = mid;
            return 1;
        }
        else if (x < S[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> Sang(N);

    for(int i= 0 ; i < N; i++){
        cin >> Sang[i];
    }
    sort(Sang.begin(), Sang.end());

    int M;
    cin >> M;
    vector<int> bin(M);

    for(int i= 0 ; i < M; i++){
        int location;
        cin >> bin[i];
        cout<< binsearch(bin[i], Sang)<<" ";
    }

    cout << endl;
    return 0;
}