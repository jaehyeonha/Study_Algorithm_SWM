#include<vector>
#include<queue>
using namespace std;

int n,m;

int solution(vector<vector<int> > maps)
{
    //maps[n][m] = 1: 길, 0: 벽
    //BFS
    n = maps.size();
    m = maps[0].size();

    queue<pair<int,int>> q;
    q.push({0,0});
    int cnt = 1;
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == n-1 && y == m-1){
                return cnt;
            }
            if(x+1 < n && maps[x+1][y] == 1){
                q.push({x+1,y});
                maps[x+1][y] = 0;
            }
            if(x-1 >= 0 && maps[x-1][y] == 1){
                q.push({x-1,y}); 
                maps[x-1][y] = 0;
            }
            if(y+1 < m && maps[x][y+1] == 1){
                q.push({x,y+1});
                maps[x][y+1] = 0;
            }
            if(y-1 >= 0 && maps[x][y-1] == 1){
                q.push({x,y-1});
                maps[x][y-1] = 0;
            }
        }
        cnt++;
    }
    return -1;
}