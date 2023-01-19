#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    int tmp = 0;
    int total = 0;
    scanf("%d", &N);
    vector<int> ary(N);
    for(int i=0; i<N; i++)
        scanf("%d", &ary[i]);
    
    sort(ary.begin(), ary.end());

    for(int i=0; i<N; i++){
        tmp += ary[i];
        total += tmp;
    }
    printf("%d", total);
    return 0;
}