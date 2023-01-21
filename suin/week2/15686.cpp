#include<iostream>
#include<cmath>
using namespace std;
int ar[51][51];
int dis[101][13];
int shop[13][2];
int house[101][2];

int N, M;
int cnt_h = 0;
int cnt_s = 0;
int selected_shop[13];

int f(int cur_h, int selected_s){
    //cout << cur_h <<" "<< selected_s;
    if(cur_h >= cnt_h){
        return 0;
    }
    int result = 1000010000;
    for(int i = 0; i<cnt_s; i++){
        int temp = 1000010000;
        if(selected_shop[i] == 1){
            temp = f(cur_h+1,selected_s) + dis[cur_h][i];
        }else{
            if(selected_s != M){
                selected_shop[i] = 1;
                temp = f(cur_h+1,selected_s+1) + dis[cur_h][i];
                selected_shop[i] = 0;
            }
        }
        if(temp < result){
            result = temp;
        }
    }
    return result;
}

int main(){
    cin >> N >> M;


    for(int i = 0; i< N; i++){
        for(int j = 0; j< N; j++){
            cin >> ar[i][j];
            if( ar[i][j] == 1){
                house[cnt_h][0] = i;
                house[cnt_h][1] = j;
                cnt_h++;
            }else if( ar[i][j] == 2){
                shop[cnt_s][0] = i;
                shop[cnt_s][1] = j;
                cnt_s++;
            }
        }
    }

    for(int i = 0; i< cnt_h; i++){
        for(int j = 0; j< cnt_s; j++){
            dis[i][j] = abs(house[i][0]-shop[j][0])+abs(house[i][1]-shop[j][1]);
        }
    }

    cout << f(0,0);

    return 0;
}