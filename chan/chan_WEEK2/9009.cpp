#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//현재 피보나치 수열에서 제일 큰 값 구하기
int max_fibo(int n){
    if(n<=1)
        return n;
    int f0 = 0;
    int f1 = 1;
    int f2;
    while(1){
        f2 = f0 + f1;
        if(f2 == n)
            return f2;
        else if(f2 > n)
            return f1;
        f0 = f1;
        f1 = f2;
    }  
}

void fibo(int n){
    int max;
    //n이 1인 경우 계산 할 필요 없이 처리
    if(n==1){
        printf("1");
        return;
    }
    //그 다음으로 제일 큰 값을 찾기
    max = max_fibo(n);

    //n-max가 0보다 크면
    if(n-max){
        //재귀로 그 다음 값 구하러감
        fibo(n-max);
        printf(" ");
    }
    //max값 출력
    printf("%d", max);
}

int main(){
    int T;
    int n;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &n);
        fibo(n);
        printf("\n");
    }
    return 0;
}