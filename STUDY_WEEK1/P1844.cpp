#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int row = maps.size();
    int col = maps[0].size();
    int xdir[4] = {1, -1, 0, 0};
    int ydir[4] = {0, 0, 1, -1};
    vector<vector<int>> visited(row, vector<int> (col));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = x+xdir[i];
            int dy = y+ydir[i];
            if(dx>=row || dy>=col || dx < 0 || dy < 0)
                continue;
            if(maps[dx][dy] == 1){
                if(visited[dx][dy]==0){
                     q.push({dx, dy});
                     visited[dx][dy] = visited[x][y] + 1;
                }    
            }
        }
    }
    if(visited[row-1][col-1] == 0)
        answer = -1;
    else 
        answer = visited[row-1][col-1];
    return answer;
}