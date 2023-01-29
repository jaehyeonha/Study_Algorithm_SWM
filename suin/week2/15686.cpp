#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
int ar[51][51];
int dis[13][101];
int shop[13][2];
int house[101][2];

int N, M;
int cnt_h = 0;
int cnt_s = 0;

bool selected_shop[13];

int cnt_select = 0;
int result = 21e8;
bool flag;

int cost(){
    flag = false;

    int sum = 0;
    int min;
    for(int i=0; i<cnt_h; i++){
        min = 21e8;
        for(int j=0; j<cnt_s; j++){
            if(selected_shop[j]){
                flag = true;
                if(min > dis[j][i]){
                    min = dis[j][i];
                }
            }
        }
        sum += min;
    }
    return sum;
}
void dfs(int cur_s){
    if(cur_s >= cnt_s){
        int cost_cur = cost();
        if( result > cost_cur && flag){
            result = cost_cur;
        }
        return ;
    }
    
    selected_shop[cur_s] = true;
    cnt_select++;
    if(cnt_select <= M){
        dfs(cur_s+1);
    }
    selected_shop[cur_s] = false;
    cnt_select--;
    if(cnt_select <= M){
        dfs(cur_s+1);
    }
}

int main(){
    cin >> N >> M;

    // input 받기
    for(int i = 0; i< N; i++){
        for(int j = 0; j< N; j++){
            cin >> ar[i][j];
            if( ar[i][j] == 1){
                // 집 위치 저장 0:x, 1:y
                house[cnt_h][0] = i;
                house[cnt_h][1] = j;
                cnt_h++;
            }else if( ar[i][j] == 2){
                // 치킨가게 위치 저장 0:x, 1:y
                shop[cnt_s][0] = i;
                shop[cnt_s][1] = j;
                cnt_s++;
            }
        }
    }

    for(int i = 0; i< cnt_h; i++){
        for(int j = 0; j< cnt_s; j++){
            dis[j][i] = abs(house[i][0]-shop[j][0])+abs(house[i][1]-shop[j][1]);
            //cout << dis[j][i] << " ";
        }
        //cout << endl;
    }
    memset(selected_shop, false, sizeof(selected_shop));
    dfs(0);
    // 시간 초과가 나는 코드입니다 개선이 필요합니다.
    cout << result;

    return 0;
}