#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, -1 , 0};
vector<int> dy = {1, 0, 0 , -1};

typedef vector<vector<int>> matrix_t;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int N = maps.size();
    int M = maps[0].size();
    queue<pair<int, int>> q;
    matrix_t visited(N,vector<int>(M, 0));

    q.push({0,0});
    visited[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        if(x == N-1 && y == M-1){
            answer = visited[x][y];
            break;
        }

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 && xx<N && yy>=0 && yy<M)
                if(maps[xx][yy]==1 && visited[xx][yy]==0){
                    visited[xx][yy] = visited[x][y] + 1;
                    q.push({xx, yy});
                }
        }
        q.pop();
    }
    
    return answer;
}