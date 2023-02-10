#include<iostream>
#include<deque>
using namespace std;

int N, M, x, y, K;
int ar[21][21];
int dir[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
deque<int> dice_sero(4); // dice_sero[1]는 항상 현재의 주사위의 하단을 가리킨다.
deque<int> dice_side(3);
int main(){
    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> ar[i][j];
        }
    }
    int nx, ny, go;
    for(int i=0; i<K; i++){
        cin >> go;
        nx = x + dir[go][0];
        ny = y + dir[go][1];
        if(0<=nx&&nx<N&&0<=ny&&ny<M){
            x = nx;
            y = ny;

            //dice 설정 해야합니다
            if(go==1){
                dice_sero[1] = dice_side[2];
                dice_side.push_back(dice_sero.back());
                dice_sero.pop_back();
                dice_sero.push_back(dice_side.front());
                dice_side.pop_front();
            }else if(go==2){
                dice_sero[1] = dice_side[0];
                dice_side.push_front(dice_sero.back());
                dice_sero.pop_back();
                dice_sero.push_back(dice_side.back());
                dice_side.pop_back();
            }else if(go==3){
                dice_side[1] = dice_sero[0];
                dice_sero.push_front(dice_sero.back());
                dice_sero.pop_back();
            }else{
                dice_side[1] = dice_sero[2];
                dice_sero.push_back(dice_sero.front());
                dice_sero.pop_front();
            }
            
            //dice의 숫자 바꾸기
            if(ar[x][y]){
                dice_sero[1] = dice_side[1] = ar[x][y];
                ar[x][y] = 0;
            }else{
                ar[x][y] =  dice_sero[1];
            }
            cout << dice_sero[3]<< endl;
            // for(int h=0; h<N; h++){
            //     for(int j=0; j<M; j++){
            //         cout <<  ar[h][j] << " ";
            //     }
            //     cout << endl;
            // }
            // for(int a=0; a<4; a++){
            //     for(int b=0; b<3; b++){
            //         if(b==1){
            //             cout << dice_sero[a];
            //             if(a==1){
            //                 cout << dice_side[a];
            //             }
            //             cout << " ";
            //         }else if(a==1){
            //             cout << dice_side[b] << " ";
            //         }else{
            //             cout << "  ";
            //         }
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }



    return 0;
}