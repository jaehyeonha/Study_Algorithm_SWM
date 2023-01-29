#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int R, C;
vector < vector<int> > box;
queue < pair<int,int> > q;
int result=1;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

void bfs(){
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0; i< 4; i++){
            pair<int, int> next (cur.first + dir[i][0], cur.second + dir[i][1]);
            if(0 <= next.first && next.first < box.size() && 0 <= next.second && next.second < box[0].size() ){
                if(box[next.first][next.second] == 0){
                    q.push(next);
                    box[next.first][next.second] = box[cur.first][cur.second]+1;
                    if(box[next.first][next.second] > result){
                        result = box[next.first][next.second];
                    }
                }
            }
        }
    }
}
int main(){
    cin >> C >> R;

    for(int i = 0; i<R; i++){
        vector<int> a;
        box.push_back(a);
        //box.push_back({});
        for(int j = 0; j<C; j++){
            int temp;
            cin >> temp;
            box[i].push_back(temp);
            if(box[i][j] == 1){
                pair<int, int> a(i, j);
                q.push(a);
            }
        }
    }

    bfs();

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            //cout << box[i][j]<< " ";
            if(box[i][j]==0){
                cout << -1;
                return 0;
            }
        }
        //cout << endl;
    }
    cout << result-1;
    return 0;
}