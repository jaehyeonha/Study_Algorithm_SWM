#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct point{
    //score : 1 = 이동할 수 있는 곳, 0 = 벽, 음수 = 점수(시작을 포함한 최소 이동 횟수) * -1
    int x;
    int y;
    int score;
};

int bfs(vector<vector<int>> & maps){
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<point> q;
    
    point a = {0,0,-1};
    q.push(a);
    
    maps[a.y][a.x] = a.score;
    
    while(!q.empty()){
        // 하나 꺼내서 탐색함.
        point a = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            // 주변 탐색
            point next = {a.x+dir[i][0], a.y+dir[i][1], a.score - 1};
            
            if( (0 <= next.x && next.x < maps[0].size()) && (0 <= next.y && next.y < maps.size()) ){
                if( next.x == maps[0].size()-1 && next.y == maps.size()-1){
                    // 끝에 도달함
                    return abs(next.score);
                }
                if( maps[next.y][next.x] == 1 ){
                    // 이동할 수 있는 곳일 경우
                    q.push(next);
                    maps[next.y][next.x] = next.score;
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return answer;
}