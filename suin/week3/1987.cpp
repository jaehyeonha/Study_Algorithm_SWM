#include<iostream>
#include<stack>

using namespace std;

int R, C;
int ar[21][21];
int alpha[27];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int result = 0;

void dfs(int r, int c, int score){
    if(score > result){
        result = score;
    }
    for(int i=0; i<4; i++){
        int next_r = r+dir[i][0];
        int next_c = c+dir[i][1];
        if(0 <= next_r && next_r < R && 0 <= next_c && next_c < C){
            if(alpha[ar[next_r][next_c]]==0){
                // for(int i=0; i<27;i++){
                //     cout << alpha[i] << " ";
                // }
                // cout << ":"<<score<<endl;
                alpha[ar[next_r][next_c]]=1;
                dfs(next_r, next_c, score+1);
                alpha[ar[next_r][next_c]]=0;
            }

        }
    }
}
int main(){

    
    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char a;
            cin >> a;
            ar[i][j] = a - 'A' + 1;
        }
    }

    // for(int i=0; i<R; i++){
    //     for(int j=0; j<C; j++){
    //         cout << ar[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    alpha[ar[0][0]]=1;
    dfs(0,0,1);

    cout << result;
    
    return 0 ;
}