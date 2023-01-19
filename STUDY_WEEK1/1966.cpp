#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main(){
    
    int tcase;
    int N;
    int idx;
    int pri;
    int when;
    

    //test case 입력
    scanf("%d", &tcase);

    for(int i=0; i<tcase; i++){
        when = 0;
        //문서의 개수 N과 궁금한 문서 idx 입력
        scanf("%d %d", &N, &idx);

        // 큐에 중요도를 순서대로 입력 및 우선순위 큐에도 중요도 입력 
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int j=0; j<N; j++){
            scanf("%d", &pri);
            q.push({j, pri});
            pq.push(pri);
        }
      
        // 큐가 빌 때까지
        while(!q.empty()){
            // 큐에 가장 앞에 있는 pair 저장 후 pop
            int loc = q.front().first;
            int val = q.front().second;
            q.pop();

            //우선순위 큐의 top과 val이 같다면 즉, 우선순위 큐와 큐의 젤 앞에 있는 애들이 가장 중요도가 높은 경우
            if(val == pq.top()){
                //우선순위도 pop
                pq.pop();

                //언제 출력되는지 변수 증가
                ++when;
               
                //궁금했던 idx가 loc과 같다면 원하는 게 pop되었다면 when 출력 후 종료
                if(idx == loc){
                    printf("%d\n", when);
                    break;
                }   
            }
            else{
                //아닌 경우 처음값 뒤로 가야함g
                q.push({loc, val});
            }
        }
        
    }
    return 0;
}