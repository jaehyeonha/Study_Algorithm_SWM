#include<iostream>
#include<stack>
#include<cmath>
#include<cstring>

using namespace std;

int N;
int people[11];
int adj_list[11][11];
bool sar[11];
int visit[11];
int result=21e8;

bool paint(int color, int start, bool selected){
    stack<int> s;
    s.push(start);
    visit[start] = color;
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        for(int i=1; i<=adj_list[cur][0];i++){
            int next = adj_list[cur][i];
            if( (visit[next] == 0) && (sar[next] == selected) ){
                visit[next] = color;
                s.push(next);
            }
        }
    }
    
    return true;

}
void combi(int last, bool selected){ 
    sar[last] = selected;
    if(last < (N-1) ){
        combi(last+1, true);
        combi(last+1, false);
        return ;
    }
    
    memset(visit,0,sizeof(visit));
    bool paint_a=true, paint_b=true;
    for(int i=0; i<N; i++){
        if(sar[i]&&paint_a){
            paint(1,i,true);
            for(int i=0;i<N;i++){
                if(sar[i]&&visit[i]!=1){
                    return ;
                }
            }
            paint_a = false;
        }else if(!sar[i] && paint_b){
            paint(2,i,false);
            paint_b = false;
        }
        if(!paint_a && !paint_b){
            break;
        }
    }

    int sum = 0 ;
    for(int i=0; i<N; i++){
        if(visit[i]==0){
            return;
        }else if(visit[i]==1){
            sum += people[i];
        }else if(visit[i]==2){
            sum -= people[i];
        }
    }

    sum = abs(sum);
    if(result > sum){
        result = sum;
    }

    // cout<<" --- ";
    // for(int i=0; i<N; i++){
    //     cout << visit[i] << " ";
    // }
    // cout<<":";
    // for(int i=0; i<N; i++){
    //     cout << sar[i] << " ";
    // }
    // cout<<" = " <<sum<<endl;
    return ;
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> people[i];
    }

    for(int i=0; i<N; i++){
        cin >> adj_list[i][0];
        for(int j=1; j<=adj_list[i][0]; j++){
            int a;
            cin >> a;
            adj_list[i][j]=a-1;
        }
    }

    combi(0,true);
    combi(0,false);

    if(result > 10e8){
        cout << -1;
        return 0;
    }

    cout << result;
    return 0;

}