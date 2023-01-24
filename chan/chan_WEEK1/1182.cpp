#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int N;
int S;
vector<int> sub;

void solution(int cur, int total){
    if(cur == N){
        //tree 마지막 level에 total과 같은 S 있는 만큼 cnt++
        if(total == S)
            cnt++;
        return;
    }
    //level 증가 및 한 쪽은 total과 현재 sub를 더해서 내려감
    solution(cur+1, total+sub[cur]);
    //level 증가 및 한 쪽은 total 그대로 내려감
    solution(cur+1, total);
}

int main(){
    scanf("%d %d", &N, &S);
    
    sub.resize(N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &sub[i]);
    
    solution(0, 0);
    if(S==0)
        cnt--;
    printf("%d", cnt);
    return 0;
}