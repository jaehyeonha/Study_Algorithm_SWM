#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> Nary;

//이분 탐색
int search(int start, int end, long long num){
    while(start<=end){
        int mid = (start + end) /2;
        if(Nary[mid] == num)
            return 1;
        else if(Nary[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

int main(){
    int N, M, ans;
    long long num;
    scanf("%d", &N);
    Nary.resize(N);

    for(int i=0; i<N; i++)
        scanf("%lld", &Nary[i]); 
       

    sort(Nary.begin(), Nary.end());

    scanf("%d", &M);

    for(int i=0; i<M; i++){
        scanf("%lld", &num);
        ans = search(0, N-1, num);
        printf("%d ", ans);
    }
    return 0;
}