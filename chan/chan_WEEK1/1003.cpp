#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(){
    int F[41] = {0, 1};
    for(int n=2; n<=40; n++)
        F[n] = F[n-1] + F[n-2];

    int N;
    int n;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &n);
        if(n==0)
            printf("1 0\n");
        else
            printf("%d %d\n", F[n-1], F[n]);
    }

}