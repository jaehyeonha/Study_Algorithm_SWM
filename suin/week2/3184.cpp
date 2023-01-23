#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

char ar[251][251];
int ch[251][251];
int cnt[250250][2];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int R, C;

void dfs(int x, int y, int color){ //row:x,col:y
    if( 0<=x && x<R && 0<=y && y<C){
        if(ch[x][y] == 0 && ar[x][y] != '#'){
            ch[x][y] = color;
            if(ar[x][y]=='o'){
                cnt[color][0]++;
            }else if(ar[x][y]=='v'){
                cnt[color][1]++;
            }
            for(int i = 0; i < 4; i++){
                int n_x = x+dir[i][0];
                int n_y = y+dir[i][1];
                dfs(n_x, n_y, color);
            }
        }
    }
}
int main(){

    int result[2] = {0,};
    cin >> R >> C;

    for(int i = 0; i<R; i++){
        for( int j = 0; j<C; j++){
            cin >> ar[i][j];
        }
    }

    int color_cnt = 1;
    for(int i = 0; i<R; i++){
        for( int j = 0; j<C; j++){
            dfs(i,j,color_cnt);
            if(cnt[color_cnt][0] > cnt[color_cnt][1]){
                result[0] += cnt[color_cnt][0];
            }else{
                result[1] += cnt[color_cnt][1];
            }
            color_cnt++;
        }
    }

    cout << result[0] <<" " <<result[1];


    return 0;
}