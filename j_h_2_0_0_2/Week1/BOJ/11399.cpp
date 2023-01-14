#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> P(N);
    int sum = 0, temp = 0;

    for(int i = 0; i < N; i++){
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    for(int i =0; i < N; i++){
        temp += P[i];
        sum += temp;
    }
    cout << sum << endl;

    return 0;
}