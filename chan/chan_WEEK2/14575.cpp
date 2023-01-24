#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector <pair<int, int>> lr;

int check(int mid, int T){
    int max2 = 0;
    int min2 = 0;
    for(int i=0; i<lr.size(); i++){
        if(lr[i].first > mid){
            return 0;
        }
        max2 += (min(mid, lr[i].second) - lr[i].first);
        min2 += lr[i].first;
    }
    if(max2 >= T - min2) 
        return 1;
    else
        return 0;
}
int main(){
    int N, T;
    int min1 = 0;
    int max1 = 0;
    int low = 0;
    int high = 0;
    int l = 0;
    int r = 0;
    int mid = 0;
    int ans = 9999999;
    scanf("%d %d", &N, &T);

    for(int i=0; i<N; i++){
        scanf("%d %d", &l, &r);
        min1 += l;
        max1 += r;
        high = max(high, r);
        lr.push_back({l, r});
    }
    
    if(min1>T || max1<T){
        printf("-1");
        return 0;
    }

    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid, T)){
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;

    }

    printf("%d", ans);
    return 0;
}